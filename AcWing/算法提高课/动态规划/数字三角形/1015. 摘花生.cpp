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
const int MaxN = 101;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n, m, g[MaxN][MaxN], f[MaxN][MaxN];
int main() {
  T = read();
  while(T --) {
    n = read(), m = read();
    memset(f, 0, sizeof f);
    for(int i = 1; i <= n; ++ i)  
      for(int j = 1; j <= m; ++ j)
        g[i][j] = read();
    for(int i = 1; i <= n; ++ i)
      for(int j = 1; j <= m; ++ j)
        f[i][j] = max(f[i][j], max(f[i-1][j], f[i][j-1]) + g[i][j]);
    printf("%d\n", f[n][m]);
  }
  return 0;
}