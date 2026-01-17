#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'



int binpow(int a, int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)
		{
			ans = ans * a;
		}
		a = a * a;
		b = b >> 1;
	}
	return ans;
}


	int fact[11];
void pre()
{
	fact[0] = fact[1] = 1;
	for(int i=2; i<11; i++)
	{
		fact[i] = i * fact[i-1];
	}
}


int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] / (fact[r] * fact[n - r]);
}


void solve()
{
	string s,t;
	cin>>s>>t;
	int sPlus=0;
	int sMinus = 0;
	int n = s.length();
	for(int i=0; i<n; i++)
	{
		if(s[i] == '+')
			sPlus++;
		else
			sMinus++;
	}

	int tPlus=0;
	int tMinus=0;
	int qMark =0;
	for(int i=0; i<n; i++)
	{
		if(t[i] == '+')
			tPlus++;
		else if(t[i] == '-')
			tMinus++;
		else
			qMark++;
	}
	double ans;
	if(tPlus > sPlus || tMinus > sMinus)
	{
		ans = 0;

	}
	else if(tMinus == sMinus and tPlus == sPlus)
	{
		ans = 1;
	}
	else
	{
		int plusDiff = sPlus - tPlus;
		int totalPossibilities = binpow(2, qMark);
		ans = (double) nCr(qMark, plusDiff) / (double)totalPossibilities ;
	}
	cout<<fixed<<setprecision(9)<<ans<<endl;
}



signed main()
{
    pre();
	solve();
}
