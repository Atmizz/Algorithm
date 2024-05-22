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
const int MaxN = 1e5+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
struct Node {
  int l, r;
  ll sum, lazy1, lazy2;
}t[MaxN<<2];
int n, p, m, a[MaxN];
void pushUp(int k) {
  t[k].sum = (t[ls].sum + t[rs].sum) % p;
}
void pushDown(int k) {
  t[ls].lazy1 = (t[ls].lazy1 * t[k].lazy1) % p;
  t[rs].lazy1 = (t[rs].lazy1 * t[k].lazy1) % p;
  t[ls].lazy2 = (t[ls].lazy2 * t[k].lazy1 + t[k].lazy2) % p;
  t[rs].lazy2 = (t[rs].lazy2 * t[k].lazy1 + t[k].lazy2) % p;
  t[ls].sum = ((t[ls].sum * t[k].lazy1) % p + (t[k].lazy2 * (t[ls].r - t[ls].l + 1))) % p;
  t[rs].sum = ((t[rs].sum * t[k].lazy1) % p + (t[k].lazy2 * (t[rs].r - t[rs].l + 1))) % p;
  t[k].lazy1 = 1; t[k].lazy2 = 0;
}
void build(int l, int r, int k) {
  t[k].l = l; t[k].r = r; t[k].lazy1 = 1;
  if(l == r) {
    t[k].sum = a[l] % p;
    return ;
  } int mid = (l + r) >> 1;
  build(l, mid, ls); build(mid+1, r, rs);
  pushUp(k);
}
void modify1(int l, int r, int k, int x) {
  // std :: cout << t[k].l << " " << t[k].r << '\n';
  if(l <= t[k].l && t[k].r <= r) {
    t[k].sum = (t[k].sum * x) % p;
    t[k].lazy1 = (t[k].lazy1 * x) % p;
    t[k].lazy2 = (t[k].lazy2 * x) % p;
    return ;
  } pushDown(k);
  int mid = (t[k].l + t[k].r) >> 1;
  if(l <= mid) modify1(l, r, ls, x);
  if(r > mid) modify1(l, r, rs, x);
  pushUp(k);
}
void modify2(int l, int r, int k, int x) {
  if(l <= t[k].l && t[k].r <= r) {
    t[k].sum = (t[k].sum + (t[k].r - t[k].l + 1) * x) % p;
    t[k].lazy2 = (t[k].lazy2 + x) % p;
    return ;
  } pushDown(k);
  int mid = (t[k].l + t[k].r) >> 1;
  if(l <= mid) modify2(l, r, ls, x);
  if(r > mid) modify2(l, r, rs, x);
  pushUp(k);
}
ll Query(int l, int r, int k) {
  if(l <= t[k].l && t[k].r <= r) return t[k].sum % p;
  pushDown(k); ll sum = 0ll; int mid = (t[k].l + t[k].r) >> 1;
  if(l <= mid) sum = (sum + Query(l, r, ls)) % p;
  if(r > mid) sum = (sum + Query(l, r, rs)) % p;
  return sum % p;
}
int main() {
  n = read(); p = read();
  for(int i = 1; i <= n; ++ i) a[i] = read();
  m = read(); build(1, n, 1);
  for(int i = 1; i <= m; ++ i) {
    int opt = read(), l = read(), r = read(), x;
    if(opt == 1) x = read(), modify1(l, r, 1, x);
    else if(opt == 2) x = read(), modify2(l, r, 1, x);
    else printf("%lld\n", Query(l, r, 1) % p);
  }
  return 0;
}