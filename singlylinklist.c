#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
// ====================(COUNT NODES IN LINKLIST FUNCTION)=========
int countNodes(struct node **head)
{
    int count = 0;
    struct node *temp = (*head);
    if (temp == NULL)
    {
        return count;
    }
    else
    {
        count = 1;
        while (temp->link != NULL)
        {
            temp=temp->link;
            count++;
        }
        return count;
    }
}
// =======================(INSERSION FUNCTIONS)===============================
void insertFirst(struct node **head, int data)
{
    struct node *newn = (struct node *)malloc(sizeof(struct node));
    newn->data = data;
    newn->link = NULL;
    if ((*head) == NULL)
    {
        (*head) = newn;
    }
    else
    {
        newn->link = *head;

        (*head) = newn;
    }
}
// -------
void insertAtLAst(struct node **head, int data)
{
    struct node *temp = (*head);
    struct node *newn = (struct node *)malloc(sizeof(struct node));
    newn->data = data;
    newn->link = NULL;
    if ((*head) == NULL)
    {
        (*head) = newn;
    }
    else
    {
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newn;
        newn->link = NULL;
    }
}
// ----------------------------
void insertAtPOsition1(struct node **head, int position, int data)
{
    int nPosi = position - 1;
    struct node *temp = (*head);
    struct node *newn = (struct node *)malloc(sizeof(struct node));
    newn->data = data;
    newn->link = NULL;
    if (position == 1)
    {
        insertFirst(&(*head), data);
        // newn->link=temp;
        // (*head)=newn;
    }
    else
    {
        while (nPosi > 1)
        {
            temp = temp->link;
            nPosi--;
        }
        newn->link = temp->link;
        temp->link = newn;
    }
}
// ----------------------------
// ====================(DELETION FUNCTIONS)=======================
void deletFirst(struct node **head)
{
    struct node *temp = (*head);
    (*head) = temp->link;
    free(temp);
}
void deleteLast(struct node **head)
{
    struct node *temp = (*head), *ptr = temp;
    while (temp->link != NULL)
    {
        ptr = temp;
        temp = temp->link;
    }
    ptr->link = NULL;
    free(temp);
}
void deleteAtPosition(struct node **head, int position)
{
    int countnodes=countNodes(&(*head));
    if (position == 1)
    {
        deletFirst(&(*head));
    }
    else if(position>countnodes)
    {
        printf("\nLIST LIST HAS %d NODE",countnodes);
        printf("\n%d th NODE DOSENT EXIST:\n",position);
    }
    else
    {
        struct node *temp = (*head), *ptr = temp;
        int nPos = position;
        while (nPos > 1)
        {
            ptr = temp;
            temp = temp->link;
            --nPos;
        }
        ptr->link = temp->link;
        free(temp);
    }
}

// ====================(DISPLAY FUNCTION)=========================
void display(struct node **head)
{   
    if (*head == NULL)
    {
        printf("the list is empty:\n");
    }
    else
    {
        struct node *temp;
        temp = *head;
        while (temp != NULL)
        {
            printf("[%d]-->", temp->data);
            temp = temp->link;
        }
    }
}
// --------------

int main()
{
    struct node *first = NULL;

    insertFirst(&first, 1);
    insertFirst(&first, 2);
    insertFirst(&first, 3);
    insertFirst(&first, 4);
    insertAtPOsition1(&first, 1, 5);
    insertAtLAst(&first, 6);
    insertAtPOsition1(&first, 3, 7);
    deletFirst(&first);
    deleteLast(&first);
    deleteAtPosition(&first, 7);
    display(&first);
    int cnt = countNodes(&first);
    printf("\nnodes are-%d", cnt);

    return 0;
}
