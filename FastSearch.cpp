#include<iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <stdio.h>
#include <string>
using namespace std;
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    v nums;
    nums.reserve(n);
    for(size_t i = 0; i < n; i++)
    {
        ll e;
        cin >> e;
        nums.pb(e);
    }
    sort(nums.begin(),nums.end());
    int k;
    cin >> k;
    for(size_t i = 0; i < k; i++)
    {
        ll a,b;
        cin >> a >> b;
        int l=-1,h=n;
        while(l+1<h)         // for finding lower bound
        {
            int m = (l+h)/2;
            if(nums[m] < a)
                l = m;
            else
                h = m;
        }
        int lb = h;

        int L=-1,H=n;
        while(L+1<H)        //for finding upper bound
        {
            int M = (L+H)/2;
            if(nums[M] <= b)
                L = M;
            else
                H = M;
        }
        int ub = L+1;
        cout << ub-lb << " ";

        // auto lb = lower_bound(nums.begin(), nums.end(), a);
        // auto ub = upper_bound(nums.begin(),nums.end(),b);
        // cout << ub-lb << " " ;

    }
    return 0;
}