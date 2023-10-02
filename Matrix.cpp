#include<iostream>
#include <cstring>
using namespace std;
const int sz = 2;

class Matrix
{
    public:
        long long M[sz][sz];
    
        Matrix()
        {
            memset(M,0,sizeof(M)); // initializes all elements to 0 , under header file <cstring>
        }

        void identity()
        {
            for(int i = 0; i < sz; i++)
            {
                M[i][i] = 1;
            }
        }

        Matrix friend operator*(Matrix &a, Matrix &b)
        {
            Matrix mul;
            for(int i = 0; i < sz; i++)
            {
                for(int j = 0; j < sz; j++)
                {
                    for(int k = 0; k < sz; k++)
                    {
                        mul.M[i][j] += a.M[i][k] * b.M[k][j];
                    }
                }
            }
            return mul;
        }

        Matrix friend operator^(Matrix &T,long long n)
        {
            Matrix ans;
            ans.identity();
            while(n)
            {
                if(n&1)
                    ans = ans*T;
                T = T*T;
                n >>=1;
            }

            return ans;
        }


};

long long your_function(long n)
{
    
}

int main()
{
    
    return 0;
}




