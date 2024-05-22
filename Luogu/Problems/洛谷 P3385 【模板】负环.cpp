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
const int MaxN = 1e4+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
struct Edge {
  int to, net, dis;
}e[MaxN];
int n, m, dis[MaxN], cnt, head[MaxN], num[MaxN];
bool vis[MaxN];
void New_Begin() {
  cnt = 0;
  memset(dis, 88, sizeof dis);
  memset(vis, 0, sizeof vis);
  memset(num, 0, sizeof num);
  memset(head, 0, sizeof head);
}
void Insert(int u, int v, int w) {
  e[++cnt] = {v, head[u], w};
  head[u] = cnt;
}
bool SPFA() {
  std :: queue <int> q; q.push(1);
  dis[1] = 0; vis[1] = 1;
  while(!q.empty()) {
    int u = q.front(); q.pop(), vis[u] = 0;
//    printf("u %d  dis %d\n", u, dis[u]);
    for(int i = head[u]; i; i = e[i].net) {
      int v = e[i].to;
      if(dis[v] > dis[u] + e[i].dis) {
        dis[v] = dis[u] + e[i].dis;
        if(!vis[v]) q.push(v), vis[v] = 1, num[v] ++;
        if(num[v] > n) return true;
      }
    }
  } return false;
}
int main() {
  int T = read();
  while(T --) {
    New_Begin(), n = read(); m = read();
    for(int i = 1; i <= m; ++ i) {
      int u = read(), v = read(), w = read();
      if(w >= 0) Insert(u, v, w), Insert(v, u, w);
      else Insert(u, v, w);
    } printf(SPFA() ? "YES\n" : "NO\n");
  }
  return 0;
}