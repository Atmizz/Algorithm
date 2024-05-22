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
const int N = 3e5 + 20;
int n, num[N], cnt, head[N], dp[N];
struct Edge {
  int to, net;
}e[N<<1];
inline void Insert(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
}
void dfs(int u, int fa) {
  num[u] = 1; dp[u] = 0;
  int l = 0, r = 0;
  for(int i = head[u]; i; i = e[i].net) {
    int v = e[i].to;
    if(v == fa) continue;
    dfs(v, u);
    if(l == 0) {
      l = v;
    } else {
      r = v;
    }
    num[u] += num[v];
  }
  if(l != 0) {
    if(r == 0) {
      dp[u] = num[l] - 1;
    } else {
      dp[u] = std :: max(dp[l] + num[r] - 1, dp[r] + num[l] - 1);
    }
  }
}
void init() {
	cnt = 0;
	std :: fill(head, head + n + 1, 0);
}
void solve() {
  std :: cin >> n;
	init();
  for(int i = 1; i < n; ++ i) {
    int u, v;
    std :: cin >> u >> v;
    Insert(u, v); Insert(v, u);
  }
  dfs(1, 1);
  std :: cout << dp[1] << '\n';
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
