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
const int N = 1010;
int n, m, head[N], cnt, s[N];
i64 dis[N][N];
struct Edge {
  int to, net, dis;
}e[N<<1];
struct Node {
  int x;
  i64 dis;
  int s;
  friend bool operator < (Node a, Node b) {
    return a.dis > b.dis;
  }
};
void init() {
  cnt = 0;
  std :: fill(head, head + n + 1, 0);
  for(int i = 1; i < N; ++ i) {
    for(int j = 1; j < N; ++ j) {
      dis[i][j] = LLINF;
    }
  }
}
void Insert(int u, int v, int w) {
  e[++cnt] = {v, head[u], w};
  head[u] = cnt;
}
void solve() {
  std :: cin >> n >> m;
  init();
  for(int i = 1; i <= m; ++ i) {
    int u, v, w;
    std :: cin >> u >> v >> w;
    Insert(u, v, w); 
    Insert(v, u, w);
  }
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> s[i];
  }
  std :: priority_queue <Node> q;
  dis[1][s[1]] = 0;
  q.push({1, 0, s[1]});
  while(q.size()) {
    int u = q.top().x, ss = q.top().s;
    i64 d = q.top().dis;
    q.pop();
    if(dis[u][ss] != d) continue;
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      int res = std :: min(ss, s[v]);
      // deb(dis[v][res]);
      // deb(dis[u][ss] + e[i].dis * ss)
      if(dis[v][res] > dis[u][ss] + e[i].dis * ss) {
        // deb(u); deb(v);
        dis[v][res] = dis[u][ss] + e[i].dis * ss;
        q.push({v, dis[v][res], res});
      }
    }
  }
  i64 ans = LLINF;
  for(int i = 1; i <= n; ++ i) {
    ans = std :: min(ans, dis[n][s[i]]);
  }
  std :: cout << ans << '\n';
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