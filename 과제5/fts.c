/* ID 2015110899       - REPLACE WITH YOUR ID
 * NAME ÀÌ¿ø±Ô       - REPLACE WITH YOUR NAME */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MEASURE_TIME
#define MIN(a,b)(a<b?a:b)
#define MAX(a,b)(a>b?a:b)

#ifdef MEASURE_TIME
#include<time.h>
#endif
typedef struct city{

    int x;
    int y;

}city;


typedef struct result{

    float length;
    city rstcity;

}result;
// find length between two city
float findlength2(city a,city b)
{

    return sqrt(pow((a.x-b.x),2)+pow((a.y-b.y),2));

}
//find pluslength when city add( between two city line)
float findlength(city a,city b,city c){

    float length;

    length=findlength2(a,c)+findlength2(c,b)-findlength2(a,b);

    return length;
}
//find minimum city from citys by doing function findlength()
result findmincity(city a,city b,city* arr)
{
    result r;
    float minL=10000;
    float length;
    city c;
    c.x=0;
    c.y=0;


    for(int i=0;i<100;i++)
    {

        length=findlength(a,b,arr[i]);

        if(minL>length)
        {
            minL=length;
            c.x=arr[i].x;
            c.y=arr[i].y;
        }


    }

    r.length=minL;
    r.rstcity=c;


    return r;

}
//insert new city between the old ciry
void shift(int num,int* shortnum,city*shortestcity,city c)
{

    for(int i=(*(shortnum))-1;i>=num+1;i--)
    {
        shortestcity[i+1]=shortestcity[i];
    }

    shortestcity[num+1]=c;


}
//fill the shortestcity arry
void makepath(float fuel,float* currentfuel,int* shortnum,city* shortestcity,city* arr)
{
    result r;
    city c;
    result min;
    min.length=100000;
    int num;
    float plusfuel;

    while(1){
    //find minimum plusfuel and city;
    for(int i=0;i<(*(shortnum))-1;i++)
    {
        r=findmincity(shortestcity[i],shortestcity[i+1],arr);

        if(min.length>r.length)
        {
            min=r;
            num=i;
        }
    }

    min.length=100000;

    plusfuel=findlength2(shortestcity[num],min.rstcity)+findlength2(min.rstcity,shortestcity[num+1])-findlength2(shortestcity[num],shortestcity[num+1]);
    //check because of fuel limitation
    if(fuel<(*(currentfuel))+plusfuel)
    {
        break;
    }
    else
    {
        shift(num,shortnum,shortestcity,min.rstcity);
        *shortnum=(*shortnum)+1;
        *currentfuel=(*(currentfuel))+plusfuel;

        for(int i=0;i<100;i++)
        {
            if(min.rstcity.x==arr[i].x&&min.rstcity.y==arr[i].y)
            {
                arr[i].x=10000;
            }

        }
    }
    if(*shortnum>=100)
        break;
    }




}








int main(){

    int scale;
    int arr[101][101];
    int x;
    int y;
    city citys[100];
    city shortestcity[100];
    float currentfuel=100*sqrt(2);
    int shortnum=2;
    float fuel;


    fscanf(stdin,"%d",&scale);
    for(int i=0;i<scale;i++){
        fscanf(stdin,"%d %d",&x,&y);
        citys[i].x=x;
        citys[i].y=y;
        arr[x][y]++;
    }


    shortestcity[0]=citys[0];
    shortestcity[1]=citys[99];
    citys[0].x=10000;
    citys[99].x=10000;



    fuel=300;
    makepath(fuel,&currentfuel,&shortnum,shortestcity,citys);

    printf("\n300 %f \n",currentfuel);
    for(int j=0;j<shortnum;j++){
        printf("%d %d ",shortestcity[j].x,shortestcity[j].y);
    }
    printf("\n");


    fuel=700;
    makepath(fuel,&currentfuel,&shortnum,shortestcity,citys);

    printf("\n700 %f \n",currentfuel);
    for(int j=0;j<shortnum;j++){
        printf("%d %d ",shortestcity[j].x,shortestcity[j].y);
    }
    printf("\n");


    fuel=1100;
    makepath(fuel,&currentfuel,&shortnum,shortestcity,citys);

    printf("\n1100 %f \n",currentfuel);
    for(int j=0;j<shortnum;j++){
        printf("%d %d ",shortestcity[j].x,shortestcity[j].y);
    }
    printf("\n");

    fuel=1500;
    makepath(fuel,&currentfuel,&shortnum,shortestcity,citys);

    printf("\n1500 %f \n",currentfuel);
    for(int j=0;j<shortnum;j++){
        printf("%d %d ",shortestcity[j].x,shortestcity[j].y);
    }
    printf("\n");



}

