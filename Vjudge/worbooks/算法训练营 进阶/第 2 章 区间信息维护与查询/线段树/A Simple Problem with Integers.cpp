#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
#include <bitset>
#include <complex>
#include <cstdlib>
#include <set>
#include <cstring>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define i64 long long;
#define gc getchar()
typedef long long ll;
inline int read() {
  int s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
const int MaxN = 1e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m;
ll a[MaxN];
namespace SegTree {
  struct Node {
    ll sum, lz;
    int l, r;
  }t[MaxN<<2];
  inline void pushUp(int k) {
    t[k].sum = t[ls].sum + t[rs].sum;
  }
  inline void pushDown(int k) {
    t[ls].lz += t[k].lz;
    t[ls].sum += t[k].lz * (t[ls].r - t[ls].l + 1);
    t[rs].lz += t[k].lz;
    t[rs].sum += t[k].lz * (t[rs].r - t[rs].l + 1);
    t[k].lz = 0;
  }
  void build(int l, int r, int k) {
    t[k].l = l; t[k].r = r;
    if(l == r) {
      t[k].sum = a[l];
      return ;
    }
    int mid = (l + r) >> 1;
    build(l, mid, ls); build(mid+1, r, rs);
    pushUp(k);
  }
  void modify(int l, int r, int k, ll x) {
    if(l <= t[k].l && r >= t[k].r) {
      t[k].sum += x * (t[k].r - t[k].l + 1);
      t[k].lz += x;
      return ;
    } int mid = (t[k].l + t[k].r) >> 1;
    if(t[k].lz) pushDown(k);
    if(l <= mid) modify(l, r, ls, x);
    if(r > mid) modify(l, r, rs, x);
    pushUp(k);
  }
  ll query(int l, int r, int k) {
    if(t[k].l >= l && t[k].r <= r) return t[k].sum;
    int mid = (t[k].l + t[k].r) >> 1; ll sum = 0;
    if(t[k].lz) pushDown(k);
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
    char opt; std :: cin >> opt;
    int l = read(), r = read(); ll x;
    if(opt == 'C') {
      scanf("%lld", &x);
      SegTree :: modify(l, r, 1, x);
    } else printf("%lld\n", SegTree :: query(l, r, 1));
  }
  return 0;
}