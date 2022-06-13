# Data-Structures
Data structure implementation using-c,c++,java

#include<stdio.h>
#define size 10
int stack1[size],stack2[size];
int top1=-1,top2=-1;
int cnt=0;
// ================================================================================
int push1(int data)
{
    stack1[++top1]=data;
}
int push2(int data)
{
    stack2[++top2]=data;
}
// --------------------------------------------------------------------------------
int pop1()
{
    return(stack1[top1--]);
}
int pop2()
{
    return(stack2[top2--]);
}
// -------------------------------------
void enqueue(int data)
{
   push1(data);
   cnt++;
}
void dequeue()
{
    for(int i=0;i<=cnt;i++)
    {
        push2(pop1());
    }
    pop2();
    cnt--;
    for(int j=0;j<=cnt;j++)
    {
        push1(pop2());
    }


}
// --------------------------
int peek()
{
    return stack1[0];
}
// ---------------------------
void display()
{
    for(int i=0;i<=top1;i++)
    {
        printf("[%d]\n",stack1[i]);
    }
}
// =================================================================================
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
                enqueue(data);
                break;
            }
            case '2':
            {   dequeue();
                break;
            }
            case '3':
            {   int topData=0;
                topData=peek();
                printf("[%d]\n",topData);
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
