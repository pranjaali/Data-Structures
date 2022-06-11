# Data-Structures
using-c,c++,java
#include<stdio.h>
#define size 5
int arr[size];
int front=-1,rare=-1;
// ==================  INQUEUE  ===================================== 
void inqueue(int data)
{
    if(rare==(size-1))
    {
        printf("CAN NOT PERFORM\nOVERFLOW CONDITON");
    }
    else if(front==-1 && rare==-1)
    {   
        rare=front=0;
        arr[rare]=data;
    
    }
    else
    { rare++;
        arr[rare]=data;
    }

}
// ==================  DEQUEUE  =====================================
void dequeue()
{
    if(front==-1 && rare==-1)
    {
        printf("QUEUE IS EMPTY \n CAN'T PERFORM DEQUEUE OPERATION");
    }
    else if(front<size)
    {
         printf("\ndequed element is %d\n",arr[front]);
        arr[front]=0;
        front++;
    }
    else{
        printf("QUEUE IS EMPTY\n");
    }
}
// ==================  PEEK     =====================================
int peek()
{
    if(front==-1 && rare==-1)
    {
        printf("\nQUEUE IS EMPTY:\n");
        return 0;
    }
    else{
        printf("[%d]",arr[front]);
        return arr[front];
    }
}
// ==================  DISPLAY  =====================================
void display()
{    printf("\n");
    for(int i=0;i<=rare;i++)
    {
        printf("[%d]-",arr[i]);
    }
    printf("\n");
}
int main()
{   char choice=0;
    int data;
    do{ printf("\n===========================================================\n");
        printf("\t\t1.INQUEUE\n\t\t2.DEQUEUE\n\t\t3.PEEK\n\t\t4.DISPLAY\n\t\t5.EXIT\n\t\tENETER OPERATION NUMBER YOU WANT TO PERFORM\n");
        scanf("%c",&choice);
        switch(choice)
        {   case '1':
            {   printf("\nENTER THE DATA:\n");
                scanf("%d",&data);
                inqueue(data);
                break;
            }
            case '2':
            {   dequeue();
                break;
            }
            case '3':
            {   int topData=0;
                topData=peek();
                break;
            }
            case '4':
            {display();
                break;
            }
            case '5':
            {break;
            }}
    }while(choice!='5');
    return 0;
}
