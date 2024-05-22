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
int T, n, m, a[MaxN], block, blk[MaxN];
std :: vector <int> g[MaxN];
int query(int l, int r, int h) {
  int sum = 0;
  for(int i = l; i <= min(r, blk[l] * block); ++ i)
    if(a[i] <= h) sum ++;
  // std :: cout << "sum : " << sum << ' ';
  if(blk[l] != blk[r])
    for(int i = (blk[r] - 1) * block + 1; i <= r; ++ i)
      if(a[i] <= h) sum ++;
  // std :: cout << sum << ' ';
  for(int i = blk[l] + 1; i <= blk[r] - 1; ++ i) {
    int pos = std :: upper_bound(g[i].begin(), g[i].end(), h) - g[i].begin();
    if(pos == 0 && g[i][0] > h) continue;
    sum += pos;
  }
  return sum;
}
int main() {
  T = read();
  for(int _ = 1; _ <= T; ++ _) {
    std :: cout << "Case " << _ << ":\n";
    n = read(); m = read(); block = sqrt(n);
    for(int i = 1; i <= n; ++ i)
      blk[i] = (i - 1) / block + 1, a[i] = read();
    for(int i = 1; i <= blk[n]; ++ i) g[i].clear();
    for(int i = 1; i <= n; ++ i)
      g[blk[i]].push_back(a[i]);
    for(int i = 1; i <= blk[n]; ++ i)
      std :: sort(g[i].begin(), g[i].end());
    for(int i = 1; i <= m; ++ i) {
      int l = read(), r = read(), h = read();
      printf("%d\n", query(l+1, r+1, h));
    }
  }
  return 0;
}