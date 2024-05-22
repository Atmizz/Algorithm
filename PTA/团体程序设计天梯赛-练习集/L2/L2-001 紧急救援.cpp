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
const int MaxN = 3e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, start, end, dis[MaxN], val[MaxN], pre[MaxN], ans[MaxN], cnt, head[MaxN], num;
struct Edge {
  int to, net, dis;
}e[MaxN];
struct Node {
  int x, dis;
  friend bool operator < (Node a, Node b) {
    return a.dis > b.dis;
  }
};
void Insert(int u, int v, int w) {
  e[++cnt] = {v, head[u], w};
  head[u] = cnt;
}
void Dijstra() {
  memset(dis, 0x3f, sizeof dis); dis[start] = 0; ans[start] = val[start];
  std :: priority_queue < Node > q; q.push({start, 0});
  while(q.size()) {
    int u = q.top().x, d = q.top().dis; q.pop();
    if(d != dis[u]) continue;
    for(int i = head[u]; i != -1; i = e[i].net) {
      int v = e[i].to;
      if(dis[v] > dis[u] + e[i].dis) {
        dis[v] = dis[u] + e[i].dis;
        ans[v] = ans[u] + val[v];
        pre[v] = u; q.push({v, dis[v]}); 
      } else if(dis[v] == dis[u] + e[i].dis)
        if(ans[v] < ans[u] + val[v]) ans[v] = ans[u] + val[v], pre[v] = u, q.push({v, dis[v]});
    }
  }
}
void printPath(int v) {
  if(v == start) {
      printf("%d", v);
      return ;
  }
  printPath(pre[v]);
  printf(" %d", v);
}
int main() {
  n = read(); m = read(); start = read(), end = read();
  for(int i = 0; i < n; ++ i) val[i] = read(), pre[i] = -1, head[i] = -1;
  for(int i = 1; i <= m; ++ i) {
    int u = read(), v = read(), w = read();
    Insert(u, v, w); Insert(v, u, w);
  } Dijstra();
  for(int i = head[end]; i != -1; i = e[i].net)
    if(dis[e[i].to] + e[i].dis == dis[end]) num ++;
  printf("%d %d\n", num, ans[end]);
  int u = end;
  std :: vector < int > p;
  while(1) {
    p.push_back(u);
    if(pre[u] == -1) break;
    u = pre[u];
  } printPath(end);
  return 0;
}