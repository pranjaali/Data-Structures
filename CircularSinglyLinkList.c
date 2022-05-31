#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *tail = NULL;
// =================INSERTION OF NODE==============================
void insertAtFirst(struct node **head, int data)
{
    struct node *newn = (struct node *)malloc(sizeof(struct node));
    newn->link = NULL;
    newn->data = data;
    struct node *temp = (*head);
    if ((*head) == NULL)
    {
        (*head) = temp = newn;
        tail = newn;
        tail->link = newn;
    }
    else
    {
        while (temp->link != (*head))
        {
            temp = temp->link;
        }
        newn->link = (*head);
        temp->link = newn;
        (*head) = newn;
    }
}
// -----------------------------
void insertAtLast(struct node **head, int data)
{
    struct node *newn = (struct node *)malloc(sizeof(struct node));
    struct node *temp = (*head);
    newn->link = NULL;
    newn->data = data;
    if ((*head) == NULL)
    {
        (*head) = temp = newn;
        tail = newn;
        tail->link = newn;
    }
    else
    {
        tail->link = newn;
        tail = newn;
        tail->link = (*head);
    }
}
// ------------------------------
void insertAtPOsition(struct node **head, int data, int possition)
{
    struct node *newn = (struct node *)malloc(sizeof(struct node));
    newn->link = NULL;
    newn->data = data;
    struct node *temp = (*head);
    struct node *ptr = NULL;
    if ((*head) == NULL)
    {
        (*head) = newn;
        tail = newn;
        tail->link = newn;
    }
    else
    {
        if (possition == 1)
        {
            while (temp->link != (*head))
            {
                temp = temp->link;
            }
            temp->link = newn;
            newn->link = (*head);
            (*head) = newn;
        }
        else
        {
            ptr = temp->link;
            for (int i = 1; (i < possition - 1); ++i)
            {
                temp = temp->link;
                ptr = temp->link;
            }
            temp->link = newn;
            newn->link = ptr;
        }
    }
}
// ====================DELETE NODES======================
void deleteAtFirst(struct node **head)
{
    struct node *temp = (*head);
    struct node *ptr = temp;
    if ((*head) == NULL)
    {
        printf("\nLink list is empty:\n");
        printf("\nDELETION OF NODE WAS UNSUCCESSFUL\n");
    }
    else
    {
        if ((*head)->link == NULL)
        {
            temp = (*head);
            (*head) = NULL;
            free(temp);
        }
        else
        {
            while (temp->link != (*head))
            {
                temp = temp->link;
            }
            (*head) = ptr->link;
            temp->link = (*head);
            free(ptr);
        }
    }
}
// -------------------------
void deleteAtLast(struct node **head)
{
    struct node *ptr, *preptr;
    if ((*head) == NULL)
    {
        printf("\nUNDERFLOW");
    }
    else if ((*head)->link == (*head))
    {
        (*head) = NULL;
        free(*head);
        printf("\nnode deleted\n");
    }
    else
    {
        ptr = (*head);
        while (ptr->link != (*head))
        {
            preptr = ptr;
            ptr = ptr->link;
        }
        preptr->link = ptr->link;
        free(ptr);
        printf("\nnode deleted\n");
    }
}
// ====================COUNT NUMBER OF NODE==================
int countNodes(struct node **head)
{
    int count = 0;
    struct node *temp = (*head);
    if ((*head == NULL))
    {
        count = 0;
        return count;
    }
    else
    {
        count = 1;
        while (temp->link != (*head))
        {
            count++;
            temp = temp->link;
        }
        return count;
    }
}
// ====================DISPLAY NODE OF CIRCULAR LINK LIST===============
void display(struct node **head)
{   printf("\n");
    struct node *temp = (*head);
    do
    {
        printf(" [%d] ->", temp->data);
        temp = temp->link;
    } while (temp != (*head));
}
// ================================
int main()
{
    struct node *first = NULL;
    // insertAtFirst(&first,29);

    insertAtLast(&first, 0);

    display(&first);
    insertAtLast(&first, 2);
    display(&first);
    insertAtFirst(&first, 9);
    insertAtPOsition(&first, 44, 4);
    deleteAtFirst(&first);
    insertAtPOsition(&first, 44, 1);
    deleteAtFirst(&first);
    deleteAtLast(&first);
    display(&first);
    int noOfNode = countNodes(&first);
    printf("\nnumber of nodes in the list are :%d", noOfNode);
    return 0;
}
