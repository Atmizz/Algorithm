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
const int MaxN = 1e6 + 200;
const int Mod = 10007;
const int INF = 2147483647;
struct Node {
  int l, r;
  ll sum1, sum2, sum3;
  ll add, mul, alt;
}t[MaxN << 2];
int n, m;
void pushUp(int k) {
  t[k].sum1 = (t[ls].sum1 + t[rs].sum1) % Mod;
  t[k].sum2 = (t[ls].sum2 + t[rs].sum2) % Mod;
  t[k].sum3 = (t[ls].sum3 + t[rs].sum3) % Mod;
}
void pd_alt(int k, int c) {
  c %= Mod;
  t[k].sum1 = (t[k].r - t[k].l + 1) * c % Mod;
  t[k].sum2 = (t[k].r - t[k].l + 1) * c % Mod * c % Mod;
  t[k].sum3 = (t[k].r - t[k].l + 1) * c % Mod * c % Mod * c % Mod;
  t[k].alt = c, t[k].add = 0, t[k].mul = 1;
}
void pd_mul(int k, int c) {
  c %= Mod;
  t[k].sum1 = t[k].sum1 * c % Mod;
  t[k].sum2 = t[k].sum2 * c % Mod * c % Mod;
  t[k].sum3 = t[k].sum3 * c % Mod * c % Mod * c % Mod;
  t[k].mul = t[k].mul * c % Mod;
  t[k].add = t[k].add * c % Mod;
}
void pd_add(int k, int c) {
  c %= Mod;
  t[k].sum3 = (t[k].sum3 % Mod + 3 * c % Mod * t[k].sum2 % Mod + 3 * c % Mod * c % Mod * t[k].sum1 % Mod + (t[k].r - t[k].l + 1) * c % Mod * c % Mod * c % Mod) % Mod;
  t[k].sum2 = (t[k].sum2 % Mod + 2 * c % Mod * t[k].sum1 % Mod + (t[k].r - t[k].l + 1) * c % Mod * c % Mod) % Mod;
  t[k].sum1 = (t[k].sum1 % Mod + (t[k].r - t[k].l + 1) * c % Mod) % Mod;
  t[k].add = (t[k].add + c) % Mod;
}
void pushDown(int k) {
  if(t[k].alt != 0) {
    pd_alt(ls, t[k].alt);
    pd_alt(rs, t[k].alt);
    t[k].alt = 0;
  } if(t[k].mul != 1) {
    pd_mul(ls, t[k].mul);
    pd_mul(rs, t[k].mul);
    t[k].mul = 1;
  } if(t[k].add != 0) {
    pd_add(ls, t[k].add);
    pd_add(rs, t[k].add);
    t[k].add = 0;
  }
}
void build(int l, int r, int k) {
  t[k].l = l; t[k].r = r;
  t[k].add = t[k].alt = 0; t[k].mul = 1;
  t[k].sum1 = t[k].sum2 = t[k].sum3 = 0;
  if(l == r) return ;
  int mid = (l + r) >> 1;
  build(l, mid, ls); build(mid+1, r, rs);
  pushUp(k);
}
void Add(int l, int r, int k, int c) {
  if(t[k].l >= l && t[k].r <= r) {
    pd_add(k, c % Mod);
    return ;
  }
  pushDown(k);
  int mid = (t[k].l + t[k].r) >> 1;
  if(l <= mid) Add(l, r, ls, c);
  if(r > mid) Add(l, r, rs, c);
  pushUp(k);
}
void Mul(int l, int r, int k, int c) {
  if(t[k].l >= l && t[k].r <= r) {
    pd_mul(k, c % Mod);
    return ;
  }
  pushDown(k);
  int mid = (t[k].l + t[k].r) >> 1;
  if(l <= mid) Mul(l, r, ls, c);
  if(r > mid) Mul(l, r, rs, c);
  pushUp(k);
}
void Alt(int l, int r, int k, int c) {
  if(t[k].l >= l && t[k].r <= r) {
    pd_alt(k, c % Mod);
    return ;
  }
  pushDown(k);
  int mid = (t[k].l + t[k].r) >> 1;
  if(l <= mid) Alt(l, r, ls, c);
  if(r > mid) Alt(l, r, rs, c);
  pushUp(k);
}
int Query(int l, int r, int k, int c) {
  if(t[k].l >= l && t[k].r <= r) {
    if(c == 1) return t[k].sum1;
    if(c == 2) return t[k].sum2;
    if(c == 3) return t[k].sum3;
  }
  pushDown(k);
  int mid = (t[k].l + t[k].r) >> 1, sum = 0;
  if(l <= mid) sum = (sum + Query(l, r, ls, c)) % Mod;
  if(r > mid) sum = (sum + Query(l, r, rs, c)) % Mod;
  return sum % Mod;
}
int main() {
  while(1) {
    n = read(); m = read();
    if(!n || !m) break;
    build(1, n, 1);
    for(int i = 1; i <= m; ++ i) {
      int opt = read(), l = read(), r = read(), c = read();
      if(opt == 1) Add(l, r, 1, c);
      else if(opt == 2) Mul(l, r, 1, c);
      else if(opt == 3) Alt(l, r, 1, c);
      else printf("%d\n", Query(l, r, 1, c) % Mod);
    }
  }
  return 0;
}