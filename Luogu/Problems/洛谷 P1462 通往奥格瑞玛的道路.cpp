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
struct Edge {
  int to, net;
  ll dis;
}e[MaxN<<1];
struct Node {
  int u;
  ll dis;
  friend bool operator < (Node a, Node b) {
    return a.dis > b.dis;
  }
};
int n, m, b, f[MaxN], head[MaxN<<1], cnt, ans;
ll dis[MaxN];
inline void Insert(int u, int v, ll w) {
  e[++cnt] = {v, head[u], w};
  head[u] = cnt;
}
bool Dijstra(int Max) {
  for(int i = 2; i <= n; ++ i) dis[i] = INF;
  dis[1] = 0;
  std :: priority_queue <Node> q; q.push({1, 0});
  while(!q.empty()) {
    Node a = q.top(); q.pop();
    int u = a.u; ll d = a.dis;
    if(d != dis[u]) continue;
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(f[v] > Max) continue;
      if(dis[v] > dis[u] + d)
        dis[v] = dis[u] + d, q.push({v, dis[v]});
    }
  }
  if(dis[n] > b) return false;
  return true;
}
int main() {
  n = read(), m = read(), b = read();
  int l = 1, r = 1e9, mid;
  for(int i = 1; i <= n; ++ i) {
    f[i] = read(); r = max(r, f[i]);
  } l = max(f[1], f[n]);
  for(int i = 1; i <= m; ++ i) {
    int u = read(), v = read(); ll w; scanf("%lld", &w);
    Insert(u, v, w); Insert(v, u, w);
  }
  while(l < r) {
    mid = (l + r) >> 1;
    if(Dijstra(mid)) r = mid;
    else l = mid + 1;
  }
  if(Dijstra(l)) printf("%d\n", l);
  else printf("AFK\n");
  return 0;
}