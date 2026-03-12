#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'


int n,k;
int arr[1000100];


multiset<int> lo, hi;



void balance()
{
	if(lo.size() > hi.size()+1)
	{
		auto it = prev(lo.end());
		auto val = *it;
		lo.erase(it);
		hi.insert(val);
	}

	if(hi.size() > lo.size())
	{
		auto it = hi.begin();
		auto val = *it;
		hi.erase(it);
		lo.insert(val);
	}
}

void insert(int x)
{
	if(lo.empty() || *prev(lo.end()) > x)
		lo.insert(x);
	else
		hi.insert(x);
	balance();
}

void remove(int x)
{
	if(lo.find(x) != lo.end())
	{
		lo.erase(lo.find(x));
	}
	else if(hi.find(x) != hi.end())
	{
		hi.erase(hi.find(x));
	}
	balance();
}


int getMedian() {
	if(lo.size() == hi.size())
		return *prev(lo.end());
	else
		return *prev(lo.end());
}



void solve() {
	cin>>n>>k;
	for(int i=0; i<n; i++)
		cin>>arr[i];
	for(int i=0; i<n; i++)
	{
		insert(arr[i]);
// 		cout<<"First set after inserting: "<<arr[i]<<endl;
// 		for(auto it:lo)
// 			cout<<it<<" ";
// 		cout<<endl;
// 		cout<<"Second set after inserting: "<<arr[i]<<endl;
// 		for(auto it:hi)
// 			cout<<it<<" ";
// 		cout<<endl;
		if(i>=k)
		{
			remove(arr[i-k]);
// 			cout<<"First set after removing: "<<arr[i-k]<<endl;
// 			for(auto it:lo)
// 				cout<<it<<" ";
// 			cout<<endl;
// 			cout<<"Second set after removing: "<<arr[i-k]<<endl;
// 			for(auto it:hi)
// 				cout<<it<<" ";
// 			cout<<endl;
		}
		if(i>=k-1)
			cout<<getMedian()<<" ";
	}
}


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}
