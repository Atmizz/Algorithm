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
const int MaxN = 1010;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, k, f[MaxN][510], ans = INF;
int main() {
  n = read(); m = read(); k = read();
  for(int i = 1; i <= k; ++ i) {
    int x = read(), w = read();
    for(int j = n; j >= x; -- j)
      for(int s = m; s >= w; -- s)
        f[j][s] = max(f[j][s], f[j-x][s-w] + 1);
  }
  for(int i = 0; i <= n; ++ i)
    for(int j = 0; j <= m; ++ j)
      if(f[i][j] == f[n][m])
        ans = min(ans, j);
  printf("%d %d", f[n][m], m - ans);
  return 0;
}