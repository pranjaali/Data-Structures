#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE;
typedef NODE* PNODE;
typedef PNODE* PPNODE;

// -----------------------
struct node{
int data;
NODE *link;

};
// ------------------------
int insertNode(PPNODE head,int data)
{
    PNODE temp=NULL;
    temp=(PNODE)malloc(sizeof(NODE));
    temp->data=data;
    temp->link=NULL;

    if(*head==NULL)
    {
      *head=temp;
    }
    else{
        temp->link=*head;
        *head=temp;

    }


}
// ------------------------
int insertEND(PPNODE head,int thisdata)
{
    PNODE temp=NULL;
    PNODE new=*head;
    temp=(PNODE)malloc(sizeof(NODE));
    temp->data=thisdata;
    temp->link=NULL;

    if(*head==NULL)
    {
       *head=temp; 
    }
    else{
        while(new->link!=NULL)
        {
            new=new->link;
        }
        new->link=temp;


    }
}

// ------------------------
void Display(PNODE head)
{
    while(head!=NULL)
    {

       printf("%d\t",head->data);
       head=head->link;
    }
}


// -------------------------
int main()
{
   PNODE newNode=NULL;
   insertNode(&newNode,79);
   insertEND(&newNode,6);
   
   insertNode(&newNode,7);
   Display(newNode);

    return 0;
}
