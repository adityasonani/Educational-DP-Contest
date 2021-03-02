/**
 * @author: adityasonani
 * */
#include <bits/stdc++.h>
 
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
 
#define     int          long long
#define     ld        	long double
#define     ln          "\n"
#define     fastio      ios_base::sync_with_stdio(0); cin.tie(nullptr)
#define     MOD         (int) 1000000007
#define     rep(i, n)   for (int i = 0; i < (int)n; i++)
#define     all(x)      (x).begin(), (x).end()
#define     debug(x)    cerr << #x << " = " << x << endl;
#define     precise(x)  cout << fixed << setprecision(x)
#define     MAX         (int) 100002 // 10^5
 
 
using namespace std;
 
/*
RECURSIVE SOLUTION FOR PROBLEM D
link - https://atcoder.jp/contests/dp/tasks/dp_d
*/
 
int dp[102][MAX];
// recursive function to calculate max value (without memoization)
int knapsack(int w[], int v[], int n, int weig){
    // base case
    if(n==0 || weig==0){
        return 0;
    }
    // memoize
    if(dp[n][weig] != -1){
        return dp[n][weig];
    }
    // if our abhi ka weight is <= remaining weight
    // so -> 2 options -
    // 1) either take this weight or
    // 2) dont take this weight
    if(w[n-1] <= weig){
        // 1st option
        int include = v[n-1] + knapsack(w, v, n-1, weig-w[n-1]);
        // 2nd option
        int dont = knapsack(w, v, n-1, weig);
        // return the max
        return dp[n][weig] = max(include, dont);
    }
    // else if abhi weight is > remaining weight so
    // we can't fit in this weight in knapsack so just don't include
    else if(w[n-1] > weig){
        return dp[n][weig] = knapsack(w, v, n-1, weig);
    }
 
    return 0;
}
 
void solve()
{
    int n, weig;
    cin>>n>>weig;
 
    int w[n], v[n];
    rep(i, n) cin>>w[i]>>v[i];
    
    // initialize to -1
    rep(i, n+1) rep(j, weig+1) dp[i][j] = -1;
 
    // call our main function
    cout << knapsack(w, v, n, weig);
 
}
 
signed main()
{
    fastio;
 
    auto start = std::chrono::high_resolution_clock::now();
 
    int t=1;
    // cin>>t;
 
    while(t--)
        solve();
  
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
 
    cerr << "\nTime taken : " << ((long double)duration.count())/((long double) 1e9) <<" s "<< endl;
 
    return 0;
}
