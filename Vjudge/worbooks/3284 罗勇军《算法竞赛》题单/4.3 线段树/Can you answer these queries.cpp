#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline ll read() {
  ll s = 0, f = 1; char ch = gc;
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
int n, m;
ll a[MaxN];
struct Node {
  int l, r, cnt;
  ll sum;
}t[MaxN<<2];
void pushUp(int k) {
  t[k].sum = t[ls].sum + t[rs].sum;
  t[k].cnt = t[ls].cnt & t[rs].cnt;
}
void build(int l, int r, int k) {
  t[k].l = l; t[k].r = r;
  if(l == r) {
    t[k].sum = a[l];
    return ;
  } int mid = (l + r) >> 1;
  build(l, mid, ls); build(mid+1, r, rs);
  pushUp(k);
}
void update(int l, int r, int k) {
  if(t[k].cnt) return ;
  if(t[k].l == t[k].r) {
    t[k].sum = sqrt(t[k].sum);
    t[k].cnt = (t[k].sum == 1);
    return ;
  }
  int mid = (t[k].l + t[k].r) >> 1;
  if(l <= mid) update(l, r, ls);
  if(r > mid) update(l, r, rs);
  pushUp(k);
}
ll query(int l, int r, int k) {
  if(t[k].l >= l && t[k].r <= r) return t[k].sum;
  ll ans = 0; int mid = (t[k].l + t[k].r) >> 1;
  if(l <= mid) ans += query(l, r, ls);
  if(r > mid) ans += query(l, r, rs);
  return ans;
}
int main() {
  int num = 0;
  while(~scanf("%d", &n)) {
    printf("Case #%d:\n", ++num);
    memset(t, 0, sizeof t);
    for(int i = 1; i <= n; ++ i) a[i] = read();
    m = read(); build(1, n, 1);
    for(int i = 1; i <= m; ++ i) {
      int opt = read(), l = read(), r = read();
      if(l > r) std :: swap(l, r);
      if(opt == 0) update(l, r, 1);
      else printf("%lld\n", query(l, r, 1));
    } puts("");
  }
  return 0;
}