#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main(){
    clock_t start,end;
    double timetaken;
    int num,i,j,min,temp;
    int a[100000];
    printf("Enter the number of inputs");
    scanf("%d",&num);
    for(i=0;i<num;i++){
        a[i]=rand();
    }
    
 for(i=0;i<num;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
     printf("\n");
      printf("\n");
        start=clock();
    for(i=0;i<num;i++){
          min=i;
        for(j=i+1;j<num;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    end=clock();
    timetaken=(double)(end-start)/CLOCKS_PER_SEC;
    for(i=0;i<num;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("%f",timetaken);
    
}