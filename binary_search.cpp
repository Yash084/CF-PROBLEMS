#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long






// Template for binary search

// bool check(int arr[], int n, int mid){

//     if(mid==n-1 || arr[mid] > arr[mid+1])
//         return 1;
//     return 0;
// }

// void solve(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++) cin>>arr[i];
//     int lo=0; int hi=n-1; int ans=-1;
//     while(lo<=hi)
//     {
//         int mid = lo+(hi-lo)/2;
//         if(check(mid)==1){
//             ans=mid;
//             hi=mid-1;
//         }else{
//             lo=mid+1;
//         }
//     }
//     cout<<ans<<endl;
// }





// Painters Partition Problem

// bool check(int arr[], int n, int mid, int k){
//     int currTime=0; int painters=1;
//     for(int i=0;i<n;i++){
//         if(currTime + arr[i] <= mid){
//             currTime += arr[i];
//         }else{
//             currTime = arr[i];
//             painters++;
//         }
//         if(painters > k)return 0;
//     }
//     return painters <=k;
// }

// void solve(){
//     int n,k;
//     cin>>n>>k;
//     int arr[n];
//     int min_element = 1e9; int sum=0;
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//         min_element = min(min_element, arr[i]);
//         sum+= arr[i];
//     }
//     int lo=min_element,hi=sum;,ans=-1;
//     while(lo<=hi){
//         int mid = lo+(hi-lo)/2;
//         if(check(mid, k)){
//             ans=mid;
//             hi=mid-1;
//         }else{
//             lo=mid+1;
//         }
//     }
//     cout<<ans<<endl;
// }







// Initially there are n points, you can
// add k more points. You need to minimize
// the maximum neighbour distance

// bool check(int arr[], int n, int mid, int k){
//     int curr_dis = 0; int points=0;
//     for(int i=0;i<n-1;i++){
//         curr_dis = abs(arr[i] - arr[i+1]);
//         if(curr_dis > mid){
//             points += ((curr_dis + mid - 1) / mid) - 1; 
//         }
//         if(points > k) return 0;
//     }
//     return points <= k;
// }

// void solve(){
//     int n, k;
//     cin>>n>>k;
//     int arr[n];
//     int max_dis=0;
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//         if(i<n-1)
//             max_dis = max(max_dis, abs(arr[i] - arr[i+1]));
//     }
//     int lo=1; int hi=max_dis;
//     int ans=hi;
//     while(lo<=hi){
//         int mid = lo + (hi-lo)/2;
//         if(check(arr, n, mid, k)){
//             ans=mid;
//             hi=mid-1;
//         }else{
//             lo=mid+1;
//         }
//     }
//     cout<<ans<<endl;
// }








// Given 2 arrays of size n and m
// we need to find the kth element
// in the resultant array where res[i] = a[i]+b[j]
// where i and j are indices of arrays

// bool check(vector<int> &arr, vector<int> &brr, int mid, int k){
//     int n = arr.size();
//     int cnt=0;
//     for(int i=0;i<n;i++){
//         cnt+= upper_bound(brr.begin(), brr.end(), mid - arr[i]) - brr.begin();
//     }
//     return cnt>=k;
// }

// void solve(){
//     int n,m,k;
//     cin>>n>>m>>k;
//     vector<int>arr(n),brr(m);
//     for(int i=0;i<n;i++)
//         cin>>arr[i];
//     for(int i=0;i<m;i++)
//         cin>>brr[i];
//     if(n>m)
//     {
//         swap(n,m);
//         swap(arr,brr);
//     }
//     sort(arr.begin(), arr.end());
//     sort(brr.begin(), brr.end());
//     int lo=arr[0]+brr[0];
//     int hi=arr.back()+brr.back();
//     int ans=-1;
//     while(lo<=hi){
//         int mid=lo+(hi-lo)/2;
//         if(check(arr, brr, mid, k)){
//             ans = mid;
//             hi=mid-1;
//         }else{
//             lo=mid+1;
//         }
//     }
//     cout<<ans<<endl;
// }






// given a binary array
// find the maximum length 
// subarray of ones possible 
// by flipping atmost k elements

// bool check(int arr[], int n, int mid, int k){
//     for(int i=mid-1;i<n;i++){
//         int zeroes = arr[i] - ( (i-mid) >= 0 ? arr[i-mid] : 0);
//         if(zeroes <= k)
//             return 1;
//     }
//     return 0;
// }

// void solve(){
//     int n, k;
//     cin>>n>>k;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         int x;
//         cin>>x;
//         arr[i]=x;
//         if(i) arr[i]+=arr[i-1];
//     }
//     int lo=0; int hi=n;
//     int ans=0;
//     while(lo<=hi){
//         int mid=lo+(hi-lo)/2;
//         if(check(arr, n, mid, k)){
//             ans = mid;
//             lo=mid+1;
//         }else{
//             hi=mid-1;
//         }
//     }
//     cout<<ans<<endl;
// }









// Given an binary array of size n
// You need to find the number
// of subarrays of all 1's by
// doing <= k flips

// bool check(int pref[], int mid, int st, int k)
// {
//     int zeroes = ((pref[mid] - (st > 0  ? pref[st-1] : 0));
//     return zeroes <= k);
// }

// void solve()
// {
//     int n,k;
//     cin>>n>>k;
//     int arr[n];
//     int pref[n];
//     for(int i=0; i<n; i++)
//     {
//         cin>>arr[i];
//         pref[i] = 1 - arr[i];
//         if(i) pref[i] += pref[i-1];
//     }
//     int total=0;
//     for(int st=0; st<n; st++)
//     {
//         int lo=st;
//         int hi=n-1;
//         int best=st-1;
//         while(lo<=hi)
//         {
//             int mid = lo+(hi-lo)/2;
//             if(check(pref, mid, st, k)) {
//                 best = mid;
//                 lo=mid+1;
//             } else {
//                 hi=mid-1;
//             }
//         }
//         total += best - st + 1;
//     }
//     cout<<total<<endl;
// }





// find the index of minimum
// element in roatated sorted array

// bool check(int arr[], int mid, int n)
// {
//     return arr[mid] < arr[0];
// }

// void solve()
// {
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     int lo=0; int hi=n-1;
//     int ans=0;
//     while(lo<=hi)
//     {
//         int mid = lo+(hi-lo)/2;
//         if(check(arr, mid, n))
//         {
//             ans = mid;
//             hi=mid-1;
//         }
//         else
//         {
//             lo=mid+1;
//         }
//     }
//     cout<<ans<<endl;
// }














signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
