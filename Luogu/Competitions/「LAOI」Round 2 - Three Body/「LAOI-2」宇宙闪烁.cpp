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
const int MaxN = 2e5 + 300;
const ll Mod = 998244353;
const int INF = 2147483647;
int n, q;
std :: string a[MaxN];
struct Tree {
  int l, r;
  std :: string val = "", lazy = "";
}t[MaxN<<2];
void pushUp(int k) {
  t[k].val = t[ls].val + t[rs].val;
}
void pushDown(int k) {
  t[ls].val = t[rs].val = "";
  t[ls].lazy = t[rs].lazy = t[k].lazy;
  for(int i = 1; i <= t[ls].r - t[ls].l + 1; i ++ ) t[ls].val += t[k].lazy;
  for(int i = 1; i <= t[rs].r - t[rs].l + 1; i ++ ) t[rs].val += t[k].lazy;
  t[k].lazy = "";
}
void Build(int l, int r, int k) {
  t[k].l = l; t[k].r = r;
  if(l == r) {
    t[k].val = a[l];
    return ;
  } int mid = (l + r) >> 1;
  Build(l, mid, ls); Build(mid+1, r, rs);
  pushUp(k);
}
void Modify(int l, int r, int k, std :: string str) {
  if(l <= t[k].l && t[k].r <= r) {
    t[k].lazy = str; t[k].val = "";
    for(int i = 1; i <= t[k].r - t[k].l + 1; ++ i) t[k].val += str;
    return ;
  } if(t[k].lazy != "") pushDown(k);
  int mid = (t[k].l + t[k].r) >> 1;
  if(l <= mid) Modify(l, r, ls, str);
  if(r > mid) Modify(l, r, rs, str);
  pushUp(k);
}
ll workUp(std :: string str) {
  ll sum = 0, len = str.length();
  sum = str[0] - 48;
  for(int i = 1; i < len; ++ i)
    sum = (sum * 10 + (str[i] - 48)) % Mod;
  // printf("%lld\n", sum);
  return sum;
}
std :: string Query(int l, int r, int k) {
  // printf("%d %d %d %d\n", l, t[k].l, r, t[k].r);
  if(l <= t[k].l && t[k].r <= r) return t[k].val;
  if(t[k].lazy != "") pushDown(k);
  int mid = (t[k].l + t[k].r) >> 1;
  std :: string str = "";
  if(l <= mid) str = Query(l, r, ls) + str;
  if(r > mid) str = str + Query(l, r, rs);
  return str;
}
int main() {
  n = read(); q = read();
  for(int i = 1; i <= n; ++ i) std :: cin >> a[i];
  Build(1, n, 1);
  for(int i = 1; i <= q; ++ i) {
    int opt = read(), l = read(), r = read();
    std :: string v;
    if(opt == 1) {
      std :: cin >> v;Modify(l, r, 1, v);
    } else printf("%lld\n", workUp(Query(l, r, 1)));
  }
  return 0;
}