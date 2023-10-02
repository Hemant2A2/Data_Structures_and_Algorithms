#include <iostream>

using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *q;
    
public:
    Queue(int size)
    {
        this->size = size;
        cout << "Constructor called..." << endl;
        front = rear = -1;
        q = new int[size];
        int n;
        cout << "\nEnter the number of elements:";
        cin >> n;
        int e;
        cout << "\nEnter the elements:" << endl;
        for(int i{0}; i < n; i++)
        {
            cin >> e;
            front = 0;
            rear = i;
            q[i] = e;
        }
    }
    
    bool is_empty()
    {
        if( front == -1)
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
        if(rear == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    void display()
    {
        if( is_empty() == false)
        {    
            cout << "\nDisplaying the queue......" << endl;
            for( int i{front}; i <= rear; i++)
            {
                cout << q[i] << " " ;
            }
            cout << endl;
        }
        
    }
    
    int length()
    {
        int l{0};
        for( int i{front}; i <= rear; i++)
        {
            l++;
        }
        return l;
    }
    
    void enqueue(int x)
    {
        if( is_full() == false)
        {
            q[rear + 1] = x;
            rear++;
        }
        else
        {
            cout << "\nQueue is FULL!!!" << endl;
        }
    }
    
    void dequeue()
    {
        if(is_empty() == false)
        {
            front++;
            size++;
        }
        else
        {
            cout << "\nQueue is EMPTY!!!" << endl;
        }
    }
    
    ~Queue()
    {
        delete [] q;
        cout << "\nDestructor called" << endl;
    }
    
};

int main()
{
    Queue line{10};
    line.display();
    line.enqueue(55);
    line.display();
    line.dequeue();
    line.display();
    line.enqueue(68);
    line.display();
    line.enqueue(10);
    line.display();


    return 0;
}