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
const int INF = 0x3f3f3f3f;
struct Edge {
  int to, net, dis;
}e[MaxN << 1];
struct Node {
  int dis, x;
  friend bool operator < (Node a, Node b) {
    return a.dis > b.dis;
  }
};
int n, m, T, dis[MaxN], cnt, head[MaxN], heal[MaxN], side[MaxN], day[MaxN];
int got() {
  int st = 0;
  for(int i = 1; i <= n; ++ i) {
    char ch; std :: cin >> ch;
    st = (st << 1) + (ch ^ 48);
  }
  return st;
}
void Insert(int u, int v, int w) {
  e[++cnt] = {v, head[u], w};
  head[u] = cnt;
}
void Dijstra(int s) {
  std :: priority_queue<Node> q;
  for(int i = 0; i <= 1024; ++ i) dis[i] = INF;
  q.push({0, s}); dis[s] = 0;
  while(q.size()) {
    int x = q.top().x, d = q.top().dis; q.pop();
    if(d != dis[x]) continue;
    for(int i = head[x]; i; i = e[i].net) {
      int v = e[i].to;
      if(dis[v] > dis[x] + e[i].dis) {
        dis[v] = dis[x] + e[i].dis;
        // std :: cout << v << ' ' << dis[v] << '\n';
        q.push({dis[v], v});
      }
    }
  }
}
void solve() {
  n = read(); m = read();
  int st = got(); cnt = 0;
  memset(head, 0, sizeof head);
  memset(e, 0, sizeof e);
  for(int i = 1; i <= m; ++ i) {
    day[i] = read();
    heal[i] = got();
    side[i] = got();
  }
  for(int i = 0; i < 1024; ++ i)
    for(int j = 1; j <= m; ++ j) {
      int x = i;
      x |= side[j];
      x &= ~heal[j];
      Insert(i, x, day[j]);
    }
  Dijstra(st);
  if(dis[0] == INF) printf("-1\n");
  else printf("%d\n", dis[0]);
}
int main() {
  T = read();
  while(T --) solve();
  return 0;
}