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
const int MaxN = 1e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, p, rt, val[MaxN];
namespace HeavyChain {
  struct Node {
    int l, r, sum, lz;
  }t[MaxN << 2];
  struct Edge {
    int to, net;
  }e[MaxN << 1];
  int head[MaxN<<1], dep[MaxN], cnt, son[MaxN], top[MaxN], fa[MaxN], id[MaxN], sz[MaxN], dfn[MaxN], dnf, w[MaxN];
  inline void Insert(int u, int v) {
    e[++cnt] = {v, head[u]};
    head[u] = cnt;
  }
  void dfs1(int u, int pa) {
    fa[u] = pa; dep[u] = dep[pa] + 1; sz[u] = 1;
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(v == pa) continue;
      dfs1(v, u);
      sz[u] += sz[v];
      if(!son[u] || sz[son[u]] < sz[v]) son[u] = v;
    }
  }
  void dfs2(int u, int topf) {
    top[u] = topf; dfn[u] = ++ dnf; w[dnf] = val[u];
    if(son[u]) dfs2(son[u], topf);
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(v == son[u] || v == fa[u]) continue;
      dfs2(v, v);
    }
  }
  inline void pushup(int k) {
    t[k].sum = (t[ls].sum + t[rs].sum) % p;
  }
  inline void pushdown(int k) {
    t[ls].lz = (t[k].lz + t[ls].lz) % p; t[rs].lz = (t[k].lz + t[rs].lz) % p;
    t[ls].sum = (t[ls].sum + t[k].lz * (t[ls].r - t[ls].l + 1)) % p;
    t[rs].sum = (t[rs].sum + t[k].lz * (t[rs].r - t[rs].l + 1)) % p;
    t[k].lz = 0;
  }
  void build(int l, int r, int k) {
    t[k].l = l; t[k].r = r;
    if(l == r) {
      t[k].sum = w[l];
      return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls); build(mid+1, r, rs);
    pushup(k);
  }
  void Modify(int l, int r, int k, int x) {
    if(l <= t[k].l && t[k].r <= r) {
      t[k].lz = (t[k].lz + x) % p;
      t[k].sum = (t[k].sum + x * (t[k].r - t[k].l + 1)) % p;
      return ;
    }
    if(t[k].lz) pushdown(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) Modify(l, r, ls, x);
    if(r > mid) Modify(l, r, rs, x);
    pushup(k);
  }
  int query(int l, int r, int k) {
    if(l <= t[k].l && t[k].r <= r) return t[k].sum % p;
    if(t[k].lz) pushdown(k);
    int mid = (t[k].l + t[k].r) >> 1, sum = 0;
    if(l <= mid) sum = (sum + query(l, r, ls)) % p;
    if(r > mid) sum = (sum + query(l, r, rs)) % p;
    return sum;
  }
  void update1(int x, int y, int k) {
    while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
      Modify(dfn[top[x]], dfn[x], 1, k); x = fa[top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    Modify(dfn[x], dfn[y], 1, k);
  }
  void update2(int x, int k) {
    Modify(dfn[x], dfn[x] + sz[x] - 1, 1, k);
  }
  int query1(int x, int y) {
    int sum = 0;
    while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
      sum = (sum + query(dfn[top[x]], dfn[x], 1)) % p, x = fa[top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    sum = (sum + query(dfn[x], dfn[y], 1)) % p;
    return sum;
  }
  int query2(int x) {
    return query(dfn[x], dfn[x] + sz[x] - 1, 1) % p;
  }
}
int main() {
  n = read(); m = read(); rt = read(); p = read();
  for(int i = 1; i <= n; ++ i) val[i] = read();
  for(int i = 1; i < n; ++ i) {
    int u = read(), v = read();
    HeavyChain :: Insert(u, v);
    HeavyChain :: Insert(v, u);
  }
  HeavyChain :: dfs1(rt, rt);
  HeavyChain :: dfs2(rt, rt);
  HeavyChain :: build(1, n, 1);
  for(int i = 1; i <= m; ++ i) {
    int opt = read(), l = read(), r, x;
    if(opt == 1) r = read(), x = read(), HeavyChain :: update1(l, r, x % p);
    else if(opt == 2) r = read(), printf("%d\n", HeavyChain :: query1(l, r));
    else if(opt == 3) x = read(), HeavyChain :: update2(l, x % p);
    else printf("%d\n", HeavyChain :: query2(l));
  }
  return 0;
}