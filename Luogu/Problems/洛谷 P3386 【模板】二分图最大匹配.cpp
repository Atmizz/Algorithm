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
const int MaxN = 520;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int map[MaxN][MaxN], G[MaxN], m, n, e, vis[MaxN], ans;
bool Xyl(int x) {
  for(int i = 1; i <= m; ++ i)
    if(!vis[i] && map[x][i]) {
      vis[i] = 1;
      if(!G[i] || Xyl(G[i])) {
        G[i] = x; return true;
      }
    } return false;
}
int main() {
  n = read(); m = read(); e = read();
  for(int i = 1; i <= e; ++ i) {
    int u = read(), v = read();
    map[u][v] = 1;
  }
  for(int i = 1; i <= n; ++ i) {
    memset(vis, 0, sizeof vis);
    if(Xyl(i)) ans ++;
  } printf("%d", ans);
  return 0;
}