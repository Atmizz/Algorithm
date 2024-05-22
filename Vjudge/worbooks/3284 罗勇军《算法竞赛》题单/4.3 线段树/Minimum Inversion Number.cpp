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
    t[k].sum = 0;
    return ;
  } int mid = (t[k].l + t[k].r) >> 1;
  build(l, mid, ls); build(mid+1, r, rs);
  pushUp(k);
}
void Modify(int l, int r, int k, ll c) {
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
  if(t[k].lz) pushDown(k);
  if(l <= mid) sum += Query(l, r, ls);
  if(r > mid) sum += Query(l, r, rs);
  return sum;
}
struct NN {
  int val, pos;
  friend bool operator < (NN a, NN b) {
    return a.val < b.val;
  }
}b[MaxN<<1];
int c[MaxN], ans = INF;
int main() {
  while(~scanf("%d", &n)) {
    for(int i = 1; i <= n; ++ i) b[i].val = read(), b[i].pos = i;
    std :: sort(b + 1, b + 1 + n); b[0].val = -INF;
    for(int j = 1; j <= n; ++ j)
      if(b[j].val == b[j-1].val) c[b[j].pos] = c[b[j-1].pos];
      else c[b[j].pos] = j;
    build(1, n, 1); int cnt = 0; ans = INF;
    for(int i = 1; i <= n; ++ i)
      cnt += Query(c[i]+1, n, 1), Modify(c[i], c[i], 1, 1);
    ans = cnt;
    for(int i = 1; i <= n; ++ i) {
      cnt = cnt + (n - 1 - c[i] + 1) - c[i] + 1;
      ans = min(ans, cnt);
    } printf("%d\n", ans);
  }
  return 0;
}