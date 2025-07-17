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
const int N = 1e3 + 7;
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

int n,m;
string s[N];
int dis[N][N];
//int par[N][N];
pair<int,int> par[N][N];
int vis[N][N];


bool is_valid(int i,int j){
    return i>=0 && j>=0 && i<n && j<m;
}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    pair<int,int>str,end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='A'){
                str.first=i;
                str.second=j;
            }
            else if(s[i][j]=='B'){
                end.first=i;
                end.second=j;
            }
        }
    }
    queue<pair<int,int>>q;
    q.push(str);
    dis[str.first][str.second]=0;
    vis[str.first][str.second]=true;

    while(!q.empty()){
        auto [i,j]=q.front();
        q.pop();
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(is_valid(x,y)&& !vis[x][y] && s[x][y]!='#'){
                q.push({x,y});
                dis[x][y]=dis[i][j]+1;
                par[x][y].first=i;
                par[x][y].second=j;
                vis[x][y]=true;
                
            }
        }
    }
    int ans=dis[end.first][end.second];
    if(!vis[end.first][end.second]){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        cout<<ans<<endl;
        vector<pair<int,int>>p;
        auto cur=end;
        while(cur!=str){
            p.pb(cur);
            cur=par[cur.first][cur.second];

        }
        p.pb(str);
        reverse(all(p));
        for(int i=0;i<(int)p.size()-1;i++){
           int xx=p[i+1].first-p[i].first;
           int yy=p[i+1].second-p[i].second;
           if(xx==1){
            cout<<'D';
           }
           else if(xx==-1){
            cout<<'U';
           }
           else if(yy==1){
            cout<<'R';
           }
           else{
            cout<<'L';
           }
           
        }
        cout<<endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}

