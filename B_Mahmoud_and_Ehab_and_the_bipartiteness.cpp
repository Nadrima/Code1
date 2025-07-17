#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mem(a, b) memset(a, b, sizeof(a))
#define vi vector<int>
#define vll vector<ll>
#define si set<int>
#define sll set<ll>
#define pii pair<int,int>
#define mii map<int,int>
#define sortt(x) sort(x.begin(),x.end())
#define rsort(x) sort(x.rbegin(),x.rend())
#define pb(x) push_back(x)
#define sz(x) x.size()
#define read(x)        \
    for (auto &it : x) \
        cin >> it;


const int M = 1e9 + 7;
const int N = 1e5 + 7;
#ifndef ONLINE_JUDGE
#include "template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif

/*
unordered_map<ll, ll> mp1;
mp.reserve(1024);
mp.max_load_factor(0.25);
*/

vi g[N];
int depth[N];

void dfs(int u,int p){
    depth[u]=depth[p]+1;
    for(auto v:g[u]){
        if(v!=p){
            dfs(v,u);
        }
    }

}

void solve(){
      int n;
      cin>>n;
      for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
      }
      dfs(1,0);
      int r=0;
      int b=0;
      for(int i=1;i<=n;i++){
        if(depth[i]%2==0){
            b++;
        }
        else{
            r++;
        }
      }
      ll ans=1ll*r*b;
      cout<<ans-(n-1)<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    //cin>>t;
    //sieve();
    //powers();
    while(t--){
        solve();
    }
}

