

#include<bits/stdc++.h>
using namespace std;

const int N = 105;
vector<pair<int, int>> g[N];
bool vis[N];
int cost = 0;
void dfs(int u, int p = 0) {
  vis[u] = true;
  for (auto [v, w]: g[u]) {
    if (!vis[v]) {
      cost += w;
      dfs(v, u);
    }
    else if (v == 1 and p != 1) {
      cost += w;
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back({v, 0});
    g[v].push_back({u, w});
    sum += w;
  }
  dfs(1);
  cout << min(cost, sum - cost) << '\n';
  return 0;
}

https://vjudge.net/problem/lightoj-1174

#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int edges, cs = 0;
  while (cin >> edges and edges) {
    map<int, vector<int>> g;
    set<int> nodes;
    while (edges--) {
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
      nodes.insert(u);
      nodes.insert(v);
    }
    int start, ttl;
    while (cin >> start >> ttl and !(start == 0 and ttl == 0)) {
      map<int, int> d;
      for (auto u: nodes) {
        d[u] = inf;
      }
      queue<int> q;
      q.push(start);
      d[start] = 0;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v: g[u]) {
          if (d[u] + 1 < d[v]) {
            d[v] = d[u] + 1;
            q.push(v);
          }
        }
      }
      int not_reachable = 0;
      for (auto u: nodes) {
        if (d[u] > ttl) {
          not_reachable++;
        }
      }
      cout << "Case " << ++cs << ": " << not_reachable << " nodes not reachable from node " << start << " with TTL = " << ttl << ".\n";
    }
  }
  return 0;
}