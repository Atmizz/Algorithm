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
const int MaxN = 400;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
struct Node {
  int x, dis;
  friend bool operator < (Node a, Node b) {
    return a.dis > b.dis;
  }
};
int dis[MaxN], n, m, st, en, sum, g[MaxN][MaxN];
int main() {
  n = read(); m = read(); st = read(); en = read(); sum = read();
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= m; ++ j)
      g[i][j] = -1;
  for(int i = 1; i <= m; ++ i) {
    int u = read(), v = read(), w = read();
    g[u][v] = g[v][u] = w;
  }
  std :: priority_queue <Node> q;
  for(int i = 1; i <= n; ++ i) dis[i] = INF >> 1;
  dis[st] = 0; q.push({st, 0});
  while(!q.empty()) {
    int u = q.top().x, d = q.top().dis; q.pop();
    if(d != dis[u]) continue;
    for(int v = 1; v <= n; ++ v) {
      if(g[u][v] == -1) continue;
      if(dis[v] > dis[u] + g[u][v])
        dis[v] = dis[u] + g[u][v], q.push({v, dis[v]});
    }
  }
  printf(dis[en] > sum ? "B" : "A");
  return 0;
}