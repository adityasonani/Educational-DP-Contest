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
ITETATIVE SOLUTION TO PROBLEM E
link - https://atcoder.jp/contests/dp/tasks/dp_e
*/
 
const long long INF = 1e13;
int dp[MAX];
void solve()
{
    int n, weig;
    cin>>n>>weig;
 
    int w[MAX], v[MAX];
    int v_max = 0;
    rep(i, n){
        cin>>w[i]>>v[i];
        v_max += v[i];
    }
 
    for(int i = 1;i<=v_max;i++) dp[i] = INF;
    dp[0] = 0;
 
    for(int i=0; i<n; i++){
        for(int j=v_max; j>=v[i]; j--){
            dp[j] = min(dp[j-v[i]] + w[i], dp[j]);
        }
    }
    
    for(int i=v_max; i>=0; i--){
        if(dp[i] <= weig){
            cout << i;
            return;
        }
    }
 
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
