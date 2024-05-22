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
const int MaxN = 3e4 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, q, val[MaxN];
namespace LuoguP2590 {
  struct Node {
    int l, r, maxn, sum;
  }t[MaxN << 2];
  struct Edge {
    int to, net;
  }e[MaxN << 1];
  int w[MaxN], top[MaxN], head[MaxN<<1], cnt, dfn[MaxN], dnf, son[MaxN], sz[MaxN], dep[MaxN], fa[MaxN];
  inline void Insert(int u, int v) {
    e[++cnt] = (Edge){v, head[u]};
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
    top[u] = topf; dfn[u] = ++ dnf; w[dnf] = val[u];
    if(son[u]) dfs2(son[u], topf);
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(v == son[u] || v == fa[u]) continue;
      dfs2(v, v);
    }
  }
  void pushup(int k) {
    t[k].sum = t[ls].sum + t[rs].sum;
    t[k].maxn = max(t[ls].maxn, t[rs].maxn);
  }
  void build(int l, int r, int k) {
    t[k].l = l; t[k].r = r;
    if(l == r) {
      t[k].sum = t[k].maxn = w[l];
      return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls); build(mid+1, r, rs);
    pushup(k);
  }
  void ModifyMax(int l, int r, int k, int x) {
    if(t[k].l >= l && t[k].r <= r) {
      t[k].maxn = t[k].sum = x;
      return ;
    }
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) ModifyMax(l, r, ls, x);
    if(r > mid) ModifyMax(l, r, rs, x);
    pushup(k);
  }
  int query(int l, int r, int k) {
    if(t[k].l >= l && t[k].r <= r) return t[k].sum;
    int sum = 0, mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) sum += query(l, r, ls);
    if(r > mid) sum += query(l, r, rs);
    return sum;
  }
  int queryMax(int l, int r, int k) {
    if(t[k].l >= l && t[k].r <= r) return t[k].maxn;
    int maxn = -INF, mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) maxn = max(maxn, queryMax(l, r, ls));
    if(r > mid) maxn = max(maxn, queryMax(l, r, rs));
    return maxn;
  }
  void Update(int l, int r) {
    ModifyMax(dfn[l], dfn[l], 1, r);
  }
  int query1(int x, int y) {
    int sum = 0;
    while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
      sum += query(dfn[top[x]], dfn[x], 1); x = fa[top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    sum += query(dfn[x], dfn[y], 1);
    return sum;
  }
  int query2(int x, int y) {
    int maxn = -INF;
    while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
      maxn = max(maxn, queryMax(dfn[top[x]], dfn[x], 1)), x = fa[top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    maxn = max(maxn, queryMax(dfn[x], dfn[y], 1));
    return maxn;
  }
} // namespace LuoguP2590
int main() {
  n = read();
  for(int i = 1; i < n; ++ i) {
    int u = read(), v = read();
    LuoguP2590 :: Insert(u, v);
    LuoguP2590 :: Insert(v, u);
  }
  for(int i = 1; i <= n; ++ i) val[i] = read();
  LuoguP2590 :: dfs1(1, 1);
  LuoguP2590 :: dfs2(1, 1);
  LuoguP2590 :: build(1, n, 1);
  q = read();
  while(q --) {
    std :: string str; int l, r;
    std :: cin >> str; l = read(); r = read();
    if(str == "CHANGE") LuoguP2590 :: Update(l, r);
    else if(str == "QMAX") printf("%d\n", LuoguP2590 :: query2(l, r));
    else printf("%d\n", LuoguP2590 :: query1(l, r));
  }
  return 0;
}