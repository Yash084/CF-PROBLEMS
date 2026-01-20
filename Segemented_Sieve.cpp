#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'


// segemented sieve
// Used to find primes in range a to b where b <= 1e12
// If a number x is not prime then it will be having its prime divisors till sqrt(x)
// we will find all primes till sqrt(b) in basePrime array
// we will iterate over the basePrime array and mark all it's prime multiples in prime array
// as if a number is not prime it will be having a prime factor before sqrt(number)



// used to create basePrime array
vector<int> sieve(int rootB)
{
	vector<int> sieve(rootB, 1);
	sieve[0]=sieve[1]=0;
	for(int i=2; i<rootB; i++)
	{
		if(sieve[i])
		{
			for(int j=2*i; j<rootB; j+=i)
			{
				sieve[j]=0;
			}
		}
	}
	return sieve;
}

void solve()
{
	int a,b;
	cin>>a>>b;
	// mark primes from 0 to sqrt(b)
	vector<int> basePrime = sieve (ceil(sqrt(b)) + 1);
	// create solution array with 0 as a, 1 as a+1 ....... b-a+1 as b
	vector<int> primes(b-a+1, 1);
	for(int i=0; i<basePrime.size(); i++)
	{
		if(basePrime[i] == 1)
		{
			int nextMultiple = ((a + i - 1)/i) * i;
			while(nextMultiple <= b)
			{
				if(nextMultiple != i)
					primes[nextMultiple - a] = 0;
				nextMultiple += i;
			}
		}
	}
	for(int i=0; i<primes.size(); i++)
	{
		cout<<"Element: "<<i+a<<" is: "<< (primes[i] ? "is prime" : "is not prime")<<endl;
	}
}


signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t = 1;
// 	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
