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
const int MaxN = 30;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, x, y;
ll f[MaxN][MaxN];
int xx[8] = {-2, -2, -1, 1, 2, 2, 1, -1}, yy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int main() {
  n = read(); m = read(); x = read(); y = read();
  n ++; m ++; x ++; y ++; f[x][y] = -1;
  for(int i = 0; i < 8; ++ i)
    if(x+xx[i] >= 1 && x+xx[i] <= n && y+yy[i] >= 1 && y+yy[i] <= m)
      f[x+xx[i]][y+yy[i]] = -1;
  f[1][0] = 1;
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= m; ++ j)
      if(f[i][j] == -1) f[i][j] = 0;
      else f[i][j] += f[i-1][j] + f[i][j-1];
  printf("%lld", f[n][m]);
  return 0;
}