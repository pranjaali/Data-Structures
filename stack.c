#include <stdio.h>
#define N 5
int top = -1;
int stack[N];
int element = 0;
// ===========  PUSH  ===============
void push()
{
    if (top == (N - 1))
    {
        printf("STACK IS FULL:\nSTACK OVERFLOW\n");
    }
    else if (top >= -1 && top <= (N - 1))
    {
        top++;
        printf("ENTER THE ELEMENT YOU WANT TO ADD:\n");
        scanf("%d", &element);
        stack[top] = element;
    }
    else
    {
        printf("PUSH OPERATION UNSUCCESFUL:\n");
    }
}
// ======  POP  =========
void pop()
{
    if (top == (-1))
    {
        printf("STACK UNDERFLOW\n");
    }
    else if (top <= (N - 1) && top >= (-1))
    {
        printf("(%d)", top);
        printf("POPED ELEMENT %d :\n", stack[top]);
        stack[top] = 0;
        top = top - 1;
        printf("(%d)", top);
    }
}
// ======= PEEK    ======
void peek()
{
    if (top == (-1))
    {
        printf("stack is empty:\n");
    }
    else if (top > (-1) && top <= (N - 1))
    {
        printf("TOPMOST ELEMENT IS:>[%d]", stack[top]);
    }
}
// ======= ISEMPTY ======
void isempty()
{
    if (top == (-1))
    {
        printf("STACK IS EMPTY:\n");
    }
    else if (top > (-1) && top <= (N - 1))
    {
        printf("STACK IS NOT EMPTY:\n");
    }
}
// ======= ISFULL  ======
void isnull()
{
    if (top == (N - 1))
    {
        printf("STACK IS FULL:\n");
    }
    else
    {
        printf("STACK IS NOT FULL:\n");
    }
}
// ======= DISPLAY ======
void display()
{
    printf("\n____________________________________\n");
    if (top == (-1))
    {
        printf("STACK IS EMPTY:\n");
    }
    else if (top > (-1) && top <= (N - 1))
    {
        for (int i = top; i > (-1); i--)
        {
            printf("[%d]\n", stack[i]);
        }
    }
    printf("\n____________________________________\n");
}

int main()
{
    printf("enter operation you want to perform:\n");
    int choice = 0;

    do
    {
        printf("\n____________________________________\n");
        printf("1.PUSH -INSERT ELEMENT\n2.POP-DELETE FIRST ELEMENT\n3.PEEK-RETURNS TOPMOST ELEMENT\n4.ISEMPTY-CHECKS WHWTHER THE STACK IS EMPTY OR NOT\n5.ISFULL-CHECKS HWETHER STACK IS FULL:\n6.DISPLAY\n7.EXIT\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            peek();
            break;
        }
        case 4:
        {
            isempty();
            break;
        }
        case 5:
        {
            isnull();
            break;
        }
        case 6:
        {
            display();
            break;
        }
        }
    } while (choice != 7);
    return 0;
}
