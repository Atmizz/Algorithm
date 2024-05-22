#include <bits/stdc++.h>
#define gc getchar()
#define ll long long
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
const int MaxN = 150;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, ans, G[MaxN];
char ch[MaxN][MaxN];
bool vis[MaxN];
bool Xyl(int x) {
  for(int i = 1; i <= m; ++ i)
    if(ch[x][i] == '1' && !vis[i]) {
      vis[i] = 1;
      if(G[i] == -1 || Xyl(G[i])) {
        G[i] = x;
        return true;
      }
    }
  return false;
}
int main() {
  n = read(); m = read();
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= m; ++ j)
      std :: cin >> ch[i][j];
  memset(G, -1, sizeof G);
  for(int i = 1; i <= n; ++ i) {
    memset(vis, 0, sizeof vis);
    if(Xyl(i)) ans ++;
  } printf("%d", ans);
  return 0;
}