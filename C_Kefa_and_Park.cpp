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
 
 
 vector<bool> is_prime (N,true);
 vi prime;
 void sieve(){
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<N;i++){
     if(is_prime [i]){
         for(int j=i+i;j<N;j+=i){
            is_prime[j]=false;
         }
     }
    }
    for(int i=2;i<N;i++){
        
        if(is_prime[i]){
         prime.pb(i);
        }
    }
 }
 
 
 int power(int n,int x){
     if(x==0) return 1;
     int curr=power(n,x/2);
     if(x&1){
     return 1ll*curr*curr%M*n%M;
     }
     else{
     return 1ll*curr*curr%M;
     }
 }
 
 
vi g[N];
bool vis[N];
int cnt[N];
int sum[N];
int ans=0;
int c=0;
int tt;
void dfs(int u,int c){
    vis[u]=true;
    if(cnt[u]) c++;
    else{
       c=0;
    }
    if(c>tt) return;
    if(g[u].size()==1)
    for(auto v:g[u]){
        if(!vis[v]){
            dfs(v,c);
        }
    }

}

 void solve(){
     int a,b;
     cin>>a>>b;
     while(1){
        if(a*2>b) break;
        else
        {
        g[a].push_back(2*a);
        g[2*a].push_back(a);
        }
        if((a*10+1)>b)break;
        else{
           g[a].push_back(10*a+1);
           g[10*a+1].push_back(a);
        }

     }
     dfs(a);

 }
 
 int32_t main()
 {
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     int t=1;
     cin>>t;
     //sieve();
     //powers();
     while(t--){
         solve();
     }
 }
 
 