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
int n, m;
namespace LuoguP3038 {
  struct Node {
    int l, r, sum, lz;
  }t[MaxN << 2];
  struct Edge {
    int to, net;
  }e[MaxN << 1];
  int head[MaxN<<1], cnt, son[MaxN], top[MaxN], fa[MaxN], sz[MaxN], dep[MaxN], dfn[MaxN], dnf;
  inline void Insert(int u, int v) {
    e[++cnt] = {v, head[u]};
    head[u] = cnt;
  }
  void dfs1(int u, int pa) {
    fa[u] = pa; dep[u] = dep[pa] + 1; sz[u] = 1;
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(v == pa) continue;
      dfs1(v, u); sz[u] += sz[v];
      if(!son[u] || sz[son[u]] < sz[v]) son[u] = v;
    }
  }
  void dfs2(int u, int topf) {
    top[u] = topf; dfn[u] = ++dnf;
    if(son[u]) dfs2(son[u], topf);
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(v == son[u] || v == fa[u]) continue;
      dfs2(v, v);
    }
  }
  inline void pushup(int k) {
    t[k].sum = t[ls].sum + t[rs].sum;
  }
  inline void pushdown(int k) {
    t[ls].lz += t[k].lz; t[rs].lz += t[k].lz;
    t[ls].sum += t[k].lz * (t[ls].r - t[ls].l + 1);
    t[rs].sum += t[k].lz * (t[rs].r - t[rs].l + 1);
    t[k].lz = 0;
  }
  void build(int l, int r, int k) {
    t[k].l = l; t[k].r = r;
    if(l == r) return ;
    int mid = (l + r) >> 1;
    build(l, mid, ls); build(mid+1, r, rs);
    pushup(k);
  }
  void Modify(int l, int r, int k, int x) {
    if(l <= t[k].l && t[k].r <= r) {
      t[k].lz += x;
      t[k].sum += x * (t[k].r - t[k].l + 1);
      return ;
    }
    if(t[k].lz) pushdown(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) Modify(l, r, ls, x);
    if(r > mid) Modify(l, r, rs, x);
    pushup(k);
  }
  int query(int l, int r, int k) {
    if(t[k].l >= l && t[k].r <= r) return t[k].sum;
    if(t[k].lz) pushdown(k);
    int sum = 0; int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) sum += query(l, r, ls);
    if(r > mid) sum += query(l, r, rs);
    return sum;
  }
  void Update(int x, int y) {
    while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
      Modify(dfn[top[x]], dfn[x], 1, 1); x = fa[top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    if(dfn[x] < dfn[y]) Modify(dfn[x] + 1, dfn[y], 1, 1);
  }
  int Query(int x, int y) {
    int res = 0;
    while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
      res += query(dfn[top[x]], dfn[x], 1); x = fa[top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    if(dfn[x] < dfn[y]) res += query(dfn[x] + 1, dfn[y], 1);
    return res;
  }
} // namespace LuoguP3038

int main() {
  n = read(); m = read();
  for(int i = 1; i < n; ++ i) {
    int u = read(), v = read();
    LuoguP3038 :: Insert(u, v);
    LuoguP3038 :: Insert(v, u);
  }
  LuoguP3038 :: dfs1(1, 1);
  LuoguP3038 :: dfs2(1, 1);
  LuoguP3038 :: build(1, n, 1);
  for(int i = 1; i <= m; ++ i) {
    char ch; int x, y;
    std :: cin >> ch; x = read(); y = read();
    if(ch == 'P') LuoguP3038 :: Update(x, y);
    else printf("%d\n", LuoguP3038 :: Query(x, y));
  }
  return 0;
}