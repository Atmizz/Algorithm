#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline int read() {
  int s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 120;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int t, n, depth[MaxN];
std :: vector <int> g[MaxN];
void dfs(int u, int fa) {
  if(g[u].size() == 1 && u != 0) {
    depth[u] = 1;
    return ;
  }
  for(auto v : g[u]) {
    if(v == fa) continue;
    dfs(v, u);
    depth[u] = max(depth[u], depth[v] + 1);
  }
}
int main() {
  n = read(); t = read();
  for(int i = 1; i < n; ++ i) {
    int u = read(), v = read();
    g[u].push_back(v);
    g[v].push_back(u);
  } dfs(0, -1);
  if(t <= depth[0] - 1) printf("%d", t + 1);
  else printf("%d", min(n, depth[0] + (t - depth[0] + 1) / 2));
  return 0;
}