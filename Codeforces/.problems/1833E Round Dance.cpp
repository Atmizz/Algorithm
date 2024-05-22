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
int n, deg[N], cnt;
bool vis[N];
std :: set <int> adj[N+1];
int dfs(int u) {
  vis[u] = 1; cnt ++;
  int res = 0;
  if(deg[u] > 2) {
    res = 1;
  }
  for(auto v : adj[u]) {
    if(vis[v]) continue;
    res |= dfs(v);
  }
  return res;
}
void solve() {
  std :: cin >> n;
  for(int i = 1; i <= n; ++ i) {
    vis[i] = deg[i] = 0;
    adj[i].clear();
  }
  for(int i = 1; i <= n; ++ i) {
    int x;
    std :: cin >> x;
    adj[i].insert(x);
    adj[x].insert(i);
    deg[x] ++; deg[i] ++;
  }
  int roundCnt = 0, listCnt = 0;
  for(int i = 1; i <= n; ++ i) {
    cnt = 0;
    if(vis[i]) {
      continue;
    }
    int flag = dfs(i);
    if(flag || (!flag&& cnt == 2)) listCnt ++;
    else roundCnt ++;
  }
  // deb(roundCnt);
  // deb(listCnt);
  std :: cout << roundCnt + (listCnt > 0) << ' ' << 
    roundCnt + listCnt << '\n';
}
int main() {
  //freopen("1.in", "r", stdin);
  //freopen("1.out", "w", stdout);
  std :: ios :: sync_with_stdio(false);
  std :: cin.tie(0);
  std :: cout.tie(0);
  int T = 1;
  std :: cin >> T; 
  while(T --) solve();
  return 0;
}