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
int n, m, cnt, head[MaxN<<1], num[MaxN];
ll dis[MaxN], ans;
bool vis[MaxN];
struct Node {
  int to, net, dis;
}e[MaxN<<1];
void Insert(int u, int v, int w) {
  e[++cnt] = {v, head[u], w};
  head[u] = cnt;
}
void spfa(int u) {
  if(vis[n+1]) return ;
  for(int i = head[u]; i; i = e[i].net) {
    int v = e[i].to;
    if(dis[v] < dis[u] + e[i].dis) {
      if(vis[v]) {
        vis[n+1] = 1; return ;
      }
      dis[v] = dis[u] + e[i].dis;
      vis[v] = 1; spfa(v); vis[v] = 0;
    }
  }
}
int main() {
  n = read(); m = read();
  for(int i = 1; i <= m; ++ i) {
    int opt = read(), u = read(), v = read();
    if(opt == 1) Insert(u, v, 0), Insert(v, u, 0);
    else if(opt == 2) Insert(u, v, 1);
    else if(opt == 3) Insert(v, u, 0);
    else if(opt == 4) Insert(v, u, 1);
    else Insert(u, v, 0);
  }
  for(int i = n; i >= 1; -- i) Insert(0, i, 1);
  memset(dis, 0, sizeof dis); vis[0] = 1; spfa(0);
  if(!vis[n+1]) {
    for(int i = 1; i <= n; ++ i) ans += dis[i];
    printf("%lld", ans);
  }
  else printf("-1");
  return 0;
}