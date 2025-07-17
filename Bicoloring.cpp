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
const int N = 2e2 + 7;
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
int col[N];
int vis[N];
bool ok;

void dfs(int u){
    vis[u]=true;
    for(auto v:g[u]){
        if(!vis[v]){
             col[v]=col[u]^1;
             dfs(v);
        }
        else{
            if(col[v]==col[u]){
                ok=false;
            }
        }
    }
}

void solve(){
    
int n;
while(cin>>n && n){
    int l;
    cin>>l;
    for(int i=1;i<=l;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    //col[0]=0;
    ok=true;
    dfs(0);
    if(ok){
        cout<<"BICOLORABLE."<<endl;
    }
    else{
        cout<<"NOT BICOLORABLE."<<endl;
    }
    for(int i=0;i<n;i++){
        g[i].clear();
        vis[i]=0;
        col[i]=0;
    }
}

  
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

