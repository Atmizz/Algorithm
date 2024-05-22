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
const int MaxN = 1500;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int m, n, l, t, V[100][MaxN][200], cnt, ans;
bool vis[100][MaxN][200];
int xx[6] = {-1, 0, 0, 1, 0, 0};
int yy[6] = {0, 0, 0, 0, 1, -1};
int zz[6] = {0, 1, -1, 0, 0, 0};
struct Node {
  int x, y, z;
};
void bfs(int x, int y, int z) {
  std :: queue <Node> q; q.push({x, y, z}); vis[x][y][z] = 1;
  while(q.size()) {
    int X = q.front().x, Y = q.front().y, Z = q.front().z;
    cnt ++;  q.pop();
    for(int i = 0; i < 6; ++ i) {
      int dx = X + xx[i], dy = Y + yy[i], dz = Z + zz[i];
      if(dx >= 1 && dx <= l && dy >= 1 && dy <= m && dz >= 1 && dz <= n && V[dx][dy][dz] && !vis[dx][dy][dz])
        vis[dx][dy][dz] = 1, q.push({dx, dy, dz});
    }
  }
}
int main() {
  m = read(); n = read(); l = read(); t = read();
  for(int i = 1; i <= l; ++ i)
    for(int j = 1; j <= m; ++ j)
      for(int k = 1; k <= n; ++ k)
        V[i][j][k] = read();
  for(int i = 1; i <= l; ++ i)
    for(int j = 1; j <= m; ++ j)
      for(int k = 1; k <= n; ++ k)
        if(!vis[i][j][k] && V[i][j][k]) {
          cnt = 0;
          bfs(i, j, k);
          if(cnt >= t) ans += cnt;
        }
  printf("%d", ans);
  return 0;
}