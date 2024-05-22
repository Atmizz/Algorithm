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
const int MaxN = 1e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, a[MaxN];
namespace Seg {
  struct Node {
    int l, r, lz, sum;
  }t[MaxN<<2];
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
    if(l == r) {
      t[k].sum = a[l];
      return ;
    } int mid = (l + r) >> 1;
    build(l, mid, ls); build(mid+1, r, rs);
    pushup(k);
  }
  void Modify(int l, int r, int k, int z) {
    if(t[k].l >= l && t[k].r <= r) {
      t[k].lz += z;
      t[k].sum += z * (t[k].r - t[k].l + 1);
      return ;
    }
    if(t[k].lz) pushdown(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) Modify(l, r, ls, z);
    if(r > mid) Modify(l, r, rs, z);
    pushup(k);
  }
  int query(int l, int r, int k) {
    if(t[k].l >= l && t[k].r <= r) return t[k].sum;
    if(t[k].lz) pushdown(k);
    int mid = (t[k].l + t[k].r) >> 1, sum = 0;
    if(l <= mid) sum += query(l, r, ls);
    if(r > mid) sum += query(l, r, rs);
    return sum;
  }
}
signed main() {
  n = read(); m = read();
  for(int i = 1; i <= n; ++ i) a[i] = read();
  Seg :: build(1, n, 1);
  for(int i = 1; i <= m; ++ i) {
    int opt = read(), l = read(), r = read(), k;
    if(opt == 1) k = read(), Seg :: Modify(l, r, 1, k);
    else printf("%lld\n", Seg :: query(l, r, 1));
  }
  return 0;
}