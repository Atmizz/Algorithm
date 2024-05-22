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
int n, q, dfn[N], dnf, sz[N], num[N];
std :: vector <int> adj[N];
void dfs(int u) {
  sz[u] = 1; dfn[++dnf] = u; num[u] = dnf;
  if(adj[u].empty()) {
    return ;
  }
  for(auto v : adj[u]) {
    dfs(v);
    sz[u] += sz[v];
  }
}
void solve() {
  std :: cin >> n >> q;
  for(int i = 2; i <= n; ++ i) {
    int x; std :: cin >> x;
    adj[x].push_back(i);
  }
  for(int i = 1; i <= n; ++ i) {
    std :: sort(adj[i].begin(), adj[i].end());
  }
  dfs(1);
  while(q --) {
    int u, k, ans;
    std :: cin >> u >> k;
    if(sz[u] < k) {
      ans = -1;
    } else {
      ans = dfn[num[u] + k - 1];
    }
    std :: cout << ans << '\n';
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