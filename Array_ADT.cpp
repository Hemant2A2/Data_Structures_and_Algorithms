
#include <iostream>

using namespace std;

class  Array
{
    private:
    
    int *A;
    int size;
    int length;
    
    public:
    
    Array(int size)
    {
        this->size = size;
        A = new int [size];
        cout << "Constructor Called" << endl;
    }
    
    void create()
    {
        cout << "Enter the number of elements:";
        cin >> length;
        cout << "\nEnter the array elements:"<< endl;
        for( int i = 0; i < length; i++)
        {
            cin >> A[i];
            cout << endl;
        }
    }
    
    void display()
    {
        for( int i =0; i < length ; i++)
        {
            cout << A[i] << " " ;
        }
    }
    
    void add( int x)
    {
        if( length < size)
        {
            A[length] = x;
            length++;
        }
        else
        {
            cout << "\nNo space available to add" << endl;
        }
    }
    
    void insert(int n , int x)
    {
        if( (length < size) && (n >=0) && (n <= length))
        {
            for( int i=length; i > n; i--)
            {
                A[i] = A[i-1];
                
            }
            A[n] = x;
            length++;
        }
        else
        {
            cout << "\nCan't insert" << endl;
        }
    }
    
    void erase(int del)
    {
        if( del >= 0 && del < length)
        {
            length--;
            for( int i=del; i < length; i++)
            {
            A[i] = A[i+1];
            }
        }
        else
        {
            cout << "Cannot delete" << endl;
        }
    }
    
    void search(int key)
    {
        for(int i=0; i < length; i++)
        {
            if(A[i] == key)
            {
                cout << key << " was found on index " << i <<endl;
                break;
            }
            else if( i == length -1)
            {
                cout << key << " was not found" <<endl;
            }
            
        }
    }
    
    void binary_search(int key)                           //not working..
    {
        int l=0;
        int h=length -1;
        int mid = (l+h)/2;
        
        do
        {
            if( key > A[mid])
            {
                l = mid +1;
                mid = (l+h)/2;
            }
            else if( key < A[mid])
            {
                h = mid - 1;
                mid = (l+h)/2;
            }
            
            
        }
        while( key != A[mid] || l != h);
        if(key == A[mid])
        {
            cout << key << " was found at index " << mid << endl;
        }
        else if((A[l] != A[h]) && (l == h))
        {
            cout << key << " was not found " << endl;
        }
        
    }
    
    void reverse()
    {
        for( int i=0,  j=(length -1); i < j; i++ , j--)
        {
            swap(A[i] , A[j]);
        }
        
    }
    
    void insert_sorted(int n)
    {
        if( length < size)
        {
            int i= length -1;
            while(n < A[i])
            {
                A[i+1] = A[i];
                i--;
            }
            A[i+1] = n;
            length++;
        }
        else
        {
            cout << "\nCan't insert" << endl;
        }
    }
    
    bool is_sorted()
    {
        int t=0 , f=0;
        for( int i=0; i < length -1; i++)
        {
            if( A[i] < A[i+1])
            {
                t++;
            }
            else
            {
                f++;
            }
        }
        if(f == 0)
        {
            return true;
        }
        else
        {
             return false;
        }
        
            
        
    }
    
    void Sort()
    {
        if( is_sorted() == false)
        {
            do
            {
                for( int i=0; i < length - 1; i++)
                {
                    if(A[i+1] < A[i])
                    {
                        swap(A[i+1], A[i]);
                    }
                }
            }
             while( is_sorted() == false);
        }
        else
        {
            cout << "\nThe array was already sorted." << endl;
        }
    }
    
    ~Array()
    {
        delete [] A;
        cout << "\nDestructor called" << endl;
    }
    
    
};

void swap(int &x , int &y);

int main()
{
    
    Array arr(10);
    arr.create();
    cout << "Displaying the elements:" << endl;
    arr.display();
    // int val;
    // cout << "\nEnter the value to add :" << endl;
    // cin >> val;
    // arr.add(val);
    // cout << "\nDisplaying the elements:" << endl;
    // arr.display();
    // int n , i;
    // cout << "\nEnter the index and value you wish to insert:";
    // cin >> n >> i;
    // arr.insert(n , i);
    // cout << "\nDisplaying the elements:" << endl;
    // arr.display();
    // int del;
    // cout << "\nEnter the index to delete:" << endl;
    // cin >> del;
    // arr.erase(del);
    // cout << "\nDisplaying the elements:" << endl;
    // arr.display();
    // int key;
    // cout << "\nEnter the value to search:" << endl;
    // cin >> key;
    // arr.search(key);
    // arr.binary_search(key);
    // cout << "\nReversing the elements...." << endl;
    // arr.reverse();
    // cout << "\nDisplaying the elements:" << endl;
    // arr.display();
    // int n;
    // cout << "\nEnter the value to insert:" << endl;
    // cin >> n;
    // arr.insert_sorted(n);
    // cout << "\nDisplaying the elements:" << endl;
    // arr.display();
    // arr.is_sorted() 
    cout << "\nSorting the array...." << endl;
    arr.Sort();
    cout << "\nDisplaying the elements:" << endl;
    arr.display();
    
    
    
	    
	    
	    
	    
    
    
    return 0;
}

void swap(int &x , int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

