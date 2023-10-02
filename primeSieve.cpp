#include<iostream>
#include <vector>
using namespace std;
#define  N  1000000
#define ll long long

void primeSieve(vector<int>&sieve)
{
    sieve[1] = sieve[0] = 0;

    for(ll i = 0; i < N; i++)
    {
        if(sieve[i])
        {
            for(ll j = i*i; j < N; j = j+i)
            {
                sieve[j] = 0;
            }
        }
    }
}


int main()
{

    vector<int> sieve(N,1);
    primeSieve(sieve);
    for(int i = 0; i < 100; i++)
    {
        if(sieve[i])
            cout << i << " ";
    }
    return 0;
}