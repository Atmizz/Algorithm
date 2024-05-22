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
const ll Mod = 0x7f7f7f7f7f7f7f7f;
const int INF = 2147483647;
int n, m;
ll a[MaxN];
namespace SegTree {
  struct Node {
    ll sum, maxx;
    int l, r;
  }t[MaxN<<2];
  inline void pushUp(int k) {
    t[k].sum = t[ls].sum + t[rs].sum;
    t[k].maxx = std :: max(t[ls].maxx, t[rs].maxx);
  }
  void build(int l, int r, int k) {
    t[k].l = l; t[k].r = r;
    if(l == r) {
      t[k].sum = t[k].maxx = a[l];
      return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls); build(mid+1, r, rs);
    pushUp(k);
  }
  void modify(int l, int r, int k, ll x) {
    if(t[k].l == t[k].r) {
      t[k].sum = t[k].maxx = x;
      return ;
    } int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) modify(l, r, ls, x);
    if(r > mid) modify(l, r, rs, x);
    pushUp(k);
  }
  void modifyMod(int l, int r, int k, ll x) {
    if(t[k].maxx < x) return ;
    if(t[k].l == t[k].r) {
      t[k].sum %= x;
      t[k].maxx %= x;
      return ;
    } int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) modifyMod(l, r, ls, x);
    if(r > mid) modifyMod(l, r, rs, x);
    pushUp(k);
  }
  ll query(int l, int r, int k) {
    if(t[k].l >= l && t[k].r <= r) return t[k].sum;
    int mid = (t[k].l + t[k].r) >> 1; ll sum = 0;
    if(l <= mid) sum += query(l, r, ls);
    if(r > mid) sum += query(l, r, rs);
    return sum;
  }
}
int main() {
  n = read(); m = read();
  for(int i = 1; i <= n; ++ i) scanf("%lld", &a[i]);
  SegTree :: build(1, n, 1);
  for(int i = 1; i <= m; ++ i) {
    ll opt = read(), l = read(), r = read(); ll x;
    if(opt == 1) std :: cout << SegTree :: query(l, r, 1) << '\n';
    else if(opt == 2) {
      std :: cin >> x;
      SegTree :: modifyMod(l, r, 1, x);
    }
    else SegTree :: modify(l, l, 1, r);
  }
  return 0;
}