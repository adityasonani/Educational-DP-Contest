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
*/

void solve()
{
    int n;
    cin>>n;

    int a[n], b[n], c[n];
    rep(i, n) cin>>a[i]>>b[i]>>c[i];

    // create a dp array of size 3 to store max points scored if we took a{0}, b{1} or c{2}
    int dp[n][3];
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    
    for(int i=1; i<n; i++){
        dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = c[i] + max(dp[i-1][0], dp[i-1][1]);
    }
    
    // our ans will be the max of all the last three elements
    int ans = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    cout << ans << ln;
    
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
