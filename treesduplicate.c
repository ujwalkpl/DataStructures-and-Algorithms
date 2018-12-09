#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;
NODE *maketree(int x)
{
    NODE *p;
    p=(NODE *)malloc(sizeof(NODE));
    if(p==NULL)
    {
        printf("memory not available");

    }
    else
    {
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
    }

}
void setleft(NODE *p,int x)
{
    if(p==NULL)
        printf("void insertion");
    else if(p->left!=NULL)
        printf("invalid insertion");
    else
        p->left=maketree(x);


}
void setright(NODE *p,int x)
{
    if(p==NULL)
        printf("void insertion");
    else if(p->right!=NULL)
        printf("invalid insertion");
    else
        p->right=maketree(x);

}

NODE *treeCreation(NODE *ptr)
{
  int number;
  printf("Enter the numbers to be inserted\n");

  NODE *p,*q;
  scanf("%d",&number);

  ptr=maketree(number);
  while(scanf("%d",&number)!=EOF)
  {
    if(number==-1){
      break;
    }
        p=q=ptr;
      while(number!=p->data&&q!=NULL)
      {
          p=q;
          if(number<p->data)
          {
              q=p->left;

          }
          else
              q=p->right;
      }



      if(number==p->data)
          printf("duplicate %d",number);
      else if(number<p->data)
          setleft(p,number);
      else
          setright(p,number);
  }
  return ptr;
}

void pretrav(NODE *ptr) {
  if(ptr!=NULL){
    printf("%d\n",ptr->data );
    pretrav(ptr->left);
    pretrav(ptr->right);
  }
}

void posttrav(NODE *ptr){
  if(ptr!=NULL){
    posttrav(ptr->left);
    printf("%d",ptr->data);
    posttrav(ptr->right);
  }
}

int main()
{
    NODE *ptr;


    int choice;
    do{
      printf("Enter the choice \n1.Tree Creation\n2.Pre Traversal \n  3.Post Traversal\n4.inTraversal\n");

    scanf("%d",&choice );
    switch (choice) {
      case 1:
        ptr=treeCreation(ptr);
        break;
      case 2:
        pretrav(ptr);
        break;
    }
  }while(choice!=4);


    return 0;
}
