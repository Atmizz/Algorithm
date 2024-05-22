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
const int MaxN = 2e5+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
struct Node {
  int u, dis;
  friend bool operator < (Node a, Node b) {
    return a.dis > b.dis;
  }
};
struct Edge {
  int to, net, dis;
}e[MaxN<<1];
int n, m, s, head[MaxN<<1], dis[MaxN], cnt;
void Insert(int u, int v, int w) {
  e[++cnt] = {v, head[u], w};
  head[u] = cnt;
}
void Dijstra() {
  memset(dis, 0x3f, sizeof dis); dis[s] = 0;
  std :: priority_queue<Node> q; q.push({s, 0});
  while(!q.empty()) {
    Node a = q.top(); q.pop();
    int u = a.u, d = a.dis;
    if(d != dis[u]) continue;
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(dis[v] > dis[u] + e[i].dis)
        dis[v] = dis[u] + e[i].dis, q.push({v, dis[v]});
    }
  }
}
int main() {
  n = read(); m = read(); s = read();
  for(int i = 1; i <= m; ++ i) {
    int u = read(), v = read(), w = read();
    Insert(u, v, w);
  } Dijstra();
  for(int i = 1; i <= n; ++ i)
    printf("%d ", dis[i]);
}