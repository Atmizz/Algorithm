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
const int MaxN = 5e3+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, cnt, head[MaxN<<1], num[MaxN], dis[MaxN];
bool vis[MaxN], flag;
struct Node {
  int to, net, dis;
}e[MaxN<<1];
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
int main() {
  n = read(); m = read();
  for(int i = 1; i <= m; ++ i) {
    int u = read(), v = read(), w = read();
    Insert(v, u, w);
  }
  for(int i = 1; i <= n; ++ i) Insert(0, i, 0);
  memset(dis, 0x3f, sizeof dis); dis[0] = 0; vis[0] = 1; spfa(0);
  if(!flag)
    for(int i = 1; i <= n; ++ i)  printf("%d ", dis[i]);
  else printf("NO");
  return 0;
}