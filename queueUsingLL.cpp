# Data-Structures
#include <iostream>
using namespace std;

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
    friend class nodeFun;
};

class nodeFun
{
private:
    node *temp, *front, *rare, *newn;

public:
    void inqueue(int data);
    void dequeue();
    void peek();
    void display();
    int count();
    nodeFun()
    {
        newn = NULL;
        front = NULL;
        temp = NULL;
        rare = NULL;
    }
};
// =======================================================================
// --------------inqueue------------------------------------------------
void nodeFun::inqueue(int data)
{
    newn = new node(data);

    if (front == NULL && rare == NULL)
    {
        front = rare = newn;
    }
    else
    {
        rare->next = newn;
        rare = newn;
    }
}
void nodeFun::dequeue()
{
    temp = front;
    if (front == NULL && rare == NULL)
    {
        cout << "UNDERFLOW CONDITION:\n";
    }
    else
    {
        temp = front;
        cout << "DEQUED ELEMENT WAS:" << front->data << endl;
        front = front->next;
        delete (temp);
    }
}
void nodeFun::peek()
{
    if (front == NULL && rare == NULL)
    {
        cout << "QUEUE IS EMPTY\n";
    }
    else
    {
        cout << "FRONT ELEMENT OF WUEUE IS: [" << front->data << "]" << endl;
    }
}

void nodeFun::display()
{

    if (front == NULL && rare == NULL)
    {
        cout << "QUEUE IS EMPTY:\n";
    }
    else
    {
        temp = front;
        while (temp != NULL)
        {
            cout << "[" << temp->data << "]";
            temp = temp->next;
        }
    }
}
int nodeFun::count()
{
    int count = 0;
    if (front == NULL && rare == NULL)
    {
        cout << "QUEUE IS EMPTY:\n";
        return 0;
    }
    else
    {
        temp = front;
        while (front != NULL)
        {
            count++;
            front = front->next;
        }
        return count;
    }
}

// =======================================================================
int main()
{
    nodeFun obj;
    int data;

    char choice;
    do
    {
        cout << "\n===========================================================\n";
        cout << "\t\t1.INQUEUE\n\t\t2.DEQUEUE\n\t\t3.PEEK\n\t\t4.DISPLAY\n\t\t5.COUNT\n\t\t6.EXIT\n\t\tENETER OPERATION NUMBER YOU WANT TO PERFORM\n";
        cin >> choice;
        switch (choice)
        {
        case '1':
        {
            cout << "\nENTER THE DATA:\n";
            cin >> data;
            obj.inqueue(data);
            break;
        }
        case '2':
        {
            obj.dequeue();
            break;
        }
        case '3':
        {
            obj.peek();
            break;
        }
        case '4':
        {
            obj.display();
            break;
        }
        case '5':
        {
            int cnt;
            cnt = obj.count();
            cout << "COUNT OF ELEMENTS IN QUEUE IS :" << cnt << endl;
            break;
        }
        case '6':
        {
            break;
        }
        }
    } while (choice != '6');
}
