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
#define     MAX         (int) 100007 // 10^5


using namespace std;
 
/*
THIS IS NOT THE F PROBLEM OF ATCODER DP CONTEST
IT IS JUST TO LEARN THE LENGTH OF LONGEST COMMON SUBSEQUENCE
*/
int dp[3007][3007];
int lcs(string s, string t, int n, int m){
    if(n==0 || m==0){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(s[n-1]==t[m-1]){
        return dp[n][m] = 1+lcs(s, t, n-1, m-1);
    }
    return dp[n][m] = max(lcs(s, t, n, m-1), lcs(s, t, n-1, m));
}

void solve()
{
    string s, t;
    cin>>s>>t;

    int n = s.length(), m = t.length();

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            dp[i][j] = -1;
        }
    }

    cout << lcs(s, t, n, m);
    
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
