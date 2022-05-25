        2
       / \    
      3   5
     /


#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* left;
struct node* right;
};
// ------------------
struct node* createNode(int data)
{
    struct node *NODE;
    NODE=(struct node*)malloc(sizeof(struct node));
    NODE->data=data;
    NODE->right=NULL;
    NODE->left=NULL;
    return NODE;
}
// ----------------
// preorde-234675
// -------------------
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
// -----------------
// postorder-764352
// ----------------
void postOrder(struct node* root)
{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d",root->data);
    }
}
// -------------------------
//-inoreder-764325
// ------------------------
void inOrder(struct node* root)
{
    if(root!=NULL)
    {
        postOrder(root->left);
        printf("%d",root->data);
        postOrder(root->right);
    }
}

// ------------------
int main()
{
struct node *p,*p1,*p2,*p3,*p4,*p5;
p=createNode(2);
p1=createNode(3);
p2=createNode(4);
p3=createNode(5);
p4=createNode(6);
p5=createNode(7);
p->left=p1;

p->right=p3;
p1->left=p2;
p2->left=p4;
p4->right=p5;
preorder(p);
printf("\n");
postOrder(p);
printf("\n");
inOrder(p);
}
