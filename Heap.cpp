//MAX HEAP......
#include <iostream>

using namespace std;

void insert(int A[], int n)
{
    int i = n , temp;
    temp = A[i];
    
    while( i > 1 && temp > A[i/2])
    {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

void createHeap(int A[], int n)
{
    for( int i{2}; i <= n ; i++)
    {
        insert(A,i);
    }
}

void Heapify(int A[], int n)
{
    //to be continued....
}

int Delete(int A[], int n)
{
    int i,j,x,val,temp;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = i*2;
    
    while( j < n-1)
    {
        if( A[j+1] > A[j])
        {
            j = j + 1;
        }
        if( A[i] < A[j])
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = j*2;
        }
        else
        {
            break;
        }
    }
    return val;
}

void HeapSort(int A[], int n)
{
    for(int i{n}; i > 1 ; i--)
    {
        Delete(A , i);
    }
}

void display(int A[])
{
    for( int i{1}; i < 8; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    int H[] = {0,10,20,30,25,5,40,35};
    
    display(H);
    HeapSort(H,7);
    display(H);
    
    
    

    return 0;
}