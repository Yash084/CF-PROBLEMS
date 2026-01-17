#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define MAXN 1000100

const int MOD = 1e9+7;


int sieve[MAXN+1];
int spf[MAXN+1];

void pre()
{
    for(int i=2;i<=MAXN;i++)
    {
        sieve[i]=1;
    }
    sieve[0] = sieve[1] = 0;
    for(int i=2;i<=MAXN;i++)
    {
        if(sieve[i]==1)
        {
            for(int j=2*i;j<=MAXN;j+=i)
            {
                sieve[j]=0;
            }
        }
    }
    
    for(int i=2;i<=MAXN;i++)
    {
        spf[i]=i;
    }
    spf[0] = 0;
    spf[1] = 1;
    for(int i=2;i<=MAXN;i++)
    {
        if(spf[i]==i)
        {
            // if i is prime mark all its multiple spf as i
            for(int j=2*i;j<=MAXN;j+=i)
            {
                if(spf[j]==j)
                  spf[j]=i;
            }
        }
    }
}

void divisors(int x)
{
    while(x!=1)
    {
        cout<<spf[x]<<endl;
        x=x/spf[x];
    }
}


int gcd(int a, int b)
{
    if(b==0) return a;
    else return gcd(b, a%b);
}

int lcm(int a, int b)
{
    return (a/gcd(a,b))*b;
}

// void divisors(int x)
// {
//     for(int i=1;i*i<=x;i++)
//     {
//         if(x%i == 0)
//         {
//             cout<<i<<endl;
//             if(x/i != i)
//               cout<<x/i<<endl;
//         }
//     }
// }

void primeDivisors(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i == 0)
        {
            int expo = 0;
            while(x%i == 0)
            {
                x=x/i;
                expo++;
            }
            cout<<i<<" "<<expo<<endl;
        }
    }
    if(x>1)
     cout<<x<<" "<<1<<endl;
}




signed main(){
    pre();
    divisors(90);
}
