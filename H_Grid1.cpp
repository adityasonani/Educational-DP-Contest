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
ITERATIVE SOLUTION FOR PROBLEM H
LINK - https://atcoder.jp/contests/dp/tasks/dp_h
*/

int n, m;
char v[1001][1001];
int dp[1001][1001];

void solve()
{
    cin>>n>>m;

    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        for(int j=0; j<m; j++){
            v[i][j] = s[j];
        }
    }

    // see if any '#' is blocking the road after that cell row wise
    // .
    // .
    // #
    // (blocked)
    // (blocked)
    bool found = false;
    for(int i=0; i<n; i++){
        if(v[i][0]=='.' && !found){
            dp[i][0] = 1;
        }
        else{
            found = true;
            dp[i][0] = 0;
        }
    }
    // see if any '#' is blocking the road after that cell column wise
    // ..#(blocked)(blocked)
    found = false;
    for(int i=0; i<m; i++){
        if(v[0][i]=='.' && !found){
            dp[0][i] = 1;
        }
        else{
            found = true;
            dp[0][i] = 0;
        }
    }

    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            // if road available
            if(v[i][j]=='.'){
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    cout << dp[n-1][m-1];
    
}

signed main()
{
    fastio;
  
    int t=1;
    // cin>>t;

    while(t--)
        solve();

    return 0;
}
