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



int main()
{
    NODE *ptr;
    NODE *p,*q;
    int number;
    scanf("%d",&number);
    ptr=maketree(number);
    while(scanf("%d",&number)!=EOF)
    {
        p=q=ptr;
        while(number!=p->data&&q!=NULL)
        {
            p=q;
            if(number<p->data)
            {
                q=p->left;

            }
            else
                q=p->left;


        }
        if(number==p->data)
            printf("duplicate %d",number);
        else if(number<p->data)
            setleft(p,number);
        else
            setright(p,number);
    }

    return 0;
}
