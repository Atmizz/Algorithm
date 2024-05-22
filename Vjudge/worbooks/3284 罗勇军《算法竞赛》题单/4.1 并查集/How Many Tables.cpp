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
const int MaxN = 1200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int t, n, m, pa[MaxN];
int Find(int x) {
  return x == pa[x] ? pa[x] : Find(pa[x]);
}
int main() {
  t = read();
  while(t --) {
    n = read(); m = read(); int ans = 0;
    for(int i = 1; i <= n; ++ i) pa[i] = i;
    for(int i = 1; i <= m; ++ i) {
      int u = read(), v = read();
      u = Find(u); v = Find(v);
      pa[v] = u;
    }
    for(int i = 1; i <= n; ++ i)
      if(pa[i] == i) ans ++;
    printf("%d\n", ans);
  }
  return 0;
}