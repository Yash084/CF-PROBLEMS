#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long


void solve()
{
    int n=4;
    int arr[4] = {1,2,3,4};
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int temp=1;
        for(int j=i;j<n;j++)
        {
           temp = temp*arr[j];
           ans+=temp;
        }
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int t=1;
    // cin>>t;
    while(t--)
      solve();
}
