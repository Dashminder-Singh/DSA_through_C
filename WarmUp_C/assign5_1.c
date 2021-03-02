/*define structure Temp to store information about, min & max temperature of a days;
define a function max_avg(struct Temp d[], int totalDays) to calculate maximum average of temperature
another function is min_avg(struct Temp d[ ],int totalDays) to calculate minimum average of temperature
*/
#include<conio.h>
#include<stdio.h>
struct Temp
{
    int max,min;
    int day;
};
struct Temp input_temp(){
    struct Temp t;
    printf("Enter day, max temperature and min temperature\n");
    scanf("%d",&t.day);
    scanf("%d%d",&t.max,&t.min);
    return(t);
}
void show_temp(struct Temp t[ ], int totalDays){
    for(int i=0;i<totalDays;++i)
        printf("\n%d %d %d",t[i].day,t[i].max,t[i].min);
}

int max_avg(struct Temp d[ ], int totalDays){
    int _s=0;
    for(int i=0;i<totalDays;++i)
        _s+=d[i].max;
    return(_s/totalDays);
}

int min_avg(struct Temp d[ ],int totalDays){
    int _s=0;
    for(int i=0;i<totalDays;++i)
        _s+=d[i].min;
    return(_s/totalDays);
}
void main()
{
    struct Temp t[3];
    int nOfDays;
    printf("Enter number of days\n");
    scanf("%d",&nOfDays);
    for(int i=0; i<nOfDays; ++i)
        t[i]=input_temp();
    //show_temp(t,nOfDays);
    printf("\nAverage of minimum temperature of %d days is %d",nOfDays,min_avg(t,3));
    printf("\nAverage of maximum temperature of %d days is %d",nOfDays,max_avg(t,3));
    getch();
}

