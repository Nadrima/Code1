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
 //#include "template.cpp"
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
int par[N];
int d[N];
int f[N];
int t;


void dfs(int u){
    vis[u]=true;
    //d[u]+=t;
    //t++;
    t++;
    d[u]=t;
    for(auto v:g[u]){
        if(!vis[v]){
            dfs(v);

        }
    }
    t++;
    f[u]=t;
   

}

 void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int u,k;
        cin>>u>>k;
        for(int j=1;j<=k;j++){
            
            int x;
            cin>>x;
            g[u].pb(x);
         
        }
        sort(all(g[u]));
    }
    t=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<d[i]<<" "<<f[i]<<endl;
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
 
 