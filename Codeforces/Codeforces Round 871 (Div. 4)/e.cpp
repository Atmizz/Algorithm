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
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
int T, n, m, g[MaxN][MaxN], now, ans;
bool vis[MaxN][MaxN];
void dfs(int x, int y) {
  vis[x][y] = 1; now += g[x][y];
  for(int i = 0; i < 4; ++ i) {
    int dx = x + xx[i], dy = y + yy[i];
    if(dx < 1 || dx > n || dy < 1 || dy > m) continue;
    if(vis[dx][dy] || g[dx][dy] == 0) continue;
    dfs(dx, dy);
  }
}
int main() {
  T = read();
  while(T --) {
    n = read(); m = read(); ans = 0;
    for(int i = 1; i <= n; ++ i)
      for(int j = 1; j <= m; ++ j)
        g[i][j] = read(), vis[i][j] = 0;
    for(int i = 1; i <= n; ++ i)
      for(int j = 1; j <= m; ++ j)
        if(g[i][j] && !vis[i][j])
          now = 0, dfs(i, j), ans = max(ans, now);
    printf("%d\n", ans);
  }
  return 0;
}