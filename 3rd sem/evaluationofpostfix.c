#include<stdio.h>
#include<ctype.h>
#include<math.h>

#define SIZE 50

int i=0,top=-1;
float stack[SIZE];
char postfix[SIZE];

float pop(){
  if(top==-1){
    printf("stack underflow cannot delete");
  }else{
    return(stack[top--]);
  }
}

void push(float item){
  if(top==SIZE-1)
    printf("stack overflow cannot insert");
  else
    stack[++top]=item;
}

void main(){

  float op1,op2,item;
  printf("Enter the postfix expression\n");
  gets(postfix);
  while(postfix[i]!='\0'){
    item=(float)(postfix[i]-'0');
    if(isdigit(postfix[i])){
      push(item);
    }
    else{
      op2=pop();
      op1=pop();
      switch (postfix[i]) {
        case '+':
        push(op1+op2);

        break;
        case '-':
        push(op1-op2);
        break;
        case '*':
        push(op1*op2);
        break;
        case '/':
        push(op1/op2);
        break;
        case '^':
        push(pow(op1,op2));
        break;
      }
    }
    i++;
  }
  printf("%f",stack[top]);
}
