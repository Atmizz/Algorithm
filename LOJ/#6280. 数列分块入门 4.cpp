#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
#define int long long
inline int read() {
  int s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 5e4 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, a[MaxN], b[MaxN], blk[MaxN], block, sum[MaxN];
void add(int l, int r, int c) {
  for(int i = l; i <= min(r, blk[l] * block); ++ i)
    a[i] += c, sum[blk[i]] += c;
  if(blk[l] != blk[r])
    for(int i = (blk[r] - 1) * block + 1; i <= r; ++ i)
      a[i] += c, sum[blk[i]] += c;
  for(int i = blk[l] + 1; i <= blk[r] - 1; ++ i)
    b[i] += c;
}
int query(int l, int r, int c) {
  int ans = 0;
  for(int i = l; i <= min(r, blk[l] * block); ++ i)
    ans = (a[i] + b[blk[i]] + ans) % c;
  if(blk[l] != blk[r])
    for(int i = (blk[r] - 1) * block + 1; i <= r; ++ i)
      ans = (ans + a[i] + b[blk[i]]) % c;
  for(int i = blk[l] + 1; i <= blk[r] - 1; ++ i)
    ans = (ans + b[i] * block + sum[i]) % c;
  return ans;
}
signed main() {
  n = read(); block = sqrt(n);
  for(int i = 1; i <= n; ++ i)
    a[i] = read(), blk[i] = (i - 1) / block + 1, sum[blk[i]] += a[i];
  for(int i = 1; i <= n; ++ i) {
    int opt = read(), l = read(), r = read(), c = read();
    if(opt == 0) add(l, r, c);
    else printf("%lld\n", query(l, r, c + 1));
  }
  return 0;
}