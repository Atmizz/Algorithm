#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline int read() {
  ll s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline ll max(ll a, ll b) {return a > b ? a : b;}
const int MaxN = 5001;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, r, sum[MaxN][MaxN], ans, maxx, maxy;
int main() {
  n = read(); r = read(); r = min(r, MaxN);
  for(int i = 1; i <= n; ++ i) {
    int x = read(), y = read(), w = read();
    sum[x+1][y+1] += w;
    maxx = max(maxx, x + 1); maxy = max(maxy, y + 1);
  } 
  for(int i = 1; i <= maxx; ++ i)
    for(int j = 1; j <= maxy; ++ j)
      sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
  for(int i = r; i <= maxx; ++ i)
    for(int j = r; j <= maxy; ++ j)
      ans = max(ans, sum[i][j] - sum[i-r][j] - sum[i][j-r] + sum[i-r][j-r]);
  printf("%d\n", ans);
  // for(int i = 1; i <= 5; ++ i, puts(""))
  //   for(int j = 1; j <= 5; ++ j)
  //     printf("%d ", sum[i][j]);
  return 0;
}