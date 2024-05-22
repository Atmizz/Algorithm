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
#define gc getchar()
#define ll long long
#define ls k << 1
#define rs k << 1 | 1
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
int T, n, a[MaxN];
struct Segment_Tree {
  struct Node {
    int l, r, sum, lazy;
  }t[MaxN];
  void Push_Up(int k) {t[k].sum = t[ls].sum + t[rs].sum;}
  void Push_Down(int k) {
    t[ls].lazy += t[k].lazy; t[rs].lazy += t[k].lazy;
    t[ls].sum += t[k].lazy * (t[ls].r - t[ls].l + 1);
    t[rs].sum += t[k].lazy * (t[rs].r - t[rs].l + 1);
    t[k].lazy = 0;
  }
  void Build_The_SegmentTree(int l, int r, int k) {
    t[k].l = l; t[k].r = r;
    if(l == r) {t[k].sum = a[l]; return ;}
    int mid = (l + r) >> 1;
    Build_The_SegmentTree(l, mid, ls);
    Build_The_SegmentTree(mid+1, r, rs);
    Push_Up(k);
  }
  void Modify(int l, int r, int k, int z) {
    if(t[k].l >= l && t[k].r <= r) {
      t[k].lazy += z;
      t[k].sum += z * (t[k].r - t[k].l + 1);
      return ;
    }
    if(t[k].lazy) Push_Down(k);
    int mid = (t[k].l + t[k].r) >> 1;
    if(l <= mid) Modify(l, r, ls, z);
    if(r > mid) Modify(l, r, rs, z);
    Push_Up(k);
  }
  int Query(int l, int r, int k) {
    if(t[k].l >= l && t[k].r <= r) return t[k].sum;
    if(t[k].lazy) Push_Down(k);
    int mid = (t[k].l + t[k].r) >> 1, sum = 0;
    if(l <= mid) sum += Query(l, r, ls);
    if(r > mid) sum += Query(l, r, rs);
    return sum;
  }
}V;
int main() {
  T = read();
  for(int k = 1; k <= T; ++ k) {
    printf("Case %d:\n", k);
    n = read(); memset(V.t, 0, sizeof V.t);
    for(int i = 1; i <= n; ++ i) a[i] = read();
    V.Build_The_SegmentTree(1, n, 1);
    while(1) {
      std :: string str; int l, r;
      std :: cin >> str;
      if(str == "End") break;
      else if(str == "Add") {
        l = read(), r = read();
        V.Modify(l, l, 1, r);
      } else if(str == "Sub") {
        l = read(), r = read();
        V.Modify(l, l, 1, -r);
      } else {
        l = read(), r = read();
        printf("%d\n", V.Query(l, r, 1));
      }
    }
  }
  return 0;
}