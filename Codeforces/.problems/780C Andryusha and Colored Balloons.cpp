#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl '\n'
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
int n, col[N], ans, fa[N];
std :: vector <int> adj[N];
void dfs(int u) {
  int x = 1;
  for(auto v : adj[u]) {
    if(v == fa[u]) {
      continue;
    }
    while(x == col[fa[u]] || x == col[u]) {
      x ++;
    }
    col[v] = x;
    x ++;
    fa[v] = u;
  }
  ans = std :: max(ans, x - 1);
  for(auto v : adj[u]) {
    if(v != fa[u]) {
      dfs(v);
    }
  }
}
void solve() {
  std :: cin >> n;
  for(int i = 1; i < n; ++ i) {
    int u, v;
    std :: cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  col[1] = 1;
  dfs(1);
  std :: cout << ans << '\n';
  for(int i = 1; i <= n; ++ i) {
    std :: cout << col[i] << ' ';
  }
}
int main() {
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);
  std :: ios :: sync_with_stdio(false);
  std :: cin.tie(0);
  std :: cout.tie(0);
  int T = 1;
  //std :: cin >> T; 
  while(T --) solve();
  return 0;
}