#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#define MAX 500

int table[128];


void shifttable(char pattern[]){
    int i,j,m;
     m=strlen(pattern);
     
    for(i=0;i<MAX;i++){
        table[i]=m;
    }
    for(j=0;j<m-1;j++){
        table[pattern[j]]=m-i-1;
 
    }
     
}
int horspool(char pattern[],char text[]){
    int m,len;
    
     len=strlen(text);
     m=strlen(pattern);
      shifttable(pattern);
    
    int i,k;
     i=m-1;
     
     puts(text);
     puts(pattern);
    while(i<len){
       
        k=0;
        while(k<m && pattern[m-1-k]==text[i-k])
        {
            printf("hi");
              k++;
        }
      

        printf("%d ",k);
        if(k==m)
        return i-m+1;
        else
        {
            i=i+table[text[i]];
        }
     
        
    }
       return -1;
}
void main(){
    char text[100];
char pattern[100];
     printf("enter text : \n");
        scanf("%s",text);
        printf("enter pattern : \n");
        scanf("%s",pattern);
    
  
    int pos=horspool(pattern,text);
    printf("%d ",pos);
}