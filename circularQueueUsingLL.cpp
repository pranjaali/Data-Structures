# Data-Structures
Data structure implementation using-c,c++,java
#include<iostream>
using namespace std;

class node{
public:
  int data;
  node *next;

  node(int data)
  {   
      this->data=data;
      next=NULL;
  }
  friend class nodeFun;
};

class nodeFun{
private:
 node *temp,*front,*rare,*ptr,*newn;
public:
void inqueue(int data);
void dequeue();
void peek();
void display();
int count();

nodeFun()
{
 ptr=NULL;
 front=NULL;
 rare=NULL;
 temp=NULL;
 newn=NULL;
}

};

// ---------------------------
void nodeFun::inqueue(int data)
{
  newn =new node(data);
  if(front==NULL && rare==NULL)
  {
    front=rare=newn;
    rare->next=front;
  }
  else{
      rare->next=newn;
      rare=rare->next;
      rare->next=front;
  }
}
// --------------------------
void nodeFun::dequeue()
{  temp=front;
    if(front==NULL && rare==NULL)
    {
        cout<<"QUEUE IS EMPTY:\nCAN'T PERFORM DEQUEUE OPERATION\n";
    }
    else if(front==rare)
    {  cout<<"1DEQUED ELEMENT IS ["<<front->data<<"]\n";
      front=NULL;
      rare=NULL;
      delete(temp);
    }
    else{
        cout<<"DEQUED ELEMENT IS ["<<front->data<<"]\n";
      
        front=front->next;
        delete(temp);
        rare->next=front;
    }
}
// --------------------------
void nodeFun::peek()
{
    if( front==NULL)
    {
        cout<<"QUEUE IS EMPTY:\n";

    }
    else{
        cout<<"TOP MOST ELEMENT IS ["<<front->data<<"]"<<endl;
    }
}
// -------------------------
void nodeFun::display()
{
    if( front==NULL)
    {
        cout<<"QUEUE IS EMPTY:\n";
    }
    else{
        ptr=front;

        do
        {
            cout<<"\n["<<ptr->data<<"]";
            ptr=ptr->next;
        }while(ptr!=front);
        cout<<endl;
    }
}
// ---------------------------
int nodeFun::count()
{
    int cnt=0;
    ptr=front;
    if(front==NULL)
    {
        return 0;
    }
    else{
        do{
            cnt++;
            ptr=ptr->next;

        }while(ptr!=front);
        return cnt;
    }
}
// ---------------------------

int main()
{
    nodeFun obj;
    char choice;
    do{
        cout<<"ENTER THE NUMBER OF OPERATION YOU WANT TO PERFORM:\n";
        cout<<"\t\t1.INQUEUE\n\t\t2.DEQUEUE\n\t\t3.PEEK\n\t\t4.DISPALY\n\t\t5.COUNT\n\t\t6.EXIT\n";
        cin>>choice;
        switch(choice)
        {
            case '1':
            {
                int data;
                cout<<"\n\tENTER THE DATA\n";
                cin>>data;
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
                cnt=obj.count();
                cout<<"COUNT IS:"<<cnt<<endl;
                break;
            }
            case '6':
            {
                cout<<"\n\tTHANK YOU!"<<endl;
                break;
            }
        }

    }while(choice!='6');
    return 0;
}
