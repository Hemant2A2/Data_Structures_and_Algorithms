

#include <iostream>

using namespace std;

class Node
{
   public:
   
   int data;
   Node *next;
};

class Linked_List
{
    private:
    
    Node *first;
    Node *last;
    
    public:
   
    Linked_List(){cout << "constructor called." << endl;}
   
    void create()
    {
       
       int n;
       cout << "\nEnter the number of elements:" << endl;
       cin >> n;
       cout << "\nEnter the elements:" << endl;
       for( int i{0}; i < n; i++)
       {
           int e;
           Node *t;
           cin >> e;
           if( i == 0)
           {
               first = new Node;
               first->data = e;
               first->next = nullptr;
               last = first;
           }
           else
           {
               
               t = new Node;
               t->data = e;
               t->next = nullptr;
               last->next = t;
               last = t;
               
           }
        }
        last->next = nullptr;
    }
   
    void display()
    {
        cout << "\nDisplaying the list....." << endl;
        Node *t = first;
        while(t)
       {
           cout << t->data << " " ;
           t = t->next;
       }
       delete t;
    }
    
    void insert(int index , int x)
    {
        Node *p , *q;
        p = first;
        if(index != 0)
        {  
            for(int i{0}; i < index -1 ; i++)
            {
                if(p != last->next)
                {
                    p = p->next;
                }
                else 
                {
                    cout << "\nCannot Insert" << endl;
                    break;
                }
            }
            if(p != last->next)
            {
                q = new Node;
                q->data = x;
                q->next = p->next;
                p->next = q;
            }
        }
        else
        {
            q = new Node;
            q->data = x;
            first = q;
            first->next = p;
        }
    }
    
    void insert_last(int x)
    {
        Node *p;
        p = new Node;
        p->data = x;
        last->next = p;
        last = p;
        last->next = nullptr;
    }
    
    void length()
    {
        Node *p = first;
        int size{0};
        while(p)
        {
            p = p->next;
            size++;
        }
        cout << "\nThe list has " << size << " elements" << endl;
    }
    
    void sum()
    {
        Node *p = first;
        int sum{0};
        while(p)
        {
            sum += p->data;
            p = p->next;
        }
        
        cout << "\nThe sum of elements of the list is " << sum << endl;
    }
    
    void erase(int index)
    {
        if(index != 0)
        {
            Node *p = first;
            for(int i{0}; i < index -1; i++)
            {
                p = p->next;
            }
            Node *q = p->next;
            p->next = q->next;
            q->next = nullptr;
            delete q;
        }
        else
        {
            Node *p = first;
            first = p->next;
            delete p;
        }
    }
    
    // void reverse()
    // {
    //     cout << "\nReversing the list...." << endl;
        
    // }
    
    void search(int key)
    {
        Node *p = first;
        while(p)
        {
            if(p->data == key)
            {
                cout << endl;
                cout << key << " found!" << endl;
                break;
            }
            else if( p == last)
            {
                cout << endl;
                cout << key << " not found" << endl;
            }
            p = p->next;
        }
    }
    
    void concat(Linked_List &to_add)
    {
        last->next = to_add.first;
    }
    
    void merge_sorted(Linked_List to_merge)
    {
        Node *p = first;
        Node *q = to_merge.first;
        Node *r = p;
        
        do
        {
            if(p->data < q->data)
            {
                if(r->next == q)
                {
                    r->next = p;
                }
                r = p;
                p = p->next;
            }
            else
            {
                if(r->next == p)
                {
                    r->next = q;
                }
                r = q;
                q = q->next;
            }
        }
        while(p || q);
        if(p == nullptr)
        {
            last->next = q;
        }
        else
        {
            to_merge.last->next = p;
        }
    }
   
    ~Linked_List(){cout << "\n\nDestructor called." << endl;}
};

   
   

int main()
{
    Linked_List list{};
    Linked_List list2{};
    list.create();
    list.display();
    list2.create();
    list2.display();
    // list.insert_last(6);
    // list.display();
    // list.insert(8,9);
    // list.display();
    // list.length();
    // list.sum();
    // list.erase(0);
    // list.display();
    // list.search(7);
    // list.concat(list2);
    // list.display();
    // list2.display();
    // list2.concat(list);
    // list2.display();
    // list.display();
    list.merge_sorted(list2);
    list.display();
    
    

    return 0;
}
