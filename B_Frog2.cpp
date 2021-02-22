/**
 * @author: adityasonani
 * */
#include <bits/stdc++.h>

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")

#define     ll          long long
#define     ld        	long double
#define     ln          "\n"
#define     fastio      ios_base::sync_with_stdio(0); cin.tie(nullptr)
#define     MOD         (int) 1000000007
#define     rep(i, n)   for (int i = 0; i < (int)n; i++)
#define     all(x)      (x).begin(), (x).end()
#define     debug(x)    cerr << #x << " = " << x << endl;
#define     precise(x)  cout << fixed << setprecision(x)
#define     MAX         (int) 100000 // 10^5


using namespace std;

/*
PROBLEM LINK - https://atcoder.jp/contests/dp/tasks/dp_b
*/

void solve()
{
    int n, k;
    cin>>n>>k;

    int ar[n+1];
    for(int i=1; i<=n; i++) cin>>ar[i];

    int dp[n+1];
    for(int i=1; i<=n; i++){
        dp[i] = INT_MAX;
    }

    dp[1] = 0;
    
    for(int i=1; i<=n; i++){
        // check for every step from i+1 ..... i+k
        // and just take the min
        for(int j=i+1; j<=i+k; j++){
            if(j<=n){
                int choice = dp[i] + abs(ar[i]-ar[j]);
                dp[j] = min(dp[j], choice);
            }
        }
    }


    cout << dp[n] << ln;

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
