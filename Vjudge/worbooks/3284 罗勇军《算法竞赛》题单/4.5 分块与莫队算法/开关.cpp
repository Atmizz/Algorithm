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
int n, m, block, blk[MaxN], a[MaxN], b[MaxN], num[MaxN];
void pushdown(int x) {
  if(b[blk[x]])
    for(int i = (blk[x] - 1) * block + 1; i <= blk[x] * block; ++ i)
      a[i] ^= 1, num[blk[x]] += (a[i] == 1 ? 1 : -1);
  b[blk[x]] = 0;
}
void Modify(int l, int r) {
  pushdown(l);
  for(int i = l; i <= min(r, blk[l] * block); ++ i)
    a[i] ^= 1, num[blk[l]] += (a[i] == 1 ? 1 : -1);
  if(blk[l] != blk[r]) {
    pushdown(r);
    for(int i = (blk[r] - 1) * block + 1; i <= r; ++ i)
      a[i] ^= 1, num[blk[r]] += (a[i] == 1 ? 1 : -1);
  }
  for(int i = blk[l] + 1; i <= blk[r] - 1; ++ i)
    b[i] ^= 1;
}
int query(int l, int r) {
  int sum = 0; pushdown(l);
  for(int i = l; i <= min(r, blk[l] * block); ++ i)
    sum += (a[i] == 1);
  if(blk[l] != blk[r]) {
    pushdown(r);
    for(int i = (blk[r] - 1) * block + 1; i <= r; ++ i)
      sum += (a[i] == 1);
  }
  for(int i = blk[l] + 1; i <= blk[r] - 1; ++ i)
    sum += (b[i] == 0 ? num[i] : (block - num[i]));
  return sum;
}
int main() {
  n = read(); m = read();
  block = sqrt(n);
  for(int i = 1; i <= n; ++ i)
    blk[i] = (i - 1) / block + 1;
  for(int i = 1; i <= m; ++ i) {
    int opt = read(), l = read(), r = read();
    if(opt == 0) Modify(l, r);
    else printf("%d\n", query(l, r));
  }
  return 0;
}