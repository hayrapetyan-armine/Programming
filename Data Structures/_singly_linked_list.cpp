#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
    private:
        node *head, *tail;
    public:
        linked_list()
        {
            head = NULL;
            tail = NULL;
        }

        // add node to the end of the linked-list
        void add_node(int n)
        {
            node *tmp = new node;
            tmp->data = n;
            tmp->next = NULL;

            if(head == NULL)
            {
                head = tmp;
                tail = tmp;
            }
            else
            {
                tail->next = tmp;
                tail = tail->next;
            }
        }

        // Linked list traversal using while loop
        static void display(node *head)
        {
            node *tmp;
            tmp = head;
            while (tmp != NULL)
            {
                cout << tmp->data << endl;
                tmp = tmp->next;
            }
        }

        node* gethead()
        {
            return head;
        }

        // Traversal using recursion
        static void display_recursion(node *head)
        {
            if(head == NULL)
            {
                cout << "NULL" << endl;
            }
            else
            {
                cout << head->data << endl;
                display_recursion(head->next);
            }
        }

        // Concatenate two linked lists
        static void concatenate(node *a,node *b)
        {
            if( a != NULL && b!= NULL )
            {
                if (a->next == NULL)
                    a->next = b;
                else
                    concatenate(a->next, b);
            }
            else
            {
                cout << "Either a or b is NULL\n";
            }
        }

        void delete_first()
        {
            node *temp=new node;
            temp=head;
            head=head->next;
            delete temp;
        }

        void delete_last()
        {
            node *current=new node;
            node *previous=new node;
            current=head;
            while(current->next!=NULL)
            {
              previous=current;
              current=current->next;
            }
            tail=previous;
            previous->next=NULL;
            delete current;
        }

        void delete_position(int pos)
        {
            node *current=new node;
            node *previous=new node;
            current=head;
            for(int i=1; i<pos; i++)
            {
              previous=current;
              current=current->next;
            }
            previous->next=current->next;
        }
};

int main()
{
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.add_node(3);
    a.add_node(4);
    cout << "display linked list a with loop\n";
    linked_list::display(a.gethead());
    cout << "display linked list a with recursion\n";
    linked_list::display_recursion(a.gethead());
    linked_list b;
    b.add_node(5);
    b.add_node(6);
    b.add_node(7);
    cout << "concat linked lists a and b\n";
    linked_list::concatenate(a.gethead(),b.gethead());
    cout << "display the concatenated linked list\n";
    linked_list::display(a.gethead());
    cout << "delete the head node of linked list a\n";
    a.delete_first();
    cout << "display the updated linked list a\n";
    linked_list::display(a.gethead());
    cout << "delete the tail node of linked list a\n";
    a.delete_last();
    cout << "display the updated linked list a\n";
    linked_list::display(a.gethead());
    cout << "delete the position 2 node of linked list a\n";
    a.delete_position(3);
    cout << "display the updated linked list a\n";
    linked_list::display(a.gethead());
    return 0;
}

