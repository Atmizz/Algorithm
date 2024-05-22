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
const int MaxN = 130;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
int n, m, g[MaxN][MaxN], f[MaxN][MaxN], ans = -INF, Final;
int dfs(int x, int y) {
  if(f[x][y]) return f[x][y];
  f[x][y] = 1;
  for(int i = 0; i < 4; ++ i) {
    int xx = x + dx[i], yy = y + dy[i];
    if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && g[x][y] > g[xx][yy]) {
      dfs(xx, yy); f[x][y] = max(f[x][y], f[xx][yy] + 1);
    }
  } return f[x][y];
}
int main() {
  n = read(); m = read();
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= m; ++ j)
      g[i][j] = read();
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= m; ++ j)
      ans = max(ans, dfs(i, j));
  printf("%d", ans);
  return 0;
}