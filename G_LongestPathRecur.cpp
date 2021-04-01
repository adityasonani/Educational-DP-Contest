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
RECURSIVE SOLLUTION FOR PROBLEM G
LINK - https://atcoder.jp/contests/dp/tasks/dp_g
*/

vector<int> adj[MAX];
bool vis[MAX];
int dp[MAX];

void recur(int parent){
    dp[parent] = 0;
    vis[parent] = true;
    for(int child: adj[parent]){
        if(!vis[child]){
            recur(child);
        }
        dp[parent] = max(dp[parent], 1 + dp[child]);
    }
}

void solve()
{
    int n, m;
    cin>>n>>m;
    
    memset(vis, false, sizeof vis);
    adj->clear();

    rep(i, m){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
     
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            recur(i);
        }
    }

    int mx = 0;
    for(int i=1; i<=n; i++){
        mx = max(mx, dp[i]);
    }

    cout << mx;
    
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
