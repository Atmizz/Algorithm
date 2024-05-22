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
int n, m, T, l[MaxN], r[MaxN], a[MaxN], sz[MaxN];
namespace Segment {
  struct Node {
    int wall, l, r;
  }t[MaxN];
  void pushup(int k) {
    if(t[ls].wall != t[rs].wall) t[k].wall = 0;
    else t[k].wall = t[ls].wall;
  }
  void pushdown(int k) {
    if(t[k].wall <= 0) return ;
    t[ls].wall = t[k].wall;
    t[rs].wall = t[k].wall;
  }
  void build(int l, int r, int k) {
    t[k].l = l; t[k].r = r; t[k].wall = -1;
    if(l == r) return ;
    int mid = (l + r) >> 1;
    build(l, mid, ls); build(mid+1, r, rs);
  }
  void cover(int l, int r, int k) {
    if(t[k].wall == -1) return ;
    if(t[k].wall != 0) {
      sz[t[k].wall] -= r - l + 1;
      return ;
    }
    int mid = (l + r) >> 1;
    cover(l, mid, ls);
    cover(mid+1, r, rs);
  }
  void modify(int l, int r, int k, int x) {
    if(t[k].l >= l && t[k].r <= r) {
      cover(t[k].l, t[k].r, k);
      t[k].wall = x;
      return ;
    }
    int mid = (t[k].l + t[k].r) >> 1;
    pushdown(k);
    if(l <= mid) modify(l, r, ls, x);
    if(r > mid) modify(l, r, rs, x);
    pushup(k);
  }
}
int main() {
  T = read();
  while(T --) {
    n = read();
    for(int i = 1; i <= n; ++ i) {
      l[i] = read(); r[i] = read();
      a[(i<<1)-1] = l[i]; a[i<<1] = r[i];
    }
    std :: sort(a, a + 1 + (n << 1));
    m = std :: unique(a, a + 1 + (n << 1)) - a;
    Segment :: build(1, m, 1);
    for(int i = 1; i <= n; ++ i) {
      l[i] = std :: lower_bound(a, a + m, l[i]) - a;
      r[i] = std :: lower_bound(a, a + m, r[i]) - a;
      // printf("l[i] : %d r[i] : %d\n", l[i], r[i]);
      sz[i] = r[i] - l[i] + 1;
      Segment :: modify(l[i], r[i], 1, i);
    }
    int ans = 0;
    for(int i = 1; i <= n; ++ i)
      if(sz[i] > 0) ans ++;
    printf("%d\n", ans);
  }
  return 0;
}