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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
struct Edge {
  int to, net, dis;
}e[MaxN];
int n, m, s, cnt, head[MaxN], dis[MaxN];
bool vis[MaxN];
void Insert(int u, int v, int w) {
  e[++cnt] = {v, head[u], w};
  head[u] = cnt;
}
void SPFA() {
  for(int i = 1; i <= n; ++ i) dis[i] = INF;
  std :: queue <int> q; q.push(s); vis[s] = 1; dis[s] = 0;
  while(!q.empty()) {
    int u = q.front(); q.pop(); vis[u] = 0;
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(dis[v] > dis[u] + e[i].dis) {
        dis[v] = dis[u] + e[i].dis;
        if(!vis[v]) vis[v] = 1, q.push(v);
      }
    }
  }
}
int main() {
  n = read(); m = read(); s = read();
  for(int i = 1; i <= m; ++ i) {
    int u = read(), v = read(), w = read();
    Insert(u, v, w);
  } SPFA();
  for(int i = 1; i <= n; ++ i) printf("%d ", dis[i]);
  return 0;
}