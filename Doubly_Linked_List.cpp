
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

class Doubly_LL
{
private:
    Node *first;
    
public:
    
    Doubly_LL(int n)
    {
        cout << "Constructor called" << endl;
        int e;
        Node *t , *last;
        cout << "\nEnter the elements:" << endl;
        for( int i{0}; i < n; i++)
        {
            cin >> e;
            if(i == 0)
            {
                first = new Node;
                first->data = e;
                first->prev = first->next = nullptr;
                last = first;
            }
            else
            {
                t = new Node;
                t->data = e;
                last->next = t;
                t->prev = last;
                t->next = nullptr;
                last = t;
            }
        }
    }
    
    void display()
    {
        cout << "\nDisplaying the list...." << endl;
        Node *p = first;
        while(p)
        {
            cout << p->data << " " ;
            p = p->next;
        }
    }
    
    int length()
    {
        Node *p = first;
        int l{0};
        while(p)
        {
            p = p->next;
            l++;
        }
        return l;
    }
    
    void insert(int pos , int x)
    {
        Node *t;
        if( pos > 0 && pos <= length())
        {
            Node *p = first;
            for( int i{0}; i < pos -1; i++)
            {
                p = p->next;
            }
            t = new Node;
            t->data = x;
            t->next = p->next;
            t->prev = p;
            if(p->next)
            {
                t->next->prev = t;
            }
            p->next = t;
        }
        else if( pos == 0)
        {
            t = new Node;
            t->data = x;
            t->prev = nullptr;
            t->next = first;
            first->prev = t;
            first = t;
        }
        else
        {
            cout << "\n\nINVALID Insertion!!" << endl;
        }
    }
    
    void erase(int pos)
    {
        if(pos > 0 && pos <= length())
        {
            Node *p = first;
            for(int i{0}; i < pos - 1; i++)
            {
                p = p->next;
            }
            Node *t = p->next;
            if(t->next)
            {
                p->next = t->next;
                t->next->prev = p;
                t->prev = t->next = nullptr;
                delete t;
            }
            else
            {
                p->next = t->prev = nullptr;
                delete t;
            }
        }
        else if( pos == 0)
        {
            Node *p = first;
            first = first->next;
            first->prev = nullptr;
            p->next = nullptr;
            delete p;
        }
        else
        {
            cout << "\n\nINVALID Deletion!!" << endl;
        }
    }
    
    void reverse()
    {
        Node *p = first;
        while(p)
        {
            if(p->next == nullptr )
            {
                first = p;
            }
            Node *temp = p->next;
            p->next = p->prev;
            p->prev = temp;
            p = p->prev;
        }
    }
    
    ~Doubly_LL()
    {
        delete first;
        cout << "\nDestructor called" << endl;
    }
    
};


int main()
{
    Doubly_LL dList(5);
    dList.display();
    // cout << "\n\n" << dList.length() << " is the length" << endl;
    // dList.insert(2,100);
    // dList.display();
    // dList.erase(2);
    // dList.display();
    dList.reverse();
    dList.display();
    
    

    return 0;
}