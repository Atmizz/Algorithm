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
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1}, n, m, ans;
char Map[302][302];
bool vis[302][302];
struct Node {
  int x, y;
};
bool Check(int x, int y) {
  if(Map[x][y] == '0' || vis[x][y]) return false;
  std :: queue <Node> q;
  q.push({x, y});
  while(!q.empty()) {
    Node a = q.front(); q.pop();
    for(int i = 0; i < 4; ++ i) {
      int xx = a.x + dx[i], yy = a.y + dy[i];
      if(xx > 0 && xx <= n && yy > 0 && yy <= m && Map[xx][yy] != '0' && !vis[xx][yy])
        vis[xx][yy] = 1, q.push({xx, yy});
    }
  } return true;
}
int main() {
  n = read(); m = read();
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= m; ++ j)
      std :: cin >> Map[i][j];
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= m; ++ j)
      if(Check(i, j)) ans ++;
  printf("%d", ans);
  return 0;
}