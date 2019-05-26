#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main(){
    int num,i,j,temp,a[100000];
    clock_t start,end;
    double timetaken;
    printf("Enter the number of inputs");
    scanf("%d",&num);
    for(i=0;i<num;i++)
        a[i]=rand();
    printf("\n\n\n");

    for(i=0;i<num;i++)
        printf("%d ",a[i]);
    start=clock();
    for(i=0;i<num-1;i++)
        for(j=1;j<num-i-1;j++)
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
    end=clock();
    printf("The sorted output\n");
    for(i=0;i<num;i++)
        printf("%d ",a[i]);
        
    timetaken=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\ntime taken is %f",timetaken);
}