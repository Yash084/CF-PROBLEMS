#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long


void solve()
{
    int n=4;
    int arr[4] = {4,2,3,1};
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i] > arr[j])
            {
                ans+= (i+1) * (n-j);
            }
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
