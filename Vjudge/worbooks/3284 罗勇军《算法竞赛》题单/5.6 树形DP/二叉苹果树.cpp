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
const int MaxN = 110;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, k, head[MaxN<<1], cnt, dp[MaxN][MaxN], sz[MaxN];
struct Node {
  int to, net, w;
}e[MaxN<<1];
inline void Insert(int u, int v, int w) {
  e[++cnt] = (Node) {v, head[u], w};
  head[u] = cnt;
}
void dfsDP(int u, int fa) {
  for(int i = head[u]; i; i = e[i].net) {
    int v = e[i].to; if(v == fa) continue;
    dfsDP(v, u); sz[u] += sz[v] + 1;
    for(int j = min(k, sz[u]); j; -- j)
      for(int k = min(sz[v], j - 1); k >= 0; -- k)
        dp[u][j] = max(dp[u][j], dp[u][j-k-1] + dp[v][k] + e[i].w);
  }
}
int main() {
  n = read(); k = read();
  for(int i = 1; i < n; ++ i) {
    int u = read(), v = read(), w = read();
    Insert(u, v, w); Insert(v, u, w);
  } dfsDP(1, 0);
  printf("%d", dp[1][k]);
  return 0;
}