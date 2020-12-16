/* ID 2015110899       - REPLACE WITH YOUR ID
 * NAME 이원규       - REPLACE WITH YOUR NAME */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MEASURE_TIME

#ifdef MEASURE_TIME
#include<time.h>
#endif

#define MAX_SIZE 500 // change if string is long


// function which return large nunmber
int max(int a,int b){

    if(a>b)
        return a;
    else
        return b;

}

//function for dynamic programming table
void printarr(int arr[][MAX_SIZE],int m,int n,char* s1,char* s2)
{
    printf("   ");

    for(int i=0;i<=n;i++)
    {
        printf("%c  ",s2[i]);
    }
    printf("\n");
    for(int j=0;j<=m;j++)
    {
        printf("%c  ",s1[j]);
        for(int k=0;k<=n;k++)
        {
            printf("%d  ",arr[j][k]);
        }
        printf("\n");
    }
    printf("/////////////////////////////////////////////\n");
}

int main(){

    char s1[MAX_SIZE];
    char s2[MAX_SIZE];
    int c[MAX_SIZE][MAX_SIZE];
    char s1plus[MAX_SIZE]=" ";//" " + s1
    char s2plus[MAX_SIZE]=" ";//" " + s2
    char LCS[MAX_SIZE];

    int m;
    int n;
    int LCSlength,num=0;

    #ifdef MEASURE_TIME
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    #endif

    printf("<strin> <string> 입력:   ");
    fscanf(stdin,"%s %s",s1,s2);

    m=strlen(s1);
    n=strlen(s2);

    strcat(s1plus,s1);
    strcat(s2plus,s2);


    // all zero for i=0 or j=0
    for(int i=0;i<=m;i++)
    {
        c[i][0]=0;
    }

    for(int j=0;j<=n;j++)
    {
        c[0][j]=0;
    }

    //Source : from professor PPT
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1plus[i]==s2plus[j])
                {
                c[i][j]=c[i-1][j-1]+1;
                }
            else{
                c[i][j]=max(c[i-1][j],c[i][j-1]);
                }

        }
    }

    LCSlength=c[m][n];
    int a=m;
    int b=n;
    // backtracking for LCS
    while(a!=0||b!=0){
        if(c[a][b]==c[a-1][b])
        {
            a--;
        }
        else if(c[a][b]==c[a][b-1])
        {
            b--;
        }
        else
        {
            LCS[LCSlength-num-1]=s1plus[a];
            num++;
            a--;
            b--;

        }
    }

    printf("\nLCS: %s\n\n",LCS);


    printarr(c,m,n,s1plus,s2plus);


    #ifdef MEASURE_TIME
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(stderr,">> Execution time: %.5f seconds\n",cpu_time_used);
    #endif








}



