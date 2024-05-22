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
namespace LuoguP2486 {
  struct Node {
    int l, r, sum, tag, lz, rz;
  }t[MaxN<<2];
  struct Edge {
    int to, net;
  }e[MaxN<<1];
  int cnt, head[MaxN<<1], w[MaxN], dep[MaxN], top[MaxN], son[MaxN], fa[MaxN], sz[MaxN], dfn[MaxN], dnf, rc, lc;
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
    top[u] = topf; dfn[u] = ++ dnf; w[dnf] = val[u];
    if(son[u]) dfs2(son[u], topf);
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(v == fa[u] || v == son[u]) continue;
      dfs2(v, v);
    }
  }
  void pushdown(int k) {
    t[ls].tag = t[rs].tag = t[k].tag;
    t[ls].sum = t[rs].sum = 1;
    t[ls].lz = t[ls].rz = t[k].lz;
    t[rs].lz = t[rs].rz = t[k].rz;
    t[k].tag = 0;
  }
  void pushup(int k) {
    t[k].sum = t[ls].sum + t[rs].sum;
    if(t[ls].rz == t[rs].lz) t[k].sum --;
    t[k].lz = t[ls].lz; t[k].rz = t[rs].rz;
  }
  void build(int l, int r, int k) {
    t[k].l = l; t[k].r = r;
    if(l == r) {
      t[k].lz = t[k].rz = w[l];
      t[k].sum = t[k].tag = 1;
      return ;
    } int mid = (l + r) >> 1;
    build(l, mid, ls); build(mid+1, r, rs);
    pushup(k);
  }
  void Modify(int l, int r, int k, int x) {
    if(l <= t[k].l && t[k].r <= r) {
      t[k].lz = t[k].rz = x;
      t[k].tag = t[k].sum = 1;
      return ;
    }
    if(t[k].tag) pushdown(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) Modify(l, r, ls, x);
    if(r > mid) Modify(l, r, rs, x);
    pushup(k);
  }
  int query(int l, int r, int k) {
    if(t[k].l == l) lc = t[k].lz;
    if(t[k].r == r) rc = t[k].rz;
    if(l <= t[k].l && t[k].r <= r) return t[k].sum;
    if(t[k].tag) pushdown(k);
    int mid = (t[k].l + t[k].r) >> 1, sum = 0, num = 0;
    if(l <= mid) sum += query(l, r, ls), num ++;
    if(r > mid) sum += query(l, r, rs), num ++;
    if(num == 2 && t[ls].rz == t[rs].lz) sum --;
    return sum;
  }
  void My(int x, int y, int z) {
    while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
      Modify(dfn[top[x]], dfn[x], 1, z); x = fa[top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y);
    Modify(dfn[x], dfn[y], 1, z);
  }
  int Qy(int x, int y) {
    int sum = 0, pos1 = -1, pos2 = -1;
    while(top[x] != top[y]) {
      if(dep[top[x]] < dep[top[y]]) std :: swap(x, y), std :: swap(pos1, pos2);
      sum += query(dfn[top[x]], dfn[x], 1);
      if(rc == pos1) sum --;
      pos1 = lc; x = fa[top[x]];
    }
    if(dep[x] > dep[y]) std :: swap(x, y), std :: swap(pos1, pos2);
    sum += query(dfn[x], dfn[y], 1);
    if(lc == pos1) sum --;
    if(rc == pos2) sum --;
    return sum;
  }
} // namespace LuoguP2486

int main() {
  n = read(); m = read();
  for(int i = 1; i <= n; ++ i) val[i] = read();
  for(int i = 1; i < n; ++ i) {
    int u = read(), v = read();
    LuoguP2486 :: Insert(u, v);
    LuoguP2486 :: Insert(v, u);
  }
  LuoguP2486 :: dfs1(1, 1);
  LuoguP2486 :: dfs2(1, 1);
  LuoguP2486 :: build(1, n, 1);
  for(int i = 1; i <= m; ++ i) {
    char ch; std :: cin >> ch;
    int l = read(), r = read(), x;
    if(ch == 'C') x = read(), LuoguP2486 :: My(l, r, x);
    else printf("%d\n", LuoguP2486 :: Qy(l, r));
  }
  return 0;
}