#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
#define int long long
typedef long long ll;
inline int read() {
  int s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 2e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, cnt, head[MaxN<<2], dis[MaxN];
bool vis[MaxN], flag;
struct Node {
  int to, net, dis;
}e[MaxN<<2];
void Insert(int u, int v, int w) {
  e[++cnt] = {v, head[u], w};
  head[u] = cnt;
}
void spfa(int u) {
  if(flag) return ;
  for(int i = head[u]; i; i = e[i].net) {
    int v = e[i].to;
    if(dis[v] > dis[u] + e[i].dis) {
      if(vis[v]) {
        flag = 1; return ;
      }
      dis[v] = dis[u] + e[i].dis;
      vis[v] = 1; spfa(v); vis[v] = 0;
    }
  }
}
void solve() {
  n = read(); m = read();
  memset(e, 0, sizeof e);
  memset(head, 0, sizeof head);
  cnt = 0; flag = 0;
  for(int i = 1; i <= m; ++ i) {
    int u = read(), v = read(), w = read();
    if(w >= 0) Insert(v, u, -w), Insert(u, v, w);
    else Insert(u, v, w), Insert(v, u, -w);
  }
  for(int i = 1; i <= n; ++ i) Insert(0, i, 0);
  for(int i = 1; i <= n; ++ i) dis[i] = 2e15;
  dis[0] = 0;
  memset(vis, 0, sizeof vis); vis[0] = 1;
  spfa(0);
  if(!flag) std :: cout << "YES";
  else printf("NO");
  puts("");
}
signed main() {
  int T = 1;
  T = read();
  while(T --) solve();
  return 0;
}