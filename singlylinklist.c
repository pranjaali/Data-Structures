#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
// ====================(COUNT NODES IN LINKLIST FUNCTION)=========
int countNodes(struct node **head) // Time Complexity: O(N)
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
        while (temp->link != NULL) // -------------------Time Complexity: O(N)
        {
            temp = temp->link;
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
void insertAtLAst(struct node **head, int data) // Time Complexity: O(N)
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
        while (temp->link != NULL) // -------------------Time Complexity: O(N)
        {
            temp = temp->link;
        }
        temp->link = newn;
        newn->link = NULL;
    }
}
// ----------------------------
void insertAtPOsition1(struct node **head, int position, int data) // Time Complexity: O(N)
{
    int nPosi = position - 1;
    struct node *temp = (*head);
    struct node *newn = (struct node *)malloc(sizeof(struct node));
    newn->data = data; //---------------------O(1)
    newn->link = NULL; //---------------------O(1)
    if (position == 1)
    {
        insertFirst(&(*head), data); //---------------------O(1)
        // newn->link=temp;
        // (*head)=newn;
    }
    else
    {
        while (nPosi > 1) // -------------------Time Complexity: O(N)
        {
            temp = temp->link;
            nPosi--;
        }
        newn->link = temp->link; //---------------------O(1)
        temp->link = newn;       //---------------------O(1)
    }
}
// ----------------------------
// ====================(DELETION FUNCTIONS)=======================
void deletFirst(struct node **head)
{
    struct node *temp = (*head); //---------------------O(1)
    (*head) = temp->link;        //---------------------O(1)
    free(temp);                  //---------------------O(1)
}
void deleteLast(struct node **head) // Time Complexity: O(N)
{
    struct node *temp = (*head), *ptr = temp; //---------------------O(1)
    while (temp->link != NULL)                // -------------------Time Complexity: O(N)
    {
        ptr = temp;
        temp = temp->link;
    }
    ptr->link = NULL; //---------------------O(1)
    free(temp);       //---------------------O(1)
}
void deleteAtPosition(struct node **head, int position) // Time Complexity: O(N)
{
    int countnodes = countNodes(&(*head)); //---------------------O(1)
    if (position == 1)
    {
        deletFirst(&(*head)); //---------------------O(1)
    }
    else if (position > countnodes)
    {
        printf("\nLIST LIST HAS %d NODE", countnodes);    //---------------------O(1)
        printf("\n%d th NODE DOSENT EXIST:\n", position); //---------------------O(1)
    }
    else
    {
        struct node *temp = (*head), *ptr = temp; //---------------------O(1)
        int nPos = position;                      //---------------------O(1)
        while (nPos > 1)                          // -------------------Time Complexity: O(N)
        {
            ptr = temp;
            temp = temp->link;
            --nPos;
        }
        ptr->link = temp->link; //---------------------O(1)
        free(temp);             //---------------------O(1)
    }
}

// ====================(DISPLAY FUNCTION)=========================
void display(struct node **head) // Time Complexity: O(N)
{
    if (*head == NULL)
    {
        printf("the list is empty:\n"); //---------------------O(1)
    }
    else
    {
        struct node *temp;   //---------------------O(1)
        temp = *head;        //---------------------O(1)
        while (temp != NULL) // ------------------- O(N)
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
