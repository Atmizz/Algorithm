#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
#define int long long
typedef long long ll;
inline int read() {
  int s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 2e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, u[MaxN<<1], v[MaxN<<1];
namespace LuoguP1510 {
  struct Node {
    int l, r, minn, maxx, sum, lz;
  }t[MaxN << 2];
  struct Edge {
    int to, net, val;
  }e[MaxN << 1];
  int val[MaxN], head[MaxN << 1], cnt, w[MaxN], son[MaxN], dep[MaxN], fa[MaxN], top[MaxN], dfn[MaxN], dnf, sz[MaxN];
  inline void Insert(int u, int v, int w) {
    e[++cnt] = {v, head[u], w};
    head[u] = cnt;
  }
  void dfs1(int u, int pa) {
    fa[u] = pa; dep[u] = dep[pa] + 1; sz[u] = 1;
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(v == pa) continue;
      val[v] = e[i].val;
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
  void pushdown(int k) {
    t[ls].sum = -t[ls].sum;
    std :: swap(t[ls].minn, t[ls].maxx);
    t[ls].minn = -t[ls].minn;
    t[ls].maxx = -t[ls].maxx;
    t[rs].sum = -t[rs].sum;
    std :: swap(t[rs].minn, t[rs].maxx);
    t[rs].minn = -t[rs].minn;
    t[rs].maxx = -t[rs].maxx;
    t[ls].lz ^= 1; t[rs].lz ^= 1;
    t[k].lz = 0;
  }
  void pushup(int k) {
    t[k].sum = t[ls].sum + t[rs].sum;
    t[k].maxx = max(t[ls].maxx, t[rs].maxx);
    t[k].minn = min(t[ls].minn, t[rs].minn);
  }
  void build(int l, int r, int k) {
    t[k].l = l; t[k].r = r;
    if(l == r) {
      t[k].sum = t[k].maxx = t[k].minn = w[l];
      return ;
    } int mid = (l + r) >> 1;
    build(l, mid, ls); build(mid+1, r, rs);
    pushup(k);
  }
  void Modify(int l, int r, int k, int x) {
    if(l <= t[k].l && t[k].r <= r) {
      t[k].sum = t[k].maxx = t[k].minn = x;
      return ;
    }
    if(t[k].lz) pushdown(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) Modify(l, r, ls, x);
    if(r > mid) Modify(l, r, rs, x);
    pushup(k);
  }
  void Modify2(int l, int r, int k) {
    if(l <= t[k].l && t[k].r <= r) {
      t[k].lz ^= 1; t[k].sum = -t[k].sum;
      std :: swap(t[k].maxx, t[k].minn);
      t[k].maxx = -t[k].maxx;
      t[k].minn = -t[k].minn;
      return ;
    } if(t[k].lz) pushdown(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) Modify2(l, r, ls);
    if(r > mid) Modify2(l, r, rs);
    pushup(k);
  }
  int queryMax(int l, int r, int k) {
    if(t[k].l >= l && t[k].r <= r) return t[k].maxx;
    if(t[k].lz) pushdown(k);
    int mid = (t[k].l + t[k].r) >> 1;
    int maxx = -INF;
    if(l <= mid) maxx = max(maxx, queryMax(l, r, ls));
    if(r > mid) maxx = max(maxx, queryMax(l, r, rs));
    return maxx;
  }
  int queryMin(int l, int r, int k) {
    if(t[k].l >= l && t[k].r <= r) return t[k].minn;
    if(t[k].lz) pushdown(k);
    int mid = (t[k].l + t[k].r) >> 1;
    int minn = INF;
    if(l <= mid) minn = min(minn, queryMin(l, r, ls));
    if(r > mid) minn = min(minn, queryMin(l, r, rs));
    return minn;
  }
  int querySum(int l, int r, int k) {
    if(t[k].l >= l && t[k].r <= r) return t[k].sum;
    if(t[k].lz) pushdown(k);
    int mid = (t[k].l + t[k].r) >> 1;
    int sum = 0;
    if(l <= mid) sum = sum + querySum(l, r, ls);
    if(r > mid) sum = sum + querySum(l, r, rs);
    return sum;
  }
  void M1(int l, int r) {
    int x = u[l], y = v[l];
    while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
      Modify(dfn[top[x]], dfn[x], 1, r); x = fa[top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    if(dfn[x] < dfn[y]) Modify(dfn[x] + 1, dfn[y], 1, r);
  }
  void M2(int x, int y) {
    while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
      Modify2(dfn[top[x]], dfn[x], 1); x = fa[top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    if(dfn[x] < dfn[y]) Modify2(dfn[x] + 1, dfn[y], 1);
  }
  int QSum(int x, int y) {
    int sum = 0;
    while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
      sum += querySum(dfn[top[x]], dfn[x], 1); x = fa[top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    if(dfn[x] < dfn[y]) sum += querySum(dfn[x] + 1, dfn[y], 1);
    return sum;
  }
  int QMax(int x, int y) {
    int maxx = -INF;
    while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
      maxx = max(maxx, queryMax(dfn[top[x]], dfn[x], 1));
      x = fa[top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    if(dfn[x] < dfn[y]) maxx = max(maxx, queryMax(dfn[x] + 1, dfn[y], 1));
    return maxx;
  }
  int QMin(int x, int y) {
    int minn = INF;
    while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
      minn = min(minn, queryMin(dfn[top[x]], dfn[x], 1));
      x = fa[top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    if(dfn[x] < dfn[y]) minn = min(minn, queryMin(dfn[x] + 1, dfn[y], 1));
    return minn;
  }
} // namespace LuoguP1510

signed main() {
  n = read();
  for(int i = 1; i < n; ++ i) {
    u[i] = read() + 1, v[i] = read() + 1; int w = read();
    LuoguP1510 :: Insert(u[i], v[i], w);
    LuoguP1510 :: Insert(v[i], u[i], w);
  }
  LuoguP1510 :: dfs1(1, 1);
  LuoguP1510 :: dfs2(1, 1);
  LuoguP1510 :: build(1, n, 1);
  m = read();
  for(int i = 1; i <= m; ++ i) {
    std :: string str; std :: cin >> str;
    int l = read(), r = read();
    if(str == "SUM") printf("%lld\n", LuoguP1510 :: QSum(l+1, r+1));
    else if(str == "C") LuoguP1510 :: M1(l, r);
    else if(str == "N") LuoguP1510 :: M2(l+1, r+1);
    else if(str == "MAX") printf("%lld\n", LuoguP1510 :: QMax(l+1, r+1));
    else printf("%lld\n", LuoguP1510 :: QMin(l+1, r+1));
  }
  return 0;
}