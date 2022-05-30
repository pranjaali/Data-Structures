#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
// ===========================INSERT NODES===================================
void insertatFirst(struct node **head, int data)
{
    struct node *newn = (struct node *)malloc(sizeof(struct node));
    struct node *temp = (*head);
    newn->data = data;
    newn->next = NULL;
    newn->prev = NULL;
    if (temp == NULL)
    {
        (*head) = temp = newn;
    }
    else
    {

        newn->next = temp;
        temp->prev = newn;
        newn->prev = NULL;
        (*head) = newn;
    }
}
// -----------------------------
void insertAtEnd(struct node **head, int data)
{
    struct node *temp = (*head);
    struct node *newn = (struct node *)malloc(sizeof(struct node));
    newn->data = data;
    newn->next = NULL;
    if ((*head) == NULL)
    {
        (*head) = newn;
    }
    else
    {
        struct node *ptr = NULL;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
        newn->next = NULL;
    }
}
// -------------------------
void insertAtPosition(struct node **head, int data, int possition)
{
    struct node *temp = (*head);
    struct node *ptr=NULL;
    struct node *newn = (struct node *)malloc(sizeof(struct node));
    newn->data = data;
    newn->prev = NULL;
    newn->next = NULL;
    if (possition == 1)
    {
        // if (temp == NULL)
        // {
        //     (*head) = temp = newn;
        // }
        // else
        // {
        //     newn->next = temp;
        //     temp->prev = newn;
        //     newn->prev = NULL;
        //     (*head) = newn;
        // }
        insertatFirst(&(*head),data);
    }
    else if(possition>1)
    {
        for(int i=1;i<possition;i++)
        {   ptr=temp;
            temp=temp->next;
        }
        // printf("%d",temp->data);
        newn->next=temp;
        newn->prev=ptr;
        ptr->next=newn;
        // free(temp);

    }
}
// ============================DELETE NODES==========================
void deleteFirst(struct node **head)
{
    struct node *temp=(*head);
    struct node *ptr=temp;
    temp->prev=NULL;
    (*head)=temp=ptr->next;
    free(ptr);
}
// -----------------------------------------
void deleteLast(struct node **head)
{
    struct node *temp=(*head);
    struct node *ptr=NULL;
    while(temp->next!=NULL)
    {
        ptr=temp;
        temp=temp->next;
    }
    ptr->next=NULL;
    free(temp);
}
// -----------------------------------------
void deleteAtPossition(struct node **head,int possition)
{
    struct node *temp=(*head);
    struct node *ptr=NULL;
    struct node *ptr2=NULL;

    if(possition==1)
    {    
        (*head)=temp=temp->next;
         temp->prev=NULL;
        // deleteFirst(&(*head));
    }
    else{
       for(int i=1;i<possition;++i)
    {
        ptr=temp;
        temp=temp->next;
        ptr2=temp->next;
    }
    ptr->next=ptr2;
    ptr2->prev=ptr;
    free(temp);

    }
    

}

void display(struct node **head)
{
    struct node *temp = (*head);

    while (temp != NULL)
    {
        printf("[%d]->", temp->data);
        temp = temp->next;
    }
}

// =========================-
int main()
{
    struct node *first = NULL;
    insertatFirst(&first, 10);
    insertAtEnd(&first, 40);
    insertatFirst(&first, 20);
    insertAtEnd(&first, 30);
    insertAtEnd(&first, 40);
    insertAtPosition(&first, 88, 6);
    deleteFirst(&first);
    deleteLast(&first);
    deleteAtPossition(&first,1);
    display(&first);
    // count(&first);
    return 0;
}
