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
int n, m, val[MaxN];
namespace HeavyChain {
  struct Tree {
    int l, r, val, lz;
  }t[MaxN << 2];
  struct Edge {
    int to, net;
  }e[MaxN << 1];
  int head[MaxN << 1], top[MaxN], fa[MaxN], id[MaxN], son[MaxN], dep[MaxN], sz[MaxN], dfn[MaxN], dnf, w[MaxN], cnt;
  inline void Insert(int u, int v) {
    e[++ cnt] = {v, head[u]};
    head[u] = cnt;
  }
  void dfs1(int u, int pa) {
    fa[u] = pa; dep[u] = dep[pa] + 1; sz[u] = 1;
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(v == pa) continue;
      dfs1(v, u);
      sz[u] += sz[v];
      if(!son[u] || sz[v] > sz[son[u]]) son[u] = v;
    }
  }
  void dfs2(int u, int Top) {
    top[u] = Top; dfn[u] = ++ dnf; w[dnf] = val[u];
    if(son[u]) dfs2(son[u], Top);
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(v == son[u] || v == fa[u]) continue;
      dfs2(v, v);
    }
  }
  void pu(int k) {
    t[k].val = t[ls].val + t[rs].val;
  }
  void pd(int k) {
    t[ls].lz = t[k].lz;
    t[rs].lz = t[k].lz;
    t[ls].val = t[k].lz * (t[ls].r - t[ls].l + 1);
    t[rs].val = t[k].lz * (t[rs].r - t[rs].l + 1);
    t[k].lz = -1;
  }
  void build(int l, int r, int k) {
    t[k].l = l; t[k].r = r; t[k].lz = -1;
    if(l == r) {
      t[k].val = w[l];
      return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls); build(mid+1, r, rs);
    pu(k);
  }
  void Modify(int l, int r, int k, int x) {
    if(l <= t[k].l && t[k].r <= r) {
      t[k].lz = x;
      t[k].val = x * (t[k].r - t[k].l + 1);
      return ;
    }
    if(t[k].lz != -1) pd(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) Modify(l, r, ls, x);
    if(r > mid) Modify(l, r, rs, x);
    pu(k);
  }
  int query(int l, int r, int k) {
    if(l <= t[k].l && t[k].r <= r) return t[k].val;
    int mid = (t[k].l + t[k].r) >> 1, sum = 0;
    if(t[k].lz != -1) pd(k);
    if(l <= mid) sum = query(l, r, ls);
    if(r > mid) sum = sum + query(l, r, rs);
    return sum;
  }
  void update1(int x, int y, int k) {
    while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
      Modify(dfn[top[x]], dfn[x], 1, k), x = fa[top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    Modify(dfn[x], dfn[y], 1, k);
  }
  void update2(int x) {
    Modify(dfn[x], dfn[x] + sz[x] - 1, 1, 0);
  }
   int query1(int x, int y) {
    int sum = 0;
    while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
      sum = sum + query(dfn[top[x]], dfn[x], 1), x = fa[top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    sum = sum + query(dfn[x], dfn[y], 1);
    return sum;
  }
  int query2(int x) {
    return query(dfn[x], dfn[x] + sz[x] - 1, 1);
  }
}
int main() {
  n = read();
  for(int i = 2; i <= n; ++ i) {
    int v = read();
    HeavyChain :: Insert(i, v+1);
    HeavyChain :: Insert(v+1, i);
  }
  HeavyChain :: dfs1(1, 1);
  HeavyChain :: dfs2(1, 1);
  HeavyChain :: build(1, n, 1);
  m = read();
  for(int i = 1; i <= m; ++ i) {
    std :: string str; std :: cin >> str;
    int l = read(), sum0; l ++;
    // std :: cout << "sum0 : " << sum0 << '\n';
    if(str == "install") sum0 = HeavyChain :: query1(1, l), HeavyChain :: update1(1, l, 1), printf("%d\n", HeavyChain :: query1(1, l) - sum0);
    else sum0 = HeavyChain :: query2(l), HeavyChain :: update2(l), printf("%d\n", sum0 - HeavyChain :: query2(l));
  }
  return 0;
}