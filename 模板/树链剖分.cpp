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
const int MaxN = 1e5+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, p, rt, val[MaxN];
namespace Heavy_Chain {
  struct Tree {
    int l, r, val, lazy;
  }t[MaxN << 2];
  struct Edge {
    int to, net;
  }e[MaxN << 1];
  int head[MaxN << 1], cnt, Top[MaxN], fa[MaxN], id[MaxN], son[MaxN], dep[MaxN], sz[MaxN], dfn[MaxN], dnf, w[MaxN];
  inline void Insert(int u, int v) {
    e[++cnt] = {v, head[u]};
    head[u] = cnt;
  }
  void dfs_1(int u, int F) {
    fa[u] = F; dep[u] = dep[F] + 1; sz[u] = 1;
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(v == F) continue ;
      dfs_1(v, u);
      sz[u] += sz[v];
      if(sz[v] > sz[son[u]]) son[u] = v;
    }
  }
  void dfs_2(int u, int tp) {
    Top[u] = tp; dfn[u] = ++ dnf; w[dnf] = val[u];
    if(son[u]) dfs_2(son[u], tp);
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(v == fa[u] || v == son[u]) continue ;
      dfs_2(v, v);
    }
  }
  inline void Push_Up(int k) {
    t[k].val = (t[ls].val + t[rs].val) % p;
  }
  void Push_Down(int k) {
    t[ls].lazy += t[k].lazy; t[ls].lazy %= p;
    t[rs].lazy += t[k].lazy; t[rs].lazy %= p;
    t[ls].val = (t[ls].val + t[k].lazy * (t[ls].r - t[ls].l + 1)) % p;
    t[rs].val = (t[rs].val + t[k].lazy * (t[rs].r - t[rs].l + 1)) % p;
    t[k].lazy = 0;
  }
  void Build(int l, int r, int k) {
    t[k].l = l; t[k].r = r;
    if(l == r) {
      t[k].val = w[l];
      return ;
    }
    int mid = (l + r) >> 1;
    Build(l, mid, ls); Build(mid + 1, r, rs);
    Push_Up(k);
  }
  void Up_data(int l, int r, int k, int x) {
    if(l <= t[k].l && t[k].r <= r) {
      t[k].lazy += x; t[k].lazy %= p;
      t[k].val = (t[k].val + x * (t[k].r - t[k].l + 1));
      return ;
    }
    if(t[k].lazy) Push_Down(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) Up_data(l, r, ls, x);
    if(r > mid) Up_data(l, r, rs, x);
    Push_Up(k);
  }
  int Query(int l, int r, int k) {
    if(l <= t[k].l && t[k].r <= r) return t[k].val % p;
    int mid = (t[k].l + t[k].r) >> 1, val = 0;
    if(t[k].lazy) Push_Down(k);
    if(l <= mid) val += Query(l, r, ls), val %= p;
    if(r > mid) val += Query(l, r, rs), val %= p;
    return val % p;
  }
  void Up_data_1(int x, int y, int k) {
    while(Top[x] != Top[y]) {
      if(dep[Top[x]] < dep[Top[y]]) std :: swap(x, y);
      Up_data(dfn[Top[x]], dfn[x], 1, k), x = fa[Top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    Up_data(dfn[x], dfn[y], 1, k);
  }
  void Up_data_2(int x, int k) {
    Up_data(dfn[x], dfn[x] + sz[x] - 1, 1, k);
  }
  int Query1(int x, int y) {
    int val = 0;
    while(Top[x] != Top[y]) {
      if(dep[Top[x]] < dep[Top[y]]) std :: swap(x, y);
      val += Query(dfn[Top[x]], dfn[x], 1), x = fa[Top[x]], val %= p;
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    val += Query(dfn[x], dfn[y], 1);
    return val % p;
  }
  int Query2(int x) {
    return Query(dfn[x], dfn[x] + sz[x] - 1, 1) % p;
  }
}
int main() {
  n = read(), m = read(), rt = read(), p = read();
  for(int i = 1; i <= n; ++ i) val[i] = read();
  for(int i = 1; i < n; ++ i) {
    int u = read(), v = read();
    Heavy_Chain :: Insert(u, v);
    Heavy_Chain :: Insert(v, u);
  }
  Heavy_Chain :: dfs_1(rt, rt);
  Heavy_Chain :: dfs_2(rt, rt);
  Heavy_Chain :: Build(1, n, 1);
  for(int i = 1; i <= m; ++ i) {
    int opt = read(), l = read(), r, k;
    if(opt == 1) r = read(), k = read(), Heavy_Chain :: Up_data_1(l, r, k % p);
    else if(opt == 2) r = read(), printf("%d\n", Heavy_Chain :: Query1(l, r) % p);
    else if(opt == 3) k = read(), Heavy_Chain :: Up_data_2(l, k % p);
    else printf("%d\n", Heavy_Chain :: Query2(l) % p);
  }
  return 0;
}