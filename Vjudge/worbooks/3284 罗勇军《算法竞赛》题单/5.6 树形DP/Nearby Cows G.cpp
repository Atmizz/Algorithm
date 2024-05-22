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
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, k, dp[MaxN][25], d[MaxN][25],val[MaxN];
std :: vector <int> g[MaxN];
void dfs2(int u, int fa, int depth) {
  int x = (depth - 2) >= 0 ? d[u][depth-2] : 0;
  dp[u][depth] = dp[fa][depth-1] - x + d[u][depth];
  for(auto v : g[u])
    if(v != fa) dfs2(v, u, depth);
}
void dfs1(int u, int fa, int depth) {
  d[u][depth] += d[u][0];
  for(auto v : g[u]) {
    if(v == fa) continue;
    d[u][depth] += d[v][depth-1];
    dfs1(v, u, depth);
  }
}
int main() {
  n = read(); k = read();
  for(int i = 1; i < n; ++ i) {
    int u = read(), v = read();
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for(int i = 1; i <= n; ++ i) d[i][0] = val[i] = dp[i][0] = read();
  for(int i = 1; i <= k; ++ i) dfs1(1, 0, i), dp[1][i] = d[1][i];
  for(int i = 1; i <= k; ++ i)
    for(auto u : g[1])
      dfs2(u, 1, i);
  for(int i = 1; i <= n; ++ i)
    printf("%d\n", dp[i][k]);
  return 0;
}