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
int n, m, p, a[MaxN];
namespace SegTree {
  struct Node {
    int l, r;
    ll lz1, lz2, sum;
  }t[MaxN<<2];
  inline void pushUp(int k) {
    t[k].sum = (t[ls].sum + t[rs].sum) % p;
  }
  inline void pushDown(int k) {
    t[ls].lz1 = t[ls].lz1 * t[k].lz1 % p;
    t[rs].lz1 = t[rs].lz1 * t[k].lz1 % p;
    t[ls].lz2 = t[ls].lz2 * t[k].lz1 % p;
    t[rs].lz2 = t[rs].lz2 * t[k].lz1 % p;
    t[ls].lz2 = (t[ls].lz2 + t[k].lz2) % p;
    t[rs].lz2 = (t[rs].lz2 + t[k].lz2) % p;
    t[ls].sum = (t[ls].sum * t[k].lz1 + t[k].lz2 * (t[ls].r - t[ls].l + 1)) % p;
    t[rs].sum = (t[rs].sum * t[k].lz1 + t[k].lz2 * (t[rs].r - t[rs].l + 1)) % p;
    t[k].lz1 = 1; t[k].lz2 = 0;
  }
  void build(int l, int r, int k) {
    t[k].l = l; t[k].r = r;
    t[k].lz1 = 1; t[k].lz2 = 0;
    if(l == r) {
      t[k].sum = a[l];
      return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls); build(mid+1, r, rs);
    pushUp(k);
  }
  void modify1(int l, int r, int k, int x) {
    if(t[k].l >= l && t[k].r <= r) {
      t[k].lz1 = t[k].lz1 * x % p;
      t[k].lz2 = t[k].lz2 * x % p;
      t[k].sum = t[k].sum * x % p;
      return ;
    }
    if(t[k].lz1 != 1 || t[k].lz2 != 0) pushDown(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) modify1(l, r, ls, x);
    if(r > mid) modify1(l, r, rs, x);
    pushUp(k);
  }
  void modify2(int l, int r, int k, int x) {
    if(t[k].l >= l && t[k].r <= r) {
      t[k].lz2 = (t[k].lz2 + x) % p;
      t[k].sum = (t[k].sum + x * (t[k].r - t[k].l + 1)) % p;
      return ;
    }
    if(t[k].lz1 != 1 || t[k].lz2 != 0) pushDown(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) modify2(l, r, ls, x);
    if(r > mid) modify2(l, r, rs, x);
    pushUp(k);
  }
  int query(int l, int r, int k) {
    if(t[k].l >= l && t[k].r <= r) return t[k].sum % p;
    if(t[k].lz1 != 1 || t[k].lz2 != 0) pushDown(k);
    int mid = (t[k].l + t[k].r) >> 1, sum = 0;
    if(l <= mid) sum = (sum + query(l, r, ls)) % p;
    if(r > mid) sum = (sum + query(l, r, rs)) % p;
    return sum % p;
  }
}
int main() {
  n = read(); m = read(); p = read();
  for(int i = 1; i <= n; ++ i) a[i] = read() % p;
  SegTree :: build(1, n, 1);
  for(int i = 1; i <= m; ++ i) {
    int opt = read(), l = read(), r = read(), x;
    if(opt == 1) x = read(), SegTree :: modify1(l, r, 1, x);
    else if(opt == 2) x = read(), SegTree :: modify2(l, r, 1, x);
    else printf("%d\n", SegTree :: query(l, r, 1));
  }
  return 0;
}