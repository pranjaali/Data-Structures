# Data-Structures
using-c,c++,java
#include <iostream>
using namespace std;
// ================
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
    friend class stackOp;
};
class stackOp
{
private:
    node *temp, *ptr, *top, *head;

public:
    void push(int data);
    void pop();
    void display();
    int size();

    stackOp()
    {
        head = NULL;
        top = NULL;
        ptr = NULL;
        temp = NULL;
    }
};
// ======================    FUNCTIONS  =====================================
// ----------------------    push       -------------------------------------
void stackOp::push(int data)    //---------------------O(1)
{
    temp = new node(data);
    ptr = top;
    if (ptr == NULL)            //---------------------O(1)
    {
        top = ptr = temp;
        top->next = NULL;
    }
    else if (ptr != NULL)
    {
        temp->next = ptr;
        top = temp;
    }
}
// ----------------------    pop        -------------------------------------
void stackOp::pop()          //---------------------O(1)
{
    temp = ptr = top;

    if (ptr == NULL)        //---------------------O(1)
    {
        cout << "CAN NOT PERFORM POP OPERATION AS STACK IS EMPTY:" << endl;
    }
    else if (ptr != NULL)
    {
        temp = top;
        top = ptr->next;
        cout << "POPED ELEMENT IS " << temp->data << "!" << endl;
        delete (temp);
    }
}
// ----------------------    display    -------------------------------------
void stackOp::display()      //---------------------O(n)
{
    ptr = top;
    cout << "________________________________________________\n"
         << endl;
    if (ptr == NULL)        //---------------------O(1)
    {
        cout << "STACK IS EMPTY:" << endl;
    }
    else if (ptr != NULL)   //---------------------O(n)
    {
        while (ptr != NULL)    
        {
            cout << "[" << ptr->data << "]" << endl;
            ptr = ptr->next;
        }
    }
    cout << "________________________________________________" << endl;
}
// ----------------------    size       -------------------------------------
int stackOp::size()    //---------------------O(n)
{
    ptr = top;
    int count = 0;
    if (ptr == NULL)   //---------------------O(1)
    {
        return 0;
    }
    else if (ptr != NULL)
    {
        while (ptr != NULL)   //---------------------O(n)
        {
            count++;
            ptr = ptr->next;
        }
        return count;
    }
}
// ===========================================================================
int main()
{
    char choice;
    stackOp stack;
    do
    {
        cout << "         ______________________________________________ " << endl;
        cout << "\t|\tSTACK OPERATIONS                       |" << endl;
        cout << "        |______________________________________________|" << endl;

        cout << "\t|\t1].PUSH ELEMENT IN THE STACK           |" << endl;
        cout << "\t|\t2].POP ELEMENT FROM THE STACK          |" << endl;
        cout << "\t|\t3].DISPLAY ELEMENTS IN THE STACK       |" << endl;
        cout << "\t|\t4].COUNT THE EMEMENTS FROM THE STACK   |" << endl;
        cout << "        |______________________________________________|" << endl;

        cout << "\t\tENTER YOUR CHOICE:\n";
        cin >> choice;
        switch (choice)
        {
        case '1':
        {
            int data;
            cout << "ENTER THE DATA YOU WANT TO PUSH  :";
            cin >> data;
            stack.push(data);
            break;
        }
        case '2':
        {
            stack.pop();
            break;
        }
        case '3':
        {
            stack.display();
            break;
        }
        case '4':
        {
            int sizeOfStack = 0;
            sizeOfStack = stack.size();
            cout << "SIZE OF STACK IS :" << sizeOfStack << endl;
        }
        }
        cout << "DO YOU WANT TO CONTINUE    :";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

   
}
