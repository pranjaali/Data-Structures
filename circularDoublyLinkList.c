#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
// struct node *firstPtr=NULL;
struct node *lastPtr=NULL;
// ===============INSERTION OF NODE=================
// --------------insert at first--------------------
void insertBegin(struct Node** start, int value)
{
    struct Node *last = (*start)->prev;
 
     struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;   
    new_node->next = *start;
    new_node->prev = last;
 
   
    last->next = (*start)->prev = new_node;
 
    *start = new_node;
}
// --------------insert at last---------------------
void insertEnd(struct Node** start, int value)
{
    if (*start == NULL)
    {
         struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }
     struct Node *last = (*start)->prev;
 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
 
    new_node->next = *start;
 
    (*start)->prev = new_node;
 
    new_node->prev = last;
 
    last->next = new_node;
}
// --------------insert at possition----------------
void insertAfter(struct Node** start, int value1, int value2)
{
     struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value1;  
    struct Node *temp = *start;
    while (temp->data != value2)
        temp = temp->next;
    struct Node *next = temp->next;

    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = next;
    next->prev = new_node;
}
 
// ===============DELETION OF NODES=================
// ---------------DELETE FIRST NODE-----------------
// ---------------DELETE LAST NODE------------------
// ---------------DELETE THE NODE AT POSSITION------
// ===============COUNT THE NUMBER OF NODES=========
// ===============DISPLAY THE LINKLIST=============
void display(struct Node* start)
{
    struct Node *temp = start;
 
    printf("\nTraversal in forward direction \n");
    while (temp->next != start)
    {
        printf("[%d]-> ", temp->data);
        temp = temp->next;
    }
    printf("[%d]-> ", temp->data);
 
    printf("\nTraversal in reverse direction \n");
    struct Node *last = start->prev;
    temp = last;
    while (temp->prev != last)
    {
        printf("[%d]-> ", temp->data);
        temp = temp->prev;
    }
    printf("[%d]-> ", temp->data);
}
// ===============MAIN FUNCTION====================
int main()
{
    struct Node *first=NULL;
    insertEnd(&first, 1);
     insertEnd(&first, 2);
     insertAfter(&first, 99, 2);
      insertEnd(&first, 3);
      insertBegin(&first,100);
    display(first);
    return 0;
}
