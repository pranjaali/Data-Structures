# Data-Structures
using-c,c++,java
#include<stdio.h>
int num=0;
int display(int *ptr)
{
 for(int k=0;k<num;k++)
     {
         printf("[%d]",ptr[k]);
     }
}
  // ==========INSERTION AT START===
// ---------insert at the start-----
int insertAtbegining(int *ptr)
{
     int element=0;
    for(int j=(num-1);j>=0;j--)
    {
        ptr[j+1]=ptr[j];
    }
    printf("enter the element you want to add:\n");
    scanf("%d",&element);
    ptr[0]=element;
    num++;
}
// --------insert at the end-----
int insertAtend(int *ptr)
{
    int element=0;
    printf("enter the element you want to insert at end:\n");
    scanf("%d",&element);
    ptr[num]=element;
    num++;
}
// ------insert at the possition--
int insertAtPossition(int *ptr)
{
    int element=0,possition=0;
    printf("enter the element you want to insert:\n");
    scanf("%d",&element);
    printf("enter the possition atb which you want to insert the element:\n");
    scanf("%d",&possition);

    if(possition==1)
    {
        for(int i=(num-1);i>=0;i--)
        {
            ptr[i+1]=ptr[i];

        }
        ptr[0]=element;
        num++;
    }
    else if(possition==(num+1))
    {
        ptr[num]=element;
        num++;
    }
        // printf("[%d\t%d",ptr[num],ptr[num+1]);
    else if(possition>1 && possition<(num+1))
    {  
        int i=num-1;
        while(i!=(possition-2))
        {
            ptr[i+1]=ptr[i];
            i--;
        }
        ptr[possition-1]=element;
         num++;
    }

}
// =========delete elements======
// ---------delete from first----
void deleteFirst(int *ptr)
{
    for(int i=0;i<=(num-1);i++)
    {
        ptr[i]=ptr[i+1];
    }
    ptr[num-1]=0;
    num--;
}
// ----------delete from last----
void deleteLast(int *ptr)
{
    ptr[num-1]=0;
    num--;
} 
// ----------delete from possition---
void deletePossition(int *ptr)
{   int possition;
    printf("enter the possition:\n");
    scanf("%d",&possition);
   for(int i=(possition-1);i<num;i--)
   {
       ptr[i]=ptr[i+1];

   } 
   num--;
}
int main()
{
   
    printf("enter the size of array:\n");
    scanf("%d",&num);
    int arr[50];
    printf("enter the elements of array");
    for(int i=0;i<num;++i)
    {
        scanf("%d",&arr[i]);
    }
    insertAtend(&arr[0]);
    insertAtPossition(&arr[0]);
     deleteFirst(&arr[0]);
    deleteLast(&arr[0]);
    // deletePossition(&arr[0]);
    // ==========DISPLAY ARRAY=========
    display(&arr[0]);
    
     return 0;
}
