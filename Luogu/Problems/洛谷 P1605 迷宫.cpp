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
const int MaxN = 10;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, T, map[MaxN][MaxN], sx, sy, fx, fy, ans;
int xx[4] = {0, 0, 1, -1}, yy[4] = {1, -1, 0, 0};
bool vis[MaxN][MaxN];
struct Node {
  int x, y;
};
void DFS(int x, int y) {
  if(x == fx && y == fy) {
    ans ++; return ;
  }
  for(int i = 0; i < 4; ++ i) {
    int dx = x + xx[i], dy = y + yy[i];
    if(dx < 1 || dx > n || dy < 1 || dy > m || vis[dx][dy] || map[dx][dy]) continue;
    vis[dx][dy] = 1; DFS(dx, dy); vis[dx][dy] = 0;
  }
}
int main() {
  n = read(); m = read(); T = read();
  sx = read(); sy = read(); fx = read(); fy = read();
  for(int i = 1; i <= T; ++ i) {
    int x = read(), y = read();
    map[x][y] = 1;
  }
  vis[sx][sy] = 1; DFS(sx, sy);
  printf("%d", ans);
  return 0;
}