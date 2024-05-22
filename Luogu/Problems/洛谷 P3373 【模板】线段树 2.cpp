#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
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
const int MaxN = 1e5+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m;
ll a[MaxN], p;
namespace Seg_2 {
  struct Node {
    int l, r;
    ll mul, plus, val;
  }t[MaxN << 2];
  inline void Push_Up(int k) {
    t[k].val = (t[ls].val + t[rs].val) % p;
  }
  inline void Push_Down(int k) {
    t[ls].val = (t[ls].val * t[k].mul + (t[k].plus * (t[ls].r - t[ls].l + 1)) % p) % p;
    t[rs].val = (t[rs].val * t[k].mul + (t[k].plus * (t[rs].r - t[rs].l + 1)) % p) % p;
    t[ls].mul = (t[ls].mul * t[k].mul) % p;
    t[rs].mul = (t[rs].mul * t[k].mul) % p;
    t[ls].plus = (t[ls].plus * t[k].mul + t[k].plus) % p;
    t[rs].plus = (t[rs].plus * t[k].mul + t[k].plus) % p;
    t[k].mul = 1; t[k].plus = 0;
  }
  void Build(int l, int r, int k) {
    t[k].l = l; t[k].r = r; t[k].mul = 1;
    if(l == r) {
      t[k].val = a[l] % p;
      return ;
    }
    int mid = (t[k].l + t[k].r) >> 1;
    Build(l, mid, ls);
    Build(mid+1, r, rs);
    Push_Up(k);
  }
  void Multiply(int l, int r, int k, ll x) {
    if(l <= t[k].l && t[k].r <= r) {
      t[k].val = (t[k].val * x) % p;
      t[k].mul = (t[k].mul * x) % p;
      t[k].plus = (t[k].plus * x) % p;
      return ;
    } Push_Down(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) Multiply(l, r, ls, x);
    if(r > mid) Multiply(l, r, rs, x);
    Push_Up(k);
  }
  void Plus(int l, int r, int k, ll x) {
    if(l <= t[k].l && t[k].r <= r) {
      t[k].plus = (t[k].plus + x) % p;
      t[k].val = (t[k].val + (t[k].r - t[k].l + 1) * x) % p;
      return ;
    } Push_Down(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) Plus(l, r, ls, x);
    if(r > mid) Plus(l, r, rs, x);
    Push_Up(k);
  }
  ll Query(int l, int r, int k) {
    if(l <= t[k].l && t[k].r <= r) return t[k].val % p;
    Push_Down(k); ll val = 0;
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) val = (val + Query(l, r, ls)) % p;
    if(r > mid) val = (val + Query(l, r, rs)) % p;
    return val % p;
  }
}
int main() {
  n = read(); m = read(); scanf("%lld", &p);
  for(int i = 1; i <= n; ++ i)
    scanf("%lld", &a[i]);
  Seg_2 :: Build(1, n, 1);
  for(int i = 1; i <= m; ++ i) {
    int opt = read(), l = read(), r = read(); ll k;
    if(opt == 1) scanf("%lld", &k), Seg_2 :: Multiply(l, r, 1, k);
    else if(opt == 2) scanf("%lld", &k), Seg_2 :: Plus(l, r, 1, k);
    else printf("%lld\n", Seg_2 :: Query(l, r, 1));
  }
  return 0;
}