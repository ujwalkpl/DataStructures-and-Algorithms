#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *leftchild;
  struct node *rightchild;
};
typedef struct node NODE;
NODE *newnode,*root=NULL;
NODE *getnode(int value){
  newnode=(NODE *)malloc(sizeof(NODE));
  newnode->data=value;
  newnode->leftchild=NULL;
  newnode->rightchild=NULL;
}
NODE *createnode(NODE *root,int value){
  if(root==NULL){
    return(getnode(value));

  }
  else if(value>root->data){
  root->rightchild=createnode(root->rightchild,value);
}
  else if(value<root->data){
    root->leftchild=createnode(root->leftchild,value);

  }

  return root;
}
void preorder(NODE *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->leftchild);
        preorder(root->rightchild);
    }
}

void inorder(NODE *root)
{
    if (root != NULL)
    {
        inorder(root->leftchild);
        printf("%d ", root->data);
        inorder(root->rightchild);
    }
}

void postorder(NODE *root)
{
    if (root != NULL)
    {
        postorder(root->leftchild);
        postorder(root->rightchild);
        printf("%d ", root->data);
    }
}
void main(){
  int value,choice;

  printf("1.Insert\n2.preOrder\n3.postOrder\n4.inOrder");
  do {
    printf("Enter choice\n");
    scanf("%d",&choice);
    switch (choice) {
      case 1:
        printf("Enter the element to be inserted\n");
        scanf("%d",&value);
      root=  createnode(root,value);
        break;
      case 2:
          preorder(root);
          break;
      case 3:
          postorder(root);
          break;
        case 4:
          inorder(root);
          break;

    }
  } while(choice!=5);
}
