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


void solve(){
    int n,m;
    cin>>n>>m;
    map<int,int>mp;
    queue<int>q;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        q.push(x);
        mp[x]=0;
    }
    vi ans;
    ll sum=0;
    while(!q.empty()&& m>0){
        int u=q.front();
        q.pop();
        if(mp.find(u-1)==mp.end() && m>0){
            q.push(u-1);
            mp[u-1]=mp[u]+1;
            ans.pb(u-1);
            sum+=mp[u-1];
            m--;
            
        }
        if(mp.find(u+1)==mp.end() && m>0){
            q.push(u+1);
            mp[u+1]=mp[u]+1;
            ans.pb(u+1);
            sum+=mp[u+1];
            m--;
        }

    }
    cout<<sum<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    cout<<endl;
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

