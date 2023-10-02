

#include <iostream>

using namespace std;

class  stack 
{
private:
    int size;
    int top;
    int *s;
    
public:
    stack(int size)
    {
        cout << "Constructor called" << endl;
        this->size = size;
        top = -1;
        s = new int[size];
        cout << "\nEnter the number of elements:" ;
        int n;
        cin >> n;
        cout << "\nEnter the elements:" << endl;
        int e;
        for( int i{0}; i < n;i++)
        {
            cin >> e;
            if(i < size)
            {    s[i] = e;
                top = i;
            } 
            else
            {
                cout << "\nStack OverFlow!!!" << endl;
                cout << "Cannot insert more elements!!" << endl;
                break;
            }
        }
    }
    
    void display()
    {
        cout << "\nDisplaying the elements...." << endl;
        if( top == -1)
        {
            cout << "\nStack is EMPTY!!" << endl;
        }
        else
        {
            for( int i{top}; i >=0 ; i--)
            {
                cout << "\n          " << s[i] ;
            }
        }
    }
    
    void push(int x)
    {
        if(top == size-1)
        {
            cout << "\nStack OverFlow!!!" << endl;
            cout << "Cannot insert more elements!!" << endl;
        }
        else
        {
            top++;
            s[top] = x;
        }
    }
    
    void pop()
    {
        if( top != -1)
        {
            top--;
        }
        else
        {
            cout << "\nStack is EMPTY!!" << endl;
        }
    }
    
    void peek(int pos)
    {
        if( top != -1 && pos > 0 && pos <= top + 1)
        {
            cout << "\n" << s[top - pos + 1] << endl;
        }
    }
    ~stack()
    {
        cout << "\nDestructor called" << endl;
        delete [] s;
    }
};
int main()
{
    stack st{10};
    st.display();
    st.push(8);
    st.display();
    st.pop();
    st.display();
    st.peek(2);
    

    return 0;
}
