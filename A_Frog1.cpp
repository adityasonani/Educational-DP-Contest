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
PROBLEM LINK - https://atcoder.jp/contests/dp/tasks/dp_a
*/

void solve()
{
    int n;
    cin>>n;

    int ar[n+1];
    for(int i=1; i<=n; i++) cin>>ar[i];

    int dp[n+1];
    dp[1] = 0;
    // no choice but to take 1 step
    dp[2] = abs(ar[2]-ar[1]);

    for(int i=3; i<=n; i++){
        // take 1 step
        int firstChoice = dp[i-1] + abs(ar[i]-ar[i-1]);
        // take 2 steps
        int secondChoice = dp[i-2] + abs(ar[i]-ar[i-2]);
        // min of both
        dp[i] = min(firstChoice, secondChoice);
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
