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
const int MaxN = 4e5+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, cnt, dis[MaxN], head[MaxN], minn = INF, maxx = -INF;
bool vis[MaxN];
struct Edge {
  int to, net, dis;
}e[MaxN];
void Insert(int u, int v, int w) {
  e[++cnt] = {v, head[u], w};
  head[u] = cnt;
}
void spfa() {
  memset(dis, -0x3f, sizeof dis); dis[minn] = 0;
  std :: queue <int> q; q.push(minn); vis[minn] = 1;
  while(!q.empty()) {
    int u = q.front(); q.pop(); vis[u] = 0;
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(dis[v] < dis[u] + e[i].dis) {
        dis[v] = dis[u] + e[i].dis;
        if(!vis[v]) q.push(v), vis[v] = 1;
      }
    }
  }
}
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    int u = read(), v = read(), w = read();
    Insert(u-1, v, w);
    minn = min(u-1, minn);
    maxx = max(v, maxx);
  }
  for(int i = minn; i <= maxx; ++ i)
    Insert(i, i + 1, 0), Insert(i + 1, i, -1);
  spfa();
  printf("%d", dis[maxx]);
  return 0;
}