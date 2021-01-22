#include <iostream>
using namespace std;


struct Node {
   int data;
   struct Node *next;
};


class StackNode {

  private:
    Node* top;

  public:
    StackNode(){
      top = NULL;
    }

    void push(int val) {
       struct Node* newnode = new Node;
       newnode->data = val;
       newnode->next = top;
       top = newnode;
    }

    void pop() {
       if(top==NULL)
       cout<<"Stack Underflow"<<endl;
       else {
          cout<<"The popped element is "<< top->data <<endl;
          top = top->next;
       }
    }

    void display() {
       struct Node* ptr;
       if(top==NULL)
        cout<<"stack is empty";
       else {
          ptr = top;
          cout<<"Stack elements are: ";
          while (ptr != NULL) {
             cout<< ptr->data <<" ";
             ptr = ptr->next;
          }
       }
       cout<<endl;
    }
};

int main()
{
  StackNode s;
  cout<<"Stack Push: "<<endl;

  s.push(100);
  s.push(200);
  s.push(300);

  cout<<"\nStack Pop:"<<endl;

  s.pop();
  s.display();
  return 0;
}