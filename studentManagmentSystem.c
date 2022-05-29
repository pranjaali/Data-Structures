// shree swami samrath----
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int roll_no, marks;
    char name[200];
    char phone[11];
    char department[100];
    struct student *link;
};

// ----------------------------
void insert(struct student **head, int roll_no, char *name, char *phone, int marks)
{
    struct student *temp = (*head);
    struct student *newstudent = (struct student *)malloc(sizeof(struct student));
    newstudent->roll_no = roll_no;
    newstudent->marks = marks;
    strcpy(newstudent->name, name);
    strcpy(newstudent->phone, phone);
    newstudent->link = NULL;
    if ((*head) == NULL)
    {
        (*head) = newstudent;
    }
    else
    {
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = newstudent;
        newstudent->link = NULL;
        printf("(%d)", temp->roll_no);
    }
}
// ---------------------------
void DeleteRecord(struct student **head, int Roll_No)
{
    struct student *temp = (*head);
    struct student *ptr=temp;
    if (temp == NULL)
    {
        printf("\nSORRY WE CAN NOT DELTE ANY RECORDS AS LIST IS EMPTY:\n");
    }
    else
    {

        while (temp->roll_no != Roll_No)
        {   ptr=temp;
            temp = temp->link;
        }
        if (temp->roll_no == Roll_No)
        {
           ptr->link=temp->link;
           free(temp);
           printf("\nRECORD HAS BEEN SUCCESFULLY DELETED!\n");

        }
        else if (temp->roll_no != Roll_No)
        {
            printf("Deletion of record was unsuccesful!\nENTERED ROLL NUMBER DOES NOT EXIST IN THE LIST:\n");
        }
    }
}
// ----------------------------
void display(struct student **head)
{
    struct student *temp = (*head);
    if ((*head) == NULL)
    {
        printf("LIST IS EMPTY:\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("\n-----------------\n");
            printf("\nROLL NO       :%d", temp->roll_no);
            printf("\nNAME          :%s", temp->name);
            printf("\nPHONE NUMBER  :%s", temp->phone);
            printf("\nMARKS         :%d", temp->marks);
            // printf("\n--------------\n");

            temp = temp->link;
        }
    }
}
// -----------------------------------
int CountRecord(struct student** head)
{    int count=0;
    struct student *temp=(*head);
    if(temp==NULL)
    {
        return count;
    }
    else{
        while(temp!=NULL)
        {
            temp=temp->link;
            count++;
        }
        return count;
        
    }
}
// -===================================
int main()
{
    struct student *first = NULL;
    int roll_no = 0, marks = 0;
    char name[200];
    char phone[11];
    char department[100];
    int choice = 0;

    //  ----
    printf("1.to insert students details\n2.Delete the students record\n3.COUNT THE RECORDS\n5.display\n");
    do
    {
        printf("\n-----------------------\n");
        printf("ENTER YOUR CHOICE:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            printf("ENTER ROLL NUMBER:\n");
            scanf("%d", &roll_no);
            printf("ENTER THE NAME:\n");
            scanf("%s", name);
            printf("ENTER PHONE NUMBER:\n");
            scanf("%s", phone);
            printf("ENTER MARKS :\n");
            scanf("%d", &marks);
            insert(&first, roll_no, name, phone, marks);
            break;
        }
        case 2:
        {
            int ROll_No = 0;
            printf("ENTER THE ROLL NUMBER OF STUDENT WHOES RECORD YOU WANT TO DELETE:\n");
            scanf("%d", &ROll_No);
            DeleteRecord(&first, ROll_No);
            break;
        }
        case 3:
        {   int count=0;

             count= CountRecord(&first);
             printf("THERE ARE %d RECORD:\n",count);
             break;
        }
        case 5:
        {
            display(&first);
            break;
        }
           
        }
    }while(choice !=0);

}
