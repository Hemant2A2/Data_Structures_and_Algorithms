//Sorting Methods....
#include <iostream>

using namespace std;

void Swap(int &a , int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int A[], int n)
{
    for( int i{0}; i < n -1 ; i++)
    {
        int flag{0};
        for( int j{0}; j < n-1-i; j++)
        {
            if(A[j] > A[j+1])
            {
                Swap(A[j], A[j+1]);
                flag = 1;
            }
        }
        if( flag == 1)
        {
            continue;
        }
        else
        {
            break;
        }
    }
}

void InsertionSort(int A[], int n)
{
    for( int i{1}; i<n; i++)
    {
        int x = A[i];
        int j = i-1;
        while( j >= 0 && A[j] > x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

void SelectionSort(int A[], int n)
{
    int i,j,k;
    for(i=0; i < n-1;i++)
    {
        for(j = k = i; j < n; j++)
        {
            if( A[j] < A[k])
            {
                k = j;
            }
        }
        Swap(A[k], A[i]);
    }
}

int partition(int A[], int l, int h) //for quick sort
{
    int i{l}, j{h};
    int pivot = A[l];
    do
    {
        do{i++;}while(A[i] <= pivot);
        do{j--;}while(A[j] > pivot);
        if( i < j)
        {
            Swap(A[i], A[j]);
        }
    }while(i<j);
    Swap(A[l], A[j]);
    return j;
}

void QuickSort(int A[], int l , int h)
{
    int j;
    if(l < h)
    {
        j = partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);
    }
}

void Merge(int A[], int l , int mid , int h)
{
    int i{0},j{mid + 1},k{0};
    int B[h + 1];
    while( i <= mid && j <= h)
    {
        if(A[i] < A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    for(i; i <= mid ; i++)
    {
        B[k++] = A[i];
    }
    for(j; j <=h; j++)
    {
        B[k++] = A[j];
    }
    
    for(int i{0}; i <= h; i++)
    {
        A[i] = B[i];
    }
}

void MergeSort(int A[],int n)
{
    int p,i,l,mid,h;
    for(p = 2; p <= n; p *=2)
    {
        for( i=0; i+p-1 < n; i +=p)
        {
            l = i;
            h = i + p -1;
            mid = (l + h)/2;
            Merge(A,l,mid,h);
        }
        if( n- i > p/2)
        {
            l = i;
            h = i+p-1;
            mid = (l + h)/2;
            Merge(A,l,mid,n-1);
        }
    }
    if( p/2 < n)
    {
        Merge(A,0,p/2 - 1, n-1);
    }
}

void CountSort(int A[], int n)
{
    int i,j,max, *H;
    max = A[0];
    for( i = 1;i < n; i++)
    {
        if( A[i] > max)
        {
            max = A[i];
        }
    }
    H = new int [max + 1];
    for( i = 0 ; i <= max; i++)
    {
        H[i] = 0;
    }
    for( i = 0; i < n; i++)
    {
        H[A[i]]++;
    }
    i = j = 0;
    while(i <= max)
    {
        if( H[i] > 0)
        {
            A[j++] = i++;
        }
        else
        {
            i++;
        }
    }
    
}

void ShellSort()
{
    //to be continued....
}

void display(int A[], int n)
{
    for( int i{0}; i<n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main()
{
    // int A[] = {3,1,5,2,7,4,8,12,10,6,9,11,32767};
    // QuickSort(A,0,12);
    int A[] = {3,1,5,2,7,4,8,12,10,6,9,11};
    CountSort(A,12);
    display(A,12);

    return 0;
}