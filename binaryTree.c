# Data-Structures
Data structure implementation using-c,c++,java
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
// -----------------------------

struct node* fun()
{
    int data;
    struct node *newn=(struct node*)malloc(sizeof(struct node));
    newn->right=NULL;
    newn->left=NULL;
    printf("enter the data \n enter -1 if has no child\n");
    scanf("%d",&data);
    if(data==-1)
    {
        return 0;
    }
    newn->data=data;
    printf("ENTER THE LEFT CHILD of %d",data);
    newn->left=fun();
    printf("ENTER THE RIGHT CHILD OF %d ",data);
    newn->right=fun();
    //  printf("| %d|",newn->data);
    return newn;

}

void preorder(struct node *root)
{
    if(root==NULL)
    {
        return;

    }
    printf("%d-",root->data);
    preorder(root->left);
    preorder(root->right);
}
// -------------------------------
int main()
{
    struct node *root;
    root=fun();
    // printf("{%d",root);
    preorder(root);
   
}
