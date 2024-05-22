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
int n, val[MaxN], u[MaxN], v[MaxN];
namespace LuoguP4315 {
  struct Node {
    int l, r, maxn, lz1, lz2;
  }t[MaxN<<2];
  struct Edge {
    int to, net, dis;
  }e[MaxN<<1];
  int cnt, head[MaxN<<1], top[MaxN], dfn[MaxN], dnf, fa[MaxN], son[MaxN], sz[MaxN], dep[MaxN], w[MaxN];
  inline void Insert(int u, int v, int w) {
    e[++cnt] = {v, head[u], w};
    head[u] = cnt;
  }
  void dfs1(int u, int pa) {
    fa[u] = pa; dep[u] = dep[pa] + 1; sz[u] = 1;
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(v == pa) continue;
      val[v] = e[i].dis;
      dfs1(v, u); sz[u] += sz[v];
      if(!son[u] || sz[son[u]] < sz[v]) son[u] = v;
    }
  }
  void dfs2(int u, int topf) {
    top[u] = topf; dfn[u] = ++ dnf; w[dnf] = val[u];
    if(son[u]) dfs2(son[u], topf);
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(v == fa[u] || v == son[u]) continue;
      dfs2(v, v);
    }
  }
  void pushup(int k) {
    t[k].maxn = max(t[ls].maxn, t[rs].maxn);
  }
  void pushdown(int k) {
    if(t[k].lz1 == -1) {
      t[ls].maxn += t[k].lz2;
      t[rs].maxn += t[k].lz2;
      t[ls].lz2 += t[k].lz2;
      t[rs].lz2 += t[k].lz2;
      if(t[ls].lz1 != -1) t[ls].lz1 += t[k].lz2;
      if(t[rs].lz1 != -1) t[rs].lz1 += t[k].lz2;
    } else {
      t[ls].maxn = t[k].lz1;
      t[rs].maxn = t[k].lz1;
      t[ls].lz1 = t[k].lz1;
      t[rs].lz1 = t[k].lz1;
      t[ls].lz2 = t[rs].lz2 = 0;
    } t[k].lz1 = -1; t[k].lz2 = 0;
  }
  void build(int l, int r, int k) {
    t[k].l = l; t[k].r = r; t[k].lz1 = -1;
    if(l == r) {
      t[k].maxn = w[l];
      return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls); build(mid+1, r, rs);
    pushup(k);
  }
  void change(int l, int r, int k, int x) {
    if(l <= t[k].l && t[k].r <= r) {
      t[k].maxn = t[k].lz1 = x; t[k].lz2 = 0;
      return ;
    }
    pushdown(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) change(l, r, ls, x);
    if(r > mid) change(l, r, rs, x);
    pushup(k);
  }
  void add(int l, int r, int k, int x) {
    if(l <= t[k].l && t[k].r <= r) {
      if(t[k].lz1 != -1) t[k].lz1 += x;
      t[k].lz2 += x;
      t[k].maxn += x;
      return ;
    }
    pushdown(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) add(l, r, ls, x);
    if(r > mid) add(l, r, rs, x);
    pushup(k);
  }
  int query(int l, int r, int k) {
    if(l <= t[k].l && t[k].r <= r) return t[k].maxn;
    pushdown(k);
    int mid = (t[k].l + t[k].r) >> 1, maxn = -INF;
    if(l <= mid) maxn = max(maxn, query(l, r, ls));
    if(r > mid) maxn = max(maxn, query(l, r, rs));
    return maxn;
  }
  void Change(int l, int r) {
    int x = u[l], y = v[l];
    while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
      change(dfn[top[x]], dfn[x], 1, r);
      x = fa[top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    change(dfn[x] + 1, dfn[y], 1, r);
  }
  void Cover(int x, int y, int z) {
    while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
      change(dfn[top[x]], dfn[x], 1, z);
      x = fa[top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    change(dfn[x] + 1, dfn[y], 1, z);
  }
  void Add(int x, int y, int z) {
    while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
      add(dfn[top[x]], dfn[x], 1, z);
      x = fa[top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    add(dfn[x] + 1, dfn[y], 1, z);
  }
  int Max(int x, int y) {
    int maxx = -INF;
    while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
      maxx = max(maxx, query(dfn[top[x]], dfn[x], 1));
      x = fa[top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    maxx = max(maxx, query(dfn[x] + 1, dfn[y], 1));
    return maxx;
  }
} // namespace LuoguP4315

int main() {
  n = read();
  for(int i = 1; i < n; ++ i) {
    u[i] = read(), v[i] = read(); int w = read();
    LuoguP4315 :: Insert(u[i], v[i], w);
    LuoguP4315 :: Insert(v[i], u[i], w);
  }
  LuoguP4315 :: dfs1(1, 1);
  LuoguP4315 :: dfs2(1, 1);
  LuoguP4315 :: build(1, n, 1);
  while(1) {
    std :: string str; int x, y, z;
    std :: cin >> str;
    if(str == "Stop") break;
    x = read(), y = read();
    if(str == "Change") LuoguP4315 :: Change(x, y);
    else if(str == "Cover") z = read(), LuoguP4315 :: Cover(x, y, z);
    else if(str == "Add") z = read(), LuoguP4315 :: Add(x, y, z);
    else printf("%d\n", LuoguP4315 :: Max(x, y));
  }
  return 0;
}