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
const int N = 1e3 + 9;
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
int vis[N];
int cnt[N];

void dfs(int u){
    vis[u]=true;
    cnt[u]++;
    for(auto v:g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

void solve()
{
    
    int k,n,m;
    cin>>k>>n>>m;
    int arr[k+1];
    for(int i=1;i<=k;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
    }
    for(int i=1;i<=k;i++){
        dfs(arr[i]);
        for(int i=0;i<N;i++){
        vis[i]=false;
    }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]==k){
           ans++;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<N;i++){
        cnt[i]=0;
        g[i].clear();
    }
    
} 

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    //sieve();
    //powers();
    /*while(t--){
        solve();
    }*/
    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<": ";
        solve();
    }
}

