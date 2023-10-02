#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
};

class Queue
{
private:
    int f{0},r{0};
    Node* *cq;
    
public:
    int size{100};
    Node *a;
    bool is_empty()
    {
        if( f == r )
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
        if( (r + 1) % (size + 1) == f)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    
    void enqueue(Node *x)
    {
        if(is_empty() == true)
        {
            f = r = 0;
            cq = new Node*[size + 1];
        }
        if( is_full() == false)
        {
            r = (r + 1) % (size + 1);
            cq[r] = x;
        }
    }
    
    Node* dequeue()
    {
        f = (f + 1) % (size + 1);
        a = cq[f];
        return a;
    }
    
    ~Queue(){delete []cq;}
};

class  stack 
{
private:
    
    int top{-1};
    Node* *s;
    
public:
    int size{100};
    Node *a;
    bool isEmpty()
    {
        if( top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void push(Node *x)
    {
        if( top == -1)
        {
            s = new Node*[size];
        }
        top++;
        s[top] = x;
    }
    
    Node* pop()
    {
        a = s[top];
        top--;
        return a;
    }

    ~stack(){delete [] s;}
};

class Tree
{
public:
    Node *root;
    Tree()
    {
        root = nullptr;
    }
    
    void createTree()
    {
        Node *p,*t;
        int x;
        Queue q;
        cout << "Enter root value:";
        cin >> x;
        root = new Node;
        root->data = x;
        root->lchild = root->rchild = nullptr;
        q.enqueue(root);
        while( q.is_empty() == false)
        {
            p = q.dequeue();
            cout << "\nEnter the left child of " << p->data << ":" ;
            cin >> x;
            if( x != -1)
            {
                t = new Node;
                t->data = x;
                t->lchild = t->rchild = nullptr;
                p->lchild = t;
                q.enqueue(t);
            }
            cout << "\nEnter the right child of " << p->data << ":" ;
            cin >> x;
            if( x != -1)
            {
                t = new Node;
                t->data = x;
                t->lchild = t->rchild = nullptr;
                p->rchild = t;
                q.enqueue(t);
            }
            
        }
    }
    
    void Preorder(Node *p)
    {
        // if(p)                         // using recursion
        // {
        //     cout << p->data << " " ;
        //     Preorder(p->lchild);
        //     Preorder(p->rchild);
        // }
        
        stack st;                       //using iteration
        while( p || !st.isEmpty())
        {
            if(p)
            {
                cout << p->data << " ";
                st.push(p);
                p = p->lchild;
            }
            else
            {
                p = st.pop();
                p = p->rchild;
            }
        }
    }
    
    void Inorder(Node *p)
    {
        // if(p)                         //using recursion
        // {
        //     Inorder(p->lchild);
        //     cout << p->data << " ";
        //     Inorder(p->rchild);
        // }
        
        stack st;                       //using iteration
        while( p || !st.isEmpty())
        {
            if(p)
            {
                st.push(p);
                p = p->lchild;
            }
            else
            {
                p = st.pop();
                cout << p->data << " ";
                p = p->rchild;
            }
        }
        
    }
    
    void Postorder(Node *p)
    {
        // if(p)                        //using recursion
        // {
        //     Postorder(p->lchild);
        //     Postorder(p->rchild);
        //     cout << p->data << " ";
        // }
        
        stack st;                           //using iteration
        long long  int temp;
        while( p || !st.isEmpty())
        {
            if(p)
            {
                st.push(p);
                p = p->lchild;
            }
            else
            {
                temp = (long long int)st.pop();
                if( temp > 0)
                {
                    st.push((Node*)(-temp));
                    p = ((Node*) (-temp))->rchild;
                }
                else
                {
                    cout << ((Node*) temp)->rchild << " " ;
                }
                
            }
        }
    }
    
    void LevelOrder(Node *root)
    {
        Queue q;
        cout << root->data << " ";
        q.enqueue(root);
        while( q.is_empty() == false)
        {
            root = q.dequeue();
            if(root->lchild)
            {
                cout << root->lchild->data << " ";
                q.enqueue(root->lchild);
            }
            if(root->rchild)
            {
                cout << root->rchild->data << " ";
                q.enqueue(root->rchild);
            }
        }
    }
    
    int Height(Node *root)
    {
        int x{0}, y{0};
        if( root = nullptr)
        {
            return 0;
        }
        x = Height(root->lchild);
        y = Height(root->rchild);
        if( x > y)
        {
            return x+1;
        }
        else
        {
            return y+1;
        }
    }
    
    ~Tree()
    {
        delete root;
    }
};

int main()
{
    Tree t;
    t.createTree();
    cout << "\nPreorder: ";
    t.Preorder(t.root);
    cout << "\nInorder: ";
    t.Inorder(t.root);
    cout << "\nPostorder: ";
    // t.Postorder(t.root);    //NOT WORKING..

    return 0;
}