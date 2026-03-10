#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long


string s;

string path="";

bool vis[10][10];

int dx[4]= {-1,1,0,0};
int dy[4]= {0,0,1,-1};


// check if row, col is inbound and move we are making at that step is correct or not.
bool check(int row, int col, int steps, char c)
{
	if(row>=1 and row<=7 and col<=7 and col>=1 and vis[row][col]==0 and (s[steps] == '?' || s[steps] == c))
		return 1;
	return 0;
}

// get the move based on del values
char getMove(int row, int col)
{
	if(row == -1 and col==0)
		return 'U';
	else if(row == 1 and col == 0)
		return 'D';
	else if(row == 0 and col == -1)
		return 'L';
	return 'R';
}


int rec(int row, int col, int steps)
{
	if((row == 7 and col == 1) || steps == 48)
	{
		// all should satisfy else 0
		if(steps == 48 and row == 7 and col == 1)
			return 1;
		return 0;
	}

// PRUNING: detect grid split trap
// If both vertical neighbors are free but both horizontal neighbors are blocked,
// the path would split the grid into two disconnected regions.
// Example:
//
//   # . #
//   # X #
//   # . #
//
// X = current cell
// # = visited
// . = unvisited
//
// From here we must go up or down, which splits the grid into two parts
// that can no longer be connected by a simple path.
// Therefore this branch cannot lead to a valid solution.
	if((vis[row+1][col] == 0 and vis[row-1][col] == 0 and vis[row][col-1]!=0 and vis[row][col+1]!=0) ||
	        (vis[row][col+1]==0 and vis[row][col-1]==0 and vis[row+1][col]!=0 and vis[row-1][col]!=0))
		return 0;

	int ans=0;

	for(int i=0; i<4; i++)
	{
		int nr = row+dx[i];
		int nc = col+dy[i];
		char move = getMove(dx[i], dy[i]);
		if(check(nr, nc, steps, move))
		{
			vis[nr][nc]=1;
			path.push_back(move);
			ans+= rec(nr, nc, steps+1);
			path.pop_back();
			vis[nr][nc]=0;
		}
	}
	return ans;
}

void solve() {
	cin>>s;
	// to use 1 based indexing..
	for(int i=0; i<9; i++)
	{
		vis[0][i]=vis[8][i]=1;
		vis[i][0]=vis[i][8]=1;
	}
	// mark the initial cell
	vis[1][1]=1;
	cout<<rec(1, 1, 0)<<endl;
}


signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
}
