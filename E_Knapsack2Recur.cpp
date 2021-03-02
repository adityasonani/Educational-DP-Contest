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
#define     MAX         (int) 100007 // 10^5
 
 
using namespace std;
 
/*
RECURSIVE SOLUTION FOR PROBLEM E
link - https://atcoder.jp/contests/dp/tasks/dp_e
*/
int n, weig;
int w[MAX], v[MAX];
int dp[107][MAX];
// recursive function to calculate max value
int knapsack(int ind, int rem){
    // base case
    if(ind==n){
        return (rem==0) ? 0 : INT_MAX;
    }
    // memoize
    if(dp[ind][rem] != -1){
        return dp[ind][rem];
    }
    
    // dont include
    int ans = knapsack(ind+1, rem);
 
    // if abhi ki value is <= remaining
    if(v[ind] <= rem){
        // include
        ans = min(ans, w[ind] + knapsack(ind+1, rem - v[ind]));
    }
    
    return dp[ind][rem] = ans;
}
 
int so(int v_max){
    for(int i=v_max; i>=0; i--){
        if(knapsack(0, i) <= weig){
            
            return i;
        }
    }
    return 0;
}
 
void solve()
{
    
    cin>>n>>weig;
 
    int v_max = 0;
    rep(i, n){
        cin>>w[i]>>v[i];
        v_max += v[i];
    }
 
    // initialize to -1
    memset(dp, -1, sizeof(dp));
 
    cout << so(v_max);
 
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
