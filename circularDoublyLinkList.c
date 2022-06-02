#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
// struct node *firstPtr=NULL;
struct node *lastPtr = NULL;
// ===============COUNT NO OF NODES=================
int count(struct Node **head)
{
    int count = 0;
    struct Node *temp = (*head);
    if ((*head) == NULL)
    {
        count = 0;
    }
    else
    {
        count = 1;
        while (temp->next != (*head))
        {
            temp = temp->next;
            count++;
        }
    }

    return count;
}
// ===============INSERTION OF NODE=================
// --------------insert at first--------------------
void insertBegin(struct Node **start, int value)
{
    struct Node *last = (*start)->prev;

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = *start;
    new_node->prev = last;

    last->next = (*start)->prev = new_node;

    *start = new_node;
}
// --------------insert at last---------------------
void insertEnd(struct Node **start, int value)
{
    if (*start == NULL)
    {
        struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }
    struct Node *last = (*start)->prev;

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;

    new_node->next = *start;

    (*start)->prev = new_node;

    new_node->prev = last;

    last->next = new_node;
}
// --------------insert at possition----------------
void insertAfter(struct Node **start, int value1, int value2)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
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
void deleteFromFirst(struct Node **head)
{
    struct Node *temp = (*head);
    struct Node *last = temp;
    if ((*head) == NULL)
    {
        printf("\nLinklist is empty:\n");
    }
    else if ((*head)->next == (*head))
    {
        (*head) = temp = NULL;
        free(temp);
    }
    else
    {

        last = (*head)->prev;
        (*head) = (*head)->next;
        last->next = (*head);
        (*head)->prev = last;
        free(temp);
    }
}
// ---------------DELETE LAST NODE------------------
void deleteFromLast(struct Node **head)
{
    struct Node *temp = NULL;
    struct Node *last = NULL;
    if ((*head) == NULL)
    {
        printf("\nLink list is empty:\n");
    }
    else if ((*head)->next == (*head))
    {
        (*head) = temp = NULL;
        free(temp);
    }
    else
    {
        last = (*head)->prev;
        temp = last;
        last = last->prev;
        last->next = (*head);
        (*head)->prev = last;

        free(temp);
    }
}
// ---------------DELETE THE NODE AT POSSITION------
void deleteFromPossition(struct Node **head, int possition)
{
    struct Node *temp = (*head);
    struct Node *ptrPrev = NULL;
    struct Node *ptrNext = NULL;

    if (possition < 1 || possition > count(&(*head)))
    {
        printf("\nenvalid possition\n");
    }
    else if (possition > 1 && possition < count(&(*head)))
    {
        if ((*head) == NULL)
        {
            printf("\nLinkList is empty,Deletion of node unsuccesful\n");
        }
        else if (possition == 1)
        {
            deleteFromFirst(&(*head));
        }
        else
        {
            for (int i = 1; i < possition; i++)
            {
                temp = temp->next;
            }
            // printf("\n(%d)",temp->data);
            ptrPrev = temp->prev;
            ptrNext = temp->next;
            ptrPrev->next = ptrNext;
            ptrNext->prev = ptrPrev;
            free(temp);
        }
    }
    // else{
    //     printf("\nPLEASE ENTER VALID NODE NUMBER:\n");
    // }
}

// ===============DISPLAY THE LINKLIST=============
void display(struct Node *start)
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
    struct Node *first = NULL;
    insertEnd(&first, 1);
    deleteFromPossition(&first, 2);
    deleteFromFirst(&first);
    insertEnd(&first, 2);
    deleteFromPossition(&first, 2);
    insertAfter(&first, 99, 2);
    // deleteFromLast(&first);
    insertEnd(&first, 3);
    insertBegin(&first, 100);

    display(first);
    int cnt = count(&first);
    printf("\nNO OF NODES IN THE LINKLIST:%d\n", cnt);
    return 0;
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
