/* ID 2015110899       - REPLACE WITH YOUR ID
 * NAME ÀÌ¿ø±Ô       - REPLACE WITH YOUR NAME */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MEASURE_TIME
#define MIN(a,b)(a<b?a:b)
#define MAX(a,b)(a>b?a:b)

#ifdef MEASURE_TIME
#include<time.h>
#endif

#define MAX_SIZE 500 // change if string is long


void makeminarr(int platenum,int **slitarr,int **minimumlength)
{
    int left,leftvalue;
    int right,rightvalue;
    int tmp;




    for(int i=platenum-2;i>=0;i--){

        for(int j=1;j<=slitarr[i][0];j++){

            left=0;
            right=0;
            leftvalue=99999;
            rightvalue=99999;

            //find left slit and right slit
            for(int k=1;k<=slitarr[i+1][0];k++){

                tmp=slitarr[i][j]-slitarr[i+1][k];
                if(tmp==0)
                {
                    minimumlength[i][j]=minimumlength[i+1][k];
                    goto this;
                }
                else if(tmp>0)
                {
                    if(leftvalue>tmp)
                    {
                        left=k;
                        leftvalue=tmp;
                    }
                }
                else
                {
                    if(rightvalue>abs(tmp))
                    {
                        right=k;
                        rightvalue=abs(tmp);
                    }
                }

            }
            //insert the value
            minimumlength[i][j]=MIN(leftvalue+minimumlength[i+1][left],rightvalue+minimumlength[i+1][right]);

            this:
                tmp=tmp;
        }

    }

    }


int findmin(int**slitarr,int **minimumlength,int platewidth)
{
    int center=(platewidth/2);
    int left=0;
    int right=0;
    int leftvalue=99999;
    int rightvalue=99999;
    int minimum,tmp;

    for(int k=1;k<=slitarr[0][0];k++){

                 //find left slit and right slit
                tmp=center-slitarr[0][k];
                if(tmp==0)
                {
                    minimum=minimumlength[0][k];
                    goto this2;
                }
                else if(tmp>0)
                {
                    if(leftvalue>tmp)
                    {
                        left=k;
                        leftvalue=tmp;
                    }
                }
                else
                {
                    if(rightvalue>abs(tmp))
                    {
                        right=k;
                        rightvalue=abs(tmp);
                    }
                }

            }
            minimum=MIN(leftvalue+minimumlength[0][left],rightvalue+minimumlength[0][right]);
            this2:
                return minimum;



}

void findroute(int**slitarr,int **minimumlength,int platenum,int platewidth){
    int main=(platewidth/2);
    int left=0;
    int right=0;
    int leftvalue=99999;
    int rightvalue=99999;
    int tmp;

    for(int i=0;i<platenum;i++){

        left=0;
        right=0;
        leftvalue=99999;
        rightvalue=99999;
         //find left slit and right slit
        for(int k=1;k<=slitarr[i][0];k++){

                    tmp=main-slitarr[i][k];
                    if(tmp==0)
                    {
                        main=slitarr[i][k];
                        printf("%d ",slitarr[i][k]);
                        goto this3;
                    }
                    else if(tmp>0)
                    {
                        if(leftvalue>tmp)
                        {
                            left=k;
                            leftvalue=tmp;
                        }
                    }
                    else
                    {
                        if(rightvalue>abs(tmp))
                        {
                            right=k;
                            rightvalue=abs(tmp);
                        }
                    }

                }
                //print part of shortest path
                if(leftvalue+minimumlength[i][left]<rightvalue+minimumlength[i][right])
                    printf("%d ",slitarr[i][left]);
                else
                    printf("%d ",slitarr[i][right]);

                this3:
                    tmp=tmp;
    }

}




int main()
{

    int input;
    int platenum;
    int platewidth;
    int **slitarr;
    int **minimumlength;


    fscanf(stdin,"%d %d %d",&platenum,&platewidth,&input);

    if(input==-1)
    {
        slitarr=malloc(sizeof(int*)*platenum);
        for(int i=0;i<platenum;i++)
        {
            slitarr[i]=malloc(sizeof(int*)*(platewidth+1));
        }

        minimumlength=malloc(sizeof(int*)*platenum);
        for(int i=0;i<platenum;i++)
        {
            minimumlength[i]=malloc(sizeof(int*)*(platewidth+1));
        }
    }

    int num=0; // plate num

    for(int i=0;i<platenum;i++){

        fscanf(stdin,"%d",&slitarr[num][0]);

        for(int j=1;j<=slitarr[num][0];j++)
        {
            fscanf(stdin,"%d",&slitarr[num][j]);
        }
        fscanf(stdin,"%d",&input);
        if(input==-2){
            num++;
        }
    }
    fscanf(stdin,"%d",&input);

    if(input!=-3)
    {
        printf("input error!!!");
        exit(1);
    }

    #ifdef MEASURE_TIME
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    #endif


    for(int j=0;j<=platewidth;j++){
        minimumlength[platenum-1][j]=0;
    }

    makeminarr(platenum,slitarr,minimumlength);

    printf("%d ",findmin(slitarr,minimumlength,platewidth));

    findroute(slitarr,minimumlength,platenum,platewidth);


     #ifdef MEASURE_TIME
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(stderr,">> Execution time: %.5f seconds\n",cpu_time_used);
    #endif



}

