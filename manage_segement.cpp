#include<bits/stdc++.h>
using namespace std;
#define int long long

struct bag {

	set<pair<int, int>> st;


	void insert(int l, int r) {

		// Check if l can be submerged
		auto it = st.upper_bound({l, 1e9});
		if (it != st.begin()) {
			it--;
			if (it->second >= l) {
				l = it->first;
				r = max(r, it->second);
				st.erase(it);
			}
		}

		// Check if r can be submerged
		it = st.upper_bound({r, 1e9});
		if (it != st.begin()) {
			it--;
			if (it->second >= r) {
				l = min(l, it->first);
				r = it->second;
				st.erase(it);
			}
		}

		// Erase all the middle ones
		while (1) {
			it = st.upper_bound({l, 0});
			if (it == st.end() || it->second >= r)
				break;
			else
				st.erase(it);
		}
		st.insert({l, r});
	}

	void deleteRangeInIntervals(int l, int r)
	{
		auto it = st.upper_bound({l,1e9});
		if(it != st.begin())
		{
			it--;
			if(it->second >= r)
			{
				int lo1=it->first;
				int hi1=r;

				int lo2=r;
				int hi2=it->second;

				st.erase(it);
				st.insert({lo1,h1});
				st.insert({lo2,hi2});
				return;
			}
			if(it->second >= l)
			{
				int lo1=it->first;
				int hi1=l;
				st.erase(it);
				st.insert({lo1, hi1});
			}
		}

		it = st.upper_bound({r,1e9});
		if(it != st.begin())
		{
			it--;
			if(it->second >= r)
			{
				int lo1=r;
				int hi1=it->second;
				st.erase(it);
				st.insert({lo1, hi1});
			}
		}

		while (1) {
			it = st.lower_bound({l, 0});
			if (it == st.end() || it->first >= r)
				break;
			else
				st.erase(it);
		}
	}


	bool checkRangePortionLiesInIntervals(int l, int r)
	{
		// check for segement starts after l
		auto it = st.upper_bound({l, 1e9});
		if(it != st.end())
		{
			it--;
			// check if it also starts before r
			if(it -> first <= r)
				return 1;
		}
		// check if x is a part of any interval
		return checkPointInIntervals(l);
	}

	bool checkRangeAllLiesInIntervals(int l, int r)
	{
		// check for segement starts after l
		auto it = st.upper_bound({l, 1e9});
		if(it != st.begin())
		{
			it--;
			// come to segement start with l or less and check if it ends after r
			if(it->second >= r)
				return 1;
		}
		return 0;
	}

	bool checkPointInIntervals(int x)
	{
		// check segement after x
		auto it = st.upper_bound({x, 1e9});
		if(it != st.begin())
		{
			it--;
			// check if x is covered in previous segement
			if(it -> second >= x)
				return 1;
		}
		return 0;
	}

	void print()
	{
		for(auto it: st)
			cout<<"("<<it.first<<","<<it.second<<")"<<endl;
	}
};


signed main()
{
	int n;
	cin>>n;
	bag b;
	for(int i=0; i<n; i++)
	{
		int l,r;
		cin>>l>>r;
		b.insert(l,r);
		cout<<"After inserting "<<l<<" and "<<r<<endl;
		b.print();
	}
	int l,r;
	cin>>l>>r;
	b.deleteRangeInIntervals(l,r);
	cout<<"After deleting "<<l<<" and "<<r<<endl;
	b.print();

}
