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
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, cnt, head[MaxN<<1], dis[MaxN], k, q;
struct Node {
  int u, dis;
  friend bool operator < (Node a, Node b) {
    return a.dis > b.dis;
  }
};
struct Edge {
  int to, net, dis;
}e[MaxN<<1];
inline void Insert(int u, int v, int w) {
  e[++cnt] = {v, head[u], w};
  head[u] = cnt;
}
void Dijstra(int u) {
  memset(dis, 0x3f, sizeof dis); dis[u] = 0;
  std :: priority_queue<Node> q; q.push({u, 0});
  while(!q.empty()) {
    int u = q.top().u, D = q.top().dis; q.pop();
    if(D > dis[u]) continue;
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(dis[v] > dis[u] + e[i].dis)
        dis[v] = dis[u] + e[i].dis, q.push({v, dis[v]});
    }
  }
}
int main() {
  n = read(); m = read();
  for(int i = 1; i <= m; ++ i) {
    int u = read(), v = read(), w = read();
    Insert(u, v, w); Insert(v, u, w);
  }
  k = read();
  for(int i = 1; i <= k; ++ i) {
    int x = read(); Insert(0, x, 0);
  } Dijstra(0);
  q = read();
  for(int i = 1; i <= q; ++ i)
    printf("%d\n", dis[read()]);
  return 0;
}