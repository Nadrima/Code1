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
const int N = 25;
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

string g[N];

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool vis[N][N];

int cnt;
int n,m;

bool valid(int i,int j){
   return i>=0 && i<n && j>=0 && j<m;
}

void dfs(int i,int j){
    
   vis[i][j]=true;
   cnt++;
   for(int k=0;k<4;k++){
    int xx=i+dx[k];
    int yy=j+dy[k];
    if(valid(xx,yy)&&g[xx][yy]=='.'&&!vis[xx][yy]){
        //cnt++;
        dfs(xx,yy);
    }
   }
}

void solve(){
    cin>>m>>n;
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    int a,b;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='@'){
                a=i;
                b=j;
    
            }
        }
    }
    cnt=0;
    dfs(a,b);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vis[i][j]=false;
        }
    }
    cout<<cnt<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
    cout<<"Case "<<i<<": ";
    solve();
   }
}

