#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;


unordered_map<int ,int>factor;
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

void factorsUsingSieve(int n, vector<int>sieve)
{
    for(int i = 2; i < sieve.size(); i++)
    {
        if(sieve[i] == 1)
        {
            sieve[i] = i;
            for(int j = i; j <= n; j++)
            {
                if(j%i == 0 && !sieve[j])
                {
                    sieve[j] = i;
                }
            }
        }
    }

    
    while(n!=1)
    {
        factor.insert({sieve[n],1});// factor is a globally declared unordered map
        if(auto search = factor.find(sieve[n]); search != factor.end())
        {
            factor[sieve[n]]++;
        }
        else
        {
            factor.insert({sieve[n],1});
        }
        n = n/sieve[n];
    }

    for(auto it = factor.begin(); it != factor.end(); it++)
    {
        cout << it->first << "^" << it->second << " ";
    }

}

int main()
{
    vector<int>sieve(N,1);
    primeSieve(sieve);
    //factorsUsingSieve(50,sieve);
    return 0;
}