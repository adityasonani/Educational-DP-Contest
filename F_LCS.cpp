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
ITERATIVE SOLUTION FOR PROBLEM F
link - https://atcoder.jp/contests/dp/tasks/dp_f
*/

int dp[3007][3007];
void solve()
{
    string s, t;
    cin>>s>>t;

    int n = s.length(), m = t.length();
    
    for(int i=0; i<=m; i++)
        dp[0][i] = 0;
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1]==t[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    int i = n, j = m;
    string ans = "";
    while(i>0 && j>0){
        if(s[i-1] == t[j-1]){
            ans += s[i-1];
            i--;
            j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    reverse(all(ans));
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
