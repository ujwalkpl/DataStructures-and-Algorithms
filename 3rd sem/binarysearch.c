#include<stdio.h>
int n,i=0,a[20],key,first,last,mid;
void binarysearch(int key,int first,int last){
  if(first>last){
    printf("Element not found");
  }
  else{
    mid=(first+last)/2;
    if(key==a[mid]){
      printf("Element found at index %d",mid);

    }
    else if(key>a[mid]){
      binarysearch(key,mid+1,last);
    }
    else
      binarysearch(key,first,mid-1);
    }
  }
void main(){

  printf("Enter the number of elements");
  scanf("%d",&n);
  printf("Enter the elements");
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  printf("Enter the element to search for");
  scanf("%d",&key);
  first=0;
  last=n-1;

  binarysearch(key,first,last);

}
