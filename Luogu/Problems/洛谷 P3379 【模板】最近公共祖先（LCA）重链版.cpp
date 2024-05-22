#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
#define ll long long
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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
struct Egde {
  int to, net;
}e[MaxN<<1];
int n, m, s, cnt, head[MaxN<<1], sz[MaxN], son[MaxN], top[MaxN], fa[MaxN], dep[MaxN];
void Insert(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
}
void dfs1(int u) {
  dep[u] = dep[fa[u]] + 1; sz[u] = 1;
  for(int i = head[u]; i; i = e[i].net) {
    int v = e[i].to;
    if(v == fa[u]) continue;
    fa[v] = u; dfs1(v); sz[u] += sz[v];
    if(!son[u] || sz[v] > sz[son[u]]) son[u] = v;
  }
}
void dfs2(int u, int pa) {
  top[u] = pa;
  if(son[u]) dfs2(son[u], pa);
  for(int i = head[u]; i; i = e[i].net) {
    int v = e[i].to;
    if(v == son[u] || v == fa[u]) continue;
    dfs2(v, v);
  }
}
int LCA(int x, int y) {
  while(top[x] != top[y]) {
    if(dep[top[x]] > dep[top[y]]) x = fa[top[x]];
    else y = fa[top[y]];
  } return dep[x] < dep[y] ? x : y;
}
int main() {
  n = read(), m = read(), s = read();
  for(int i = 1; i < n; ++ i) {
    int u = read(), v = read();
    Insert(u, v); Insert(v, u);
  } dfs1(s); dfs2(s, s);
  for(int i = 1; i <= m; ++ i) {
    int x = read(), y = read();
    printf("%d\n", LCA(x, y));
  }
}