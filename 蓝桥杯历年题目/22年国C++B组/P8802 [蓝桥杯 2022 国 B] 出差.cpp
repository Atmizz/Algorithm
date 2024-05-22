#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline ll read() {
  ll s = 0, f = 1; char ch = gc;
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
ll dis[MaxN], cnt, n, m, head[MaxN], c[MaxN];
struct Node {
  ll x, dis;
  friend bool operator < (Node a, Node b) {
    return a.dis > b.dis;
  }
};
struct Edge {
  ll to, net, dis;
}e[MaxN];
inline void Insert(ll u, ll v, ll w) {
  e[++cnt] = {v, head[u], w};
  head[u] = cnt;
}
void Dijstra() {
  memset(dis, 0x7f, sizeof dis); dis[1] = 0;
  std :: priority_queue <Node> q; q.push({1, 0});
  while(q.size()) {
    int u = q.top().x; ll d = q.top().dis; q.pop();
    if(d != dis[u]) continue;
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(dis[v] > dis[u] + e[i].dis + c[v])
        dis[v] = dis[u] + e[i].dis + c[v], q.push({v, dis[v]});
    }
  }
}
int main() {
  n = read(); m = read();
  for(int i = 1; i <= n; ++ i) c[i] = read();
  for(int i = 1; i <= m; ++ i) {
    int u = read(), v = read(); ll w = read();
    Insert(u, v, w); Insert(v, u, w);
  } Dijstra();
  printf("%lld", dis[n] - c[n]);
  return 0;
}