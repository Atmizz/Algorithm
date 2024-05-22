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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, p, Q[MaxN], Q_L[MaxN], a, last;
struct Node {
  int l, r, maxx;
}t[MaxN];
void pushUp(int k) {
  t[k].maxx = max(t[ls].maxx, t[rs].maxx);
}
void pushDown(int k) {
  t[ls].maxx = t[rs].maxx = t[k].maxx;
}
void Build(int l, int r, int k) {
  t[k].l = l, t[k].r = r;
  if(l == r) {
    t[k].maxx = 0;
    return ;
  } int mid = (l + r) >> 1;
  Build(l, mid, ls);
  Build(mid+1, r, rs);
}
void Modify(int l, int r, int k, int x) {
  // printf("MM l %d r %d\n", t[k].l, t[k].r);
  if(t[k].l == l && t[k].r == r) {
    t[k].maxx = x;
    return ;
  }
  int mid = (t[k].l + t[k].r) >> 1;
  if(l <= mid) Modify(l, r, ls, x);
  if(r > mid) Modify(l, r, rs, x);
  pushUp(k);
}
int Query(int l, int r, int k) {
  // printf("QQ l %d r %d  %d\n", t[k].l, t[k].r, t[k].maxx);
  if(l <= t[k].l && t[k].r <= r) return t[k].maxx;
  int MAX = 0, mid = (t[k].l + t[k].r) >> 1;
  if(l <= mid) MAX = max(MAX, Query(l, r, ls));
  if(r > mid) MAX = max(MAX, Query(l, r, rs));
  return MAX;
}
int main() {
  n = read(); p = read();
  Build(1, n, 1);
  for(int i = 1; i <= n; ++ i) {
    char ch; int t;
    std :: cin >> ch; t = read();
    if(ch == 'A') last ++, Modify(last, last, 1, (t + a) % p);
    else printf("%d\n", a = Query(last - t + 1, last, 1));
  }
  return 0;
}