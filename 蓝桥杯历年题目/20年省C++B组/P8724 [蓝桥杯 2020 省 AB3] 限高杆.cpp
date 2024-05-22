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
const int MaxN = 1e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, cnt, head[MaxN<<1], dis[MaxN][3];
struct Edge {
  int to, net, dis, mk;
}e[MaxN<<1];
void Insert(int u, int v, int w, int mk) {
  e[++cnt] = {v, head[u], w, mk};
  head[u] = cnt;
}
struct Node {
  int x, dis, mk;
  friend bool operator < (Node a, Node b) {
    return a.dis > b.dis;
  }
};
void Dijstra() {
  std :: priority_queue <Node> q; q.push({1, 0, 0});
  memset(dis, 0x3f, sizeof dis); dis[1][0] = 0;
  while(q.size()) {
    Node p = q.top(); q.pop();
    int u = p.x, d = p.dis, mk = p.mk;
    if(d != dis[u][mk]) continue;
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(!e[i].mk) {
        if(dis[v][mk] > dis[u][mk] + e[i].dis)
          dis[v][mk] = dis[u][mk] + e[i].dis, q.push({v, dis[v][mk], mk});
      }
      else {
        if(mk == 0 && dis[v][1] > dis[u][0] + e[i].dis)
          dis[v][1] = dis[u][0] + e[i].dis, q.push({v, dis[v][1], 1});
        if(mk == 1 && dis[v][2] > dis[u][1] + e[i].dis)
          dis[v][2] = dis[u][1] + e[i].dis, q.push({v, dis[v][2], 2});
      }
    }
  }
}
int main() {
  n = read(); m = read();
  for(int i = 1; i <= m; ++ i) {
    int u = read(), v = read(), w = read(), mk = read();
    Insert(u, v, w, mk); Insert(v, u, w, mk);
  } Dijstra();
  printf("%d", dis[n][0] - min(min(dis[n][2], dis[n][0]), dis[n][1]));
  return 0;
}