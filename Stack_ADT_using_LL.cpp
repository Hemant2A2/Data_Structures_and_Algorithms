
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class stack_LL
{
private:
    Node *top{nullptr};
    
public:
    stack_LL()
    {
        cout << "Constructor called" << endl;
        int n;
        Node *t;
        cout << "\nEnter the number of elements:" ;
        cin >> n;
        int e;
        cout << "\nEnter the elements:" << endl;
        for( int i{0}; i < n; i++)
        {
            cin >> e;
            if( i == 0)
            {
                top = new Node;
                top->data = e;
                top->next = nullptr;
            }
            else
            {
                t = new Node;
                t->data = e;
                t->next = top;
                top = t;
            }
        }
    }
    
    bool is_empty()
    {
        if( top == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool is_full()
    {
        Node *t = new Node;
        if(t == nullptr)
        {
            delete t;
            return true;
        }
        else
        {
            delete t;
            return false;
        }
    }
    
    void display()
    {
        if(is_empty() == false)
        {    cout << "\nDisplaying the elements....." << endl;
            Node *p = top;
            while(p)
            {
                cout << "\n           " << p->data ;
                p = p->next;
            }
            cout << endl;
        }
        else
        {
            cout << "\nNO elements to display!!!" << endl;
        }
    }
    
    int length()
    {
        Node *p = top;
        int l{0};
        while(p)
        {
            p = p->next;
            l++;
        }
        return l;
    }
    
    void push(int x)
    {
        if(is_full() == false)
        {
            Node *t = new Node;
            t->data = x;
            t->next = top;
            top = t;
        }
        else
        {
            cout << "\nStack OverFlow!!!" << endl;
        }
    }
    
    void pop()
    {
        if(is_empty() == false)
        {
            Node *t = top;
            top = top->next;
            delete t;
        }
        else
        {
            cout << "\nNO elements to DELETE!!!" << endl;
        }
    }
    
    void peek(int pos)
    {
        if( is_empty() == false)
        {
            if( pos > 0 && pos <= length())
            {
                Node *p = top;
                for( int i{1}; i < pos; i++)
                {
                    p = p->next;
                }
                cout << "\n"<< p->data << endl;
            }
            else
            {
                cout << "\nINVALID position" << endl;
            }
        }
        else
        {
            cout << "\nStack is EMPTY!!" << endl;
        }
    }
    
    ~stack_LL(){cout << "\nDestructor called" << endl;}
};

int main()
{
    stack_LL st{};
    st.display();
    st.push(70);
    st.display();
    st.pop();
    st.display();
    st.peek(3);
    cout << "\n" << st.length() << endl;

    return 0;
}
