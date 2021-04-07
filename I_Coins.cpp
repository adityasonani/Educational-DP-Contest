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
#define     debugV(x)   cerr << "["; for(auto i: x){ cerr << i << ", ";} cerr << "]" << endl;
#define     precise(x)  cout << fixed << setprecision(x)
#define     MAX         (int) 100007 // 10^5


using namespace std;
 
/*
ITERATIVE SOLUTION FOR PROBLEM I
LINK - https://atcoder.jp/contests/dp/tasks/dp_i
*/

void solve()
{
    int n;
    cin>>n;

    vector<double> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    double dp[n+1][n+1];
    memset(dp, 0.0, sizeof dp);

    dp[0][0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=0; j<=i; j++){
            if(j==0){
                // DONT TAKE HEADS AT ALL
                dp[i][j] = dp[i-1][j]*(1-v[i-1]);
            }
            else{
                // WE HAVE 2 OPTIONS NOW
                //   PREVIOUS TAILS*HERE TAKE HEAD + PREVIOUS HEAD*HERE TAKE TAILS
                dp[i][j] = (dp[i-1][j-1]*v[i-1]) + (dp[i-1][j]*(1-v[i-1]));
            }
        }
    }

    // OUR ANS WOULD BE IN Nth ROW WHERE
    // NO. OF HEADS > N/2
    double ans = 0.0;
    for(int i=n; i>n/2; i--){
        ans += dp[n][i];
    }
    precise(10);
    cout << ans;
    
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

    // cerr << "\nTime taken : " << ((long double)duration.count())/((long double) 1e9) <<" s "<< endl;

    return 0;
}
