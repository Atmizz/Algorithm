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
#define ll long long
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
int V, n, m, a[MaxN];
struct SegmentTree {
  struct Node {
    int l, r, lazy, max;
  }t[MaxN];
  void Push_Up(int k) { t[k].max = max(t[ls].max, t[rs].max);}
  void Push_Down(int k) {
    t[ls].lazy = t[rs].lazy = t[k].lazy;
    t[ls].max = t[ls].lazy; t[rs].max = t[rs].lazy;
    t[k].lazy = 0;
  }
  void Build(int l, int r, int k) {
    t[k].l = l; t[k].r = r;
    if(l == r) {
      t[k].max = t[k].lazy = a[l];
      return ;
    }
    int mid = (l + r) >> 1;
    Build(l, mid, ls); Build(mid+1, r, rs);
    Push_Up(k);
  }
  void Modify1(int l, int r, int k, int x) {
    if(t[k].l >= l && t[k].r <= r) {
      t[k].max = t[k].lazy = x;
      return ;
    }
    int mid = (t[k].l + t[k].r) >> 1;
    if(t[k].lazy) Push_Down(k);
    if(l <= mid) Modify1(l, r, ls, x);
    if(r > mid) Modify1(l, r, rs, x);
    Push_Up(k);
  }
  void Modify2(int l, int r, int k, int x) {
//    printf("tl : %d  tr : %d la : %d mx : %d x : %d \n", t[k].l, t[k].r, t[k].lazy, t[k].max, x);
    if(x >= t[k].max) return ;
    if(t[k].lazy && t[k].l >= l && t[k].r <= r) {
//      std :: cout << l << "   " << r << "  " << x << "  " << t[k].max << '\n';
      t[k].max = t[k].lazy = std :: __gcd(t[k].lazy, x);
      return ;
    } if(t[k].lazy) Push_Down(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) Modify2(l, r, ls, x);
    if(r > mid) Modify2(l, r, rs, x);
    Push_Up(k);
  }
  void Function(int l, int r, int k) {
    if(t[k].l == t[k].r) {
      printf("%d ", t[k].max);
      return ;
    }
    int mid = (t[k].l + t[k].r) >> 1;
    if(t[k].lazy) Push_Down(k);
    Function(l, r, ls); Function(l, r, rs);
  }
}T;
int main() {
  V = read();
  while(V --) {
    n = read(); memset(T.t, 0, sizeof T.t);
    for(int i = 1; i <= n; ++ i) a[i] = read();
    T.Build(1, n, 1);
    m = read();
    for(int i = 1; i <= m; ++ i) {
      int opt = read(), l = read(), r = read(), x = read();
      if(opt == 1) T.Modify1(l, r, 1, x);
      else T.Modify2(l, r, 1, x);
    }
    T.Function(1, n, 1); puts("");
  }
  return 0;
}
/*
1
10
16807 282475249 1622650073 984943658 1144108930 470211272 101027544 1457850878 1458777923 2007237709 
10
1 3 6 74243042
2 4 8 16531729
1 3 4 1474833169
2 1 8 1131570933
2 7 9 1505795335
2 3 7 101929267
1 4 10 1624379149
2 2 8 2110010672
2 6 7 156091745
1 2 5 937186357

*/