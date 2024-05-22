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
const int MaxN = 5e4 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
struct SegmentTree {
  int l, r, sum, lz;
}t[MaxN * 4];
int n, m;
void pu(int k) {
  t[k].sum = t[ls].sum + t[rs].sum;
}
void pd(int k) {
  t[ls].lz += t[k].lz; t[rs].lz += t[k].lz;
  t[ls].sum = t[k].lz * (t[ls].r - t[ls].l + 1);
  t[rs].sum = t[k].lz * (t[rs].r - t[rs].l + 1);
  t[k].lz = 0;
}
void build(int l, int r, int k) {
  t[k].l = l, t[k].r = r; t[k].sum = t[k].lz = 0;
  if(l == r) return ;
  int mid = (l + r) >> 1;
  build(l, mid, ls); build(mid+1, r, rs);
}

int main() {
  int T = read();
  while(T --) {
    n = read(), m = read();
    for(int i = 1; i <= m; ++ i) {
      int opt = read(), l = read(), r = read();
      if(opt == 1) l ++; 
      else l ++, r ++;
    }
  }
  return 0;
}