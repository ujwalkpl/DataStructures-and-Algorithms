#include<stdio.h>

int gcd(int a,int b){
  while(a!=b){
if(a>b){
  return gcd(a-b,b);
}
else
  return gcd(a,b-a);
}return a;
}
void main(){
  int num1,num2,value;
  printf("Enter the numbers");
  scanf("%d",&num1);
  scanf("%d",&num2);

  if(num1==0){
    printf("1gcd of %d and %d is %d",num1,num2,num2);
    }
    else if(num2==0){
      printf("2gcd of %d and %d is %d",num1,num2,num1);
    }
    else if(num1==0&&num2==0){
      printf("3gcd is not defined");
    }else{
      value=gcd(num1,num2);
      printf("4gcd of %d and %d is %d",num1,num2,value);
    }
}
