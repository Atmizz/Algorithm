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
const int MaxN = 5e4 + 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
struct Node {
  int l, r;
  ll sum, lz;
}t[MaxN<<2];
int T, n, m, a[MaxN];
void pushUp(int k) {
  t[k].sum = t[ls].sum + t[rs].sum;
}
void pushDown(int k) {
  t[ls].lz += t[k].lz; t[rs].lz += t[k].lz;
  t[ls].sum += t[k].lz * (t[ls].r - t[ls].l + 1);
  t[rs].sum += t[k].lz * (t[rs].r - t[rs].l + 1);
  t[k].lz = 0;
}
void build(int l, int r, int k) {
  t[k].l = l; t[k].r = r;
  t[k].sum = t[k].lz = 0;
  if(l == r) {
    t[k].sum = a[l];
    return ;
  } int mid = (t[k].l + t[k].r) >> 1;
  build(l, mid, ls); build(mid+1, r, rs);
  pushUp(k);
}
void Modify(int l, int r, int k, int c) {
  if(t[k].l >= l && t[k].r <= r) {
    t[k].lz += c;
    t[k].sum += c * (t[k].r - t[k].l + 1);
    return ;
  } int mid = (t[k].l + t[k].r) >> 1;
  if(t[k].lz) pushDown(k);
  if(l <= mid) Modify(l, r, ls, c);
  if(r > mid) Modify(l, r, rs, c);
  pushUp(k);
}
ll Query(int l, int r, int k) {
  if(t[k].l >= l && t[k].r <= r) return t[k].sum;
  int mid = (t[k].l + t[k].r) >> 1; ll sum = 0;
  if(l <= mid) sum += Query(l, r, ls);
  if(r > mid) sum += Query(l, r, rs);
  return sum;
}
int main() {
  T = read();
  for(int _ = 1; _ <= T; ++ _) {
    n = read();
    for(int i = 1; i <= n; ++ i) a[i] = read();
    build(1, n, 1); std :: cout << "Case " << _ << ":\n";
    while(1) {
      std :: string str; int l, r;
      std :: cin >> str;
      if(str == "End") break;
      l = read(); r = read();
      if(str == "Add") Modify(l, l, 1, r);
      else if(str == "Sub") Modify(l, l, 1, -r);
      else printf("%lld\n", Query(l, r, 1));
    }
  }
  return 0;
}