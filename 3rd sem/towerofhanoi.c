#include<stdio.h>


void toh(int size,char source,char spare,char destination){
  if(size==1)
    printf("Move %d disk from %c to %c\n",size,source,destination);
  else{
    toh(size-1,source,destination,spare);
    printf("Move %d disk from %c to %c\n",size,source,destination);
    toh(size-1,spare,source,destination);
  }
}
void main(){
  int size;
  char source='A',destination='C',spare='B';
  printf("Enter the size of the tower\n");
  scanf("%d",&size);
  toh(size,source,spare,destination);
}
