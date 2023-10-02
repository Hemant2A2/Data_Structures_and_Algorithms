#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    int height;
    Node *rchild;
};

class AVLTree
{
public:
    Node *root = nullptr;
    int NodeHeight(Node *p)
    {
        int hl , hr;
        hl = (p && p->lchild) ? NodeHeight(p->lchild):0;   //Find a way without recursion
        hr = (p && p->rchild) ? NodeHeight(p->rchild):0;
        
        return (hl > hr) ? hl+1:hr+1;
    }
    
    int BalanceFactor(Node *p)
    {
        int hl , hr;
        hl = (p && p->lchild) ? NodeHeight(p->lchild):0;   //Find a way without recursion
        hr = (p && p->rchild) ? NodeHeight(p->rchild):0;
        
        return hl - hr;
    }
    
    Node* LL_rotation(Node *p , Node *q)
    {
        Node *pl = p->lchild;
        Node *plr = pl->rchild;
        pl->rchild = p;
        p->lchild = plr;
        p->height = NodeHeight(p);
        pl->height = NodeHeight(pl);
        
        if( root == p)
        {
            root = pl;
        }
        else
        {
            if(q->lchild == p)
            {
                q->lchild = pl;
            }
            else
            {
                q->rchild = pl;
            }
        }
        
        return pl;
    }
    
    Node* LR_rotation(Node *p , Node *q)
    {
        Node *pl = p->lchild;
        Node *plr = pl->rchild;
        
        pl->rchild = plr->lchild;
        p->lchild = plr->rchild;
        plr->lchild = pl;
        plr->rchild = p;
        
        pl->height = NodeHeight(pl);
        p->height = NodeHeight(p);
        plr->height = NodeHeight(plr);
        
        if( root == p)
        {
            root = plr;
        }
        else
        {
            if(q->lchild == p)
            {
                q->lchild = plr;
            }
            else
            {
                q->rchild = plr;
            }
        }
        
        return plr;
    }
    
    Node* RR_rotation(Node *p , Node *q)
    {
        // Node *pr = p->rchild;
        // Node *prl = pr->lchild;
        // pr->lchild = p;
        // p->rchild = prl;
        
        // p->height = NodeHeight(p);
        // pr->height = NodeHeight(pr);
        
        // if(root == p)
        // {
        //     root = pr;
        // }
        // else
        // {
        //     if(q->lchild == p)
        //     {
        //         q->lchild = pr;
        //     }
        //     else
        //     {
        //         q->rchild = pr;
        //     }
        // }
        // return pr;
        
        Node *pr = p->rchild;
        
        p->rchild = pr->lchild;
        pr->lchild = p;
        
        p->height = NodeHeight(p);
        pr->height = NodeHeight(pr);
        
        if( root == p)
        {
            root = pr;
        }
        else
        {
            if(q->lchild == p)
            {
                q->lchild = pr;
            }
            else
            {
                q->rchild = pr;
            }
        }
        
        return pr;
    }
    
    Node* RL_rotation(Node *p , Node *q)
    {
        Node *pr = p->rchild;
        Node *prl = pr->lchild;
        
        pr->lchild = prl->rchild;
        p->rchild = prl->lchild;
        prl->lchild = p;
        prl->rchild = pr;
        
        p->height = NodeHeight(p);
        pr->height = NodeHeight(pr);
        prl->height = NodeHeight(prl);
        
        if( root == p)
        {
            root = prl;
        }
        else
        {
            if(q->lchild == p)
            {
                q->lchild = prl;
            }
            else
            {
                q->rchild = prl;
            }
        }
        
        return prl;
    }
    
    void insert(int x)
    {
        Node *t;
        if( root == nullptr)
        {
            t = new Node;
            t->data = x;
            t->height = 1;
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
            p->height = NodeHeight(p);
        }
        Node *r = root;
        Node *q = nullptr;
        r->height = NodeHeight(root);
        while(r)
        {    
            if(BalanceFactor(r) == 2 && BalanceFactor(r->lchild) == 1)
            {
                r = LL_rotation(r , q);
            }
            else if(BalanceFactor(r) == 2 && BalanceFactor(r->lchild) == -1)
            {
                r = LR_rotation(r , q);
            }
            else if(BalanceFactor(r) == -2 && BalanceFactor(r->rchild) == -1)
            {
                r = RR_rotation(r , q);
            }
            else if(BalanceFactor(r) == -2 && BalanceFactor(r->rchild) == 1)
            {
                r = RL_rotation(r , q);
            }
            else if( BalanceFactor(r) < 0)
            {
                q = r;
                r = r->rchild;
            }
            else if( BalanceFactor(r) > 0)
            {
                q = r;
                r = r->lchild;
            }
            else if( BalanceFactor(r) == 0)
            {
                r = nullptr;
            }
        }
    }
    
    void Inorder(Node *p)
    {
        if(p)                         //using recursion
        {
            Inorder(p->lchild);
            cout << p->data << " ";
            Inorder(p->rchild);
        }
    }
    
    void Preorder(Node *p)
    {
        if(p)                         // using recursion
        {
            cout << p->data << " " ;
            Preorder(p->lchild);
            Preorder(p->rchild);
        }
    }
};

int main() {
    
    AVLTree avl;
    avl.insert(3);
    avl.insert(1);
    avl.insert(5);
    avl.insert(2);
    avl.insert(7);
    avl.insert(4);
    avl.insert(8);
    avl.insert(12);
    // avl.RR_rotation(avl.root->rchild->rchild , avl.root->rchild);
    avl.insert(10);
    // avl.RR_rotation(avl.root->rchild, avl.root);
    avl.insert(6);
    // avl.RL_rotation(avl.root , nullptr);
    avl.insert(9);
    // avl.LL_rotation(avl.root->rchild->rchild, avl.root->rchild);
    avl.insert(11);
    
    avl.Inorder(avl.root);
    cout << endl;
    avl.Preorder(avl.root);
	

	return 0;
}