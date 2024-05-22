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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, T, map[9][9], ans, sum, vis[9][9];
int xx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int yy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(int x, int y) {
  if(y == m + 1) {
    dfs(x + 1, 1);
    return ;
  }
  if(x == n + 1) {
    ans = max(ans, sum);
    return ;
  }
  dfs(x, y + 1);
  if(vis[x][y] == 0) {
    sum += map[x][y];
    for(int i = 0; i < 8; ++ i)
      ++ vis[xx[i]+x][yy[i]+y];
    dfs(x, y + 1);
    for(int i = 0; i < 8; ++ i)
      -- vis[x+xx[i]][y+yy[i]];
    sum -= map[x][y];
  }
}
void Work() {
  ans = 0; dfs(1, 1);
  printf("%d\n", ans);
}
int main() {
  T = read();
  while(T --) {
    n = read(), m = read();
    memset(vis, 0, sizeof vis);
    memset(map, 0, sizeof map);
    for(int i = 1; i <= n; ++ i)
      for(int j = 1; j <= m; ++ j)
        map[i][j] = read();
    Work();
  }
  return 0;
}
/*
1 2 3 4 5
6 7 8 9 0
1 2 3 4 5
6 7 8 9 0
1 2 3 4 5

*/