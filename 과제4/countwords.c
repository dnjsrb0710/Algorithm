/* ID 2015110899       - REPLACE WITH YOUR ID
 * NAME ÀÌ¿ø±Ô       - REPLACE WITH YOUR NAME */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MEASURE_TIME

#ifdef MEASURE_TIME
#include<time.h>
#endif

typedef struct Word{

    int count;
    char word[25];

}Word;

//Source for Quick Sort : https://www.geeksforgeeks.org/quick-sort/
int partition(Word*A,int low,int high)
{

    int pivot=(A+high)->count;
    int i=low-1;
    Word tmp;

    for(int j=low;j<=high;j++){

        if((A+j)->count>pivot){

            i++;
            tmp=*(A+i);
            *(A+i)=*(A+j);
            *(A+j)=tmp;
        }
    }
    tmp=*(A+i+1);
    *(A+i+1)=*(A+high);
    *(A+high)=tmp;

    return i+1;




}


void WordSort(Word*A,int low,int high)
{
    int pi;
    if(low<high)
    {
        pi=partition(A,low,high);
        WordSort(A,low,pi-1);
        WordSort(A,pi+1,high);

    }

}

// Make word arry and sort arry , return pointer
Word* MakeWordArr(FILE* fp,int* ocnt)
{
    Word* A;
    int cnt=0;
    int total=0;
    char wd[25];

    while(!feof(fp)){
        fscanf(fp,"%s",wd);
        total++;
    }

    A=(Word*)malloc(sizeof(Word)*total);

    fseek(fp,0,SEEK_SET);

    //input first word
    fscanf(fp,"%s",wd);
    cnt=1;
    strcpy(A->word,wd);
    A->count=1;

    while(EOF!=fscanf(fp,"%s",wd)){

        //count++ if the word is already entered
        for(int i=0;i<cnt;i++){

            if(strcmp((A+i)->word,wd)==0){
                ((A+i)->count)++;
                goto site;
               }

            }
            // if new word enter, cnt++ and make new struct Word
            cnt++;
            strcpy((A+cnt-1)->word,wd);
            (A+cnt-1)->count=1;



        site:
            cnt=cnt;

    }

    *ocnt=cnt;
    WordSort(A,0,cnt-1);

    return A;

}






int main()
{
    FILE* fp;
    Word* A;
    int *ocnt=(int*)malloc(sizeof(int));


    #ifdef MEASURE_TIME
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    #endif
    ///////////////////////////////////////
    //INPUT4A                       ///////
    ///////////////////////////////////////
    fp=fopen("input4a.txt","r");

    if(fp==NULL){
        printf("FILE open ERROR!!!");
        exit(1);
    }

    A=MakeWordArr(fp,ocnt);

    fp=fopen("ouput4a.txt","w");

    for(int k=0;k<(*ocnt);k++ ){
        fprintf(fp,"%s %d\n",(A+k)->word,(A+k)->count);
    }

    free(A);


    ///////////////////////////////////////
    //INPUT4B                       ///////
    ///////////////////////////////////////


    fp=fopen("input4b.txt","r");

    if(fp==NULL){
        printf("FILE open ERROR!!!");
        exit(1);
    }

    A=MakeWordArr(fp,ocnt);

    fp=fopen("ouput4b.txt","w");

    for(int k=0;k<(*ocnt);k++ ){
        fprintf(fp,"%s %d\n",(A+k)->word,(A+k)->count);
    }

    free(A);




    ///////////////////////////////////////
    //INPUT4C                       ///////
    ///////////////////////////////////////


    fp=fopen("input4c.txt","r");

    if(fp==NULL){
        printf("FILE open ERROR!!!");
        exit(1);
    }

    A=MakeWordArr(fp,ocnt);

    fp=fopen("ouput4c.txt","w");

    for(int k=0;k<(*ocnt);k++ ){
        fprintf(fp,"%s %d\n",(A+k)->word,(A+k)->count);
    }


    #ifdef MEASURE_TIME
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    fprintf(stderr,">> Execution time: %.5f seconds\n",cpu_time_used);
    #endif

    free(A);
    fclose(fp);
}
















