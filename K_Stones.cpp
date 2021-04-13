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
ITERATIVE SOLUTION FOR PROBLEM K
LINK - https://atcoder.jp/contests/dp/tasks/dp_k
*/

void solve()
{
    int n, k;
    cin>>n>>k;

    vector<int> v(n);
    for(int i=0; i<n; i++) cin>>v[i];

    bool dp[k+1];

    for(int valueOfK=0; valueOfK<=k; valueOfK++){
        dp[valueOfK] = false;
        for(int valueInV: v){
            if(valueOfK >= valueInV && dp[valueOfK-valueInV]==false){
                dp[valueOfK] = true;
                break;
            }
        }
    }

    if(dp[k]){
        cout << "First";
    }
    else{
        cout << "Second";
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

    // cerr << "\nTime taken : " << ((long double)duration.count())/((long double) 1e9) <<" s "<< endl;

    return 0;
}
