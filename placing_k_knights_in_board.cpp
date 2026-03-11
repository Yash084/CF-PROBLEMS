#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int n, k;
int pos[10][10];

int dr[8]= {1,2,2,1,-1,-2,-2,-1};
int dc[8]= {2,1,-1,-2,-2,-1,1,2};

bool check(int row, int col)
{
    if(row <0 and row>=n and col<0 and col>=n) return 0; 
	if(pos[row][col] == 1) return 0;
	for(int i=0; i<8; i++)
	{
		int nr = row+dr[i];
		int nc = col+dc[i];
		if(nr>=0 and nr<n and nc>=0 and nc<=n and pos[nr][nc]==1)
			return 0;
	}
	return 1;
}

int rec(int level, int lastx, int lasty)
{
	if(level == k)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(pos[i][j]==0)
					cout<<"."<<"  ";
				else
					cout<<"k"<<"  ";
			}
			cout<<endl;
		}
		cout<<endl<<endl;
		return 1;
	}
	int ans=0;
	for(int row=lastx; row<n; row++)
	{
		for(int col=0; col<n; col++)
		{
			if(row == lastx and col <= lasty) continue;
			if(check(row, col))
			{
				pos[row][col]=1;
				ans+= rec(level+1, row, col);
				pos[row][col]=0;
			}
		}
	}
	return ans;
}

void solve() {
	cin>>n>>k;
	cout<<rec(0, 0, -1)<<endl;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}
