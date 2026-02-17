// Problem: Dynamic Top-K Sum
// Maintain a DS with insert, delete, and query operations.
// Query returns the sum of the k largest elements at any time.



#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

struct bag
{

	int k;
	int sumk;

	multiset<int> mt1,mt2;

	void init(int _k)
	{
		k = _k;
		sumk=0;
		mt1.clear();
		mt2.clear();
	}

	void insert(int x)
	{
		mt1.insert(x);
		sumk+=x;
		if(mt1.size() > k)
		{
			auto it = mt1.begin();
			auto val = *it;
			sumk-=val;
			mt1.erase(it);
			mt2.insert(val);
		}
	}

	void remove(int x)
	{
		if(mt1.find(x)!=mt1.end())
		{
			mt1.erase(mt1.find(x));
			sumk-=x;
		}
		else if(mt2.find(x) != mt2.end())
		{
			mt2.erase(mt2.find(x));
		}
		if(mt1.size() < k and mt2.empty() == false)
		{
			auto it = mt2.rbegin();
			mt1.insert(*it);
			sumk+=*it;
			mt2.erase(mt2.find(*it));
		}
	}

	int topK()
	{
		return sumk;
	}
};

void solve()
{
	int q,k;
	cin>>q>>k;
	bag b;
	b.init(k);
	while(q--)
	{
		int lq;
		cin>>lq;
		if(lq == 1)
		{
			int x;
			cin>>x;
			b.insert(x);
		}
		else if(lq == 2)
		{
			int x;
			cin>>x;
			b.remove(x);
		}
		else
		{
			string s;
			cin>>s;
			cout<<b.topK()<<endl;
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t=1;
	// cin>>t;
	while(t--)
	{
		solve();
	}
}
