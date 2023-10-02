#include <iostream>

using namespace std;

class Circ_Queue
{
private:
    int size;
    int f,r;
    int *cq;
    
public: 
    Circ_Queue(int size)
    {
        cout << "Constructor called" << endl;
        this->size = size;
        f = r = 0;
        cq = new int[size + 1];
        int n;
        cout << "Enter the number of elements:";
        cin >> n;
        int e;
        cout << "\nEnter the elements:" << endl;
        for( int i{1}; i <= n; i++)
        {
            cin >> e;
            r = i;
            cq[i] = e;
        }
    }
    
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
    
    int length()
    {
        int l{0};
        if( r > f)
        {
            for( int i{f + 1}; i <=r; i++)
            {
                l++;
            }
            return l;
        }
        else if( r < f)
        {
            if( f != size)
            {
                for( int i{f + 1}; i <= size ; i++)
                {
                    l++;
                }
                for(int i{0}; i <=r; i++)
                {
                    l++;
                }
                return l;
            }
            else
            {
                for(int i{0}; i <=r; i++)
                {
                    l++;
                }
                return l;
            }
        }
        else
        {
            return l;
        }
    }
    
    void display()
    {
        if( is_empty() == false)
        {
            cout << "\nDisplaying the queue...." << endl;
            if( r > f)
            {
                for( int i{f + 1} ; i <= r; i++)
                {
                    cout << cq[i] << " ";
                }
                cout << endl;
            }
            else
            {
                if( f == size)
                {
                    for( int i{0}; i <= r; i++)
                    {
                        cout << cq[i] << " ";
                    }
                    cout << endl;
                }
                else
                {
                    for( int i{f + 1}; i <= size ; i++)
                    {
                        cout << cq[i] << " ";
                    }
                    for(int i{0}; i <=r; i++)
                    {
                        cout << cq[i] << " ";
                    }
                    cout << endl;
                }
            }
        }
        else
        {
            cout << "\nQueue is EMPTY!!!" << endl;
        }
    }
    
    void enqueue(int x)
    {
        if( is_full() == false)
        {
            r = (r + 1) % (size + 1);
            cq[r] = x;
        }
        else
        {
            cout << "\nQueue is FULL!!!" << endl;
        }
    }
    
    void dequeue()
    {
        if( is_empty() == false)
        {
            f = (f + 1) % (size + 1);
        }
        else
        {
            cout << "\nQueue is EMPTY!!!" << endl;
        }
    }
    
    ~Circ_Queue()
    {
        cout << "\nDestructor called" << endl;
        delete []cq;
    }
};

int main()
{
    Circ_Queue line{10};
    line.display();
    line.dequeue();
    line.display();
    line.enqueue(10);
    line.display();
    line.enqueue(11);
    line.display();
    line.enqueue(12);
    line.display();

    return 0;
}