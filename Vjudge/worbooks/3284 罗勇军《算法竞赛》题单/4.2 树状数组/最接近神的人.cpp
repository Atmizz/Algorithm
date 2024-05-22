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
const int MaxN = 2e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, a[MaxN];
ll ans;
struct number {
  int val, pos;
  friend bool operator < (number a, number b) {
    return a.val < b.val;
  }
}b[MaxN];
struct Node {
  int sum, l, r;
}t[MaxN];
void pushUp(int k) {
  t[k].sum = t[ls].sum + t[rs].sum;
}
void Build(int l, int r, int k) {
  t[k].l = l; t[k].r = r; t[k].sum = 0;
  if(l == r) return;
  int mid = (l + r) >> 1;
  Build(l, mid, ls); Build(mid+1, r, rs);
}
void Modify(int l, int r, int k) {
  if(l <= t[k].l && t[k].r <= r) {
    t[k].sum += 1;
    return ;
  }
  int mid = (t[k].l + t[k].r) >> 1;
  if(l <= mid) Modify(l, r, ls);
  if(r > mid) Modify(l, r, rs);
  pushUp(k);
}
ll query(int l, int r, int k) {
  if(l <= t[k].l && t[k].r <= r) return t[k].sum;
  ll sum = 0; int mid = (t[k].l + t[k].r) >> 1;
  if(l <= mid) sum += query(l, r, ls);
  if(r > mid) sum += query(l, r, rs);
  return sum;
}
int main() {
  n = read(); Build(1, n, 1);
  for(int i = 1; i <= n; ++ i) b[i].val = read(), b[i].pos = i;
  std :: sort(b + 1, b + 1 + n);
  for(int i = 1; i <= n; ++ i)
    if(b[i].val != b[i-1].val) a[b[i].pos] = i;
    else a[b[i].pos] = a[b[i-1].pos];
  for(int i = 1; i <= n; ++ i)
    ans += query(a[i] + 1, n, 1), Modify(a[i], a[i], 1);
  printf("%lld", ans);
  return 0;
}