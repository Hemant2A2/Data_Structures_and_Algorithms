#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class BinarySearchTree
{
private:
    Node *root{nullptr};
public:
    void insert(int x)
    {
        Node *t;
        if( root == nullptr)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            root = t;
        }
        else
        {
            Node *p = root;
            while(p)
            {
                if( p->data == x)
                {
                    return;
                }
                else if(p->data > x)
                {
                    t = p;
                    p = p->lchild;
                }
                else
                {
                    t = p;
                    p = p->rchild;
                }
            }
            p = new Node;
            p->data = x;
            p->lchild = p->rchild = nullptr;
            if( x > t->data)
            {
                t->rchild = p;
            }
            else
            {
                t->lchild = p;
            }
            
        }
    }
    
    Node* search(int key)
    {
        if( root == nullptr)
        {
            return nullptr;
        }
        else
        {
            Node *p = root;
            while(p)
            {   
                if(p->data == key)
                {
                    return p;
                }
                else if(p->data < key)
                {
                    p = p->rchild;
                }
                else
                {
                    p = p->lchild;
                }
            }
            return nullptr;
        }
    }
    
    void erase(int key)                  //To be continuied....
    {
        if( root == nullptr)
        {
            return;
        }
        else
        {
            Node *p = root;
            Node *t;
            while(p)
            {
                if(p->data < key)
                {
                    t = p;
                    p = p->rchild;
                }
                else if(p->data > key)
                {
                    t = p;
                    p = p->lchild;
                }
                else
                {
                    
                    
                }
            }
        }
    }
    
    void Inorder(Node *p)
    {
        if(p)
        {
            Inorder(p->lchild);
            cout << p->data << " " ;
            Inorder(p->rchild);
        }
    }
    void Inorder(){Inorder(root);}
};

int main()
{
    BinarySearchTree bst;
    bst.insert(10);
    bst.Inorder();
    cout << endl;
    bst.insert(32);
    bst.Inorder();
    cout << endl;
    bst.insert(4);
    bst.Inorder();
    cout << endl;
    bst.insert(16);
    bst.Inorder();
    cout << endl;
    bst.insert(12);
    bst.Inorder();
    cout << endl;
    bst.Inorder(bst.search(34));
    cout << endl;
    bst.Inorder(bst.search(12));
    cout << endl;
    
    return 0;
}