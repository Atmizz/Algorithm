#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline ll read() {
  ll s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 1510;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll T, n, g[MaxN][MaxN], ans, x[1000010], y[1000010], f[MaxN][MaxN];
int main() {
  int k = 1, now = 1;
  while(now <= 1e6) {
    for(int i = 1; i <= k; ++ i) {
      x[now] = k, y[now] = i, g[k][i] = now ++;
      if(now > 1e6) break;
    }
    k ++;
  } f[1][1] = 1;
  for(int i = 2; i <= 1414; ++ i)
    for(int j = 1; j <= i; ++ j) {
      f[i][j] = f[i-1][j] + f[i-1][j-1] + g[i][j] * g[i][j];
      if(i > 1 && j > 1) f[i][j] -= f[i-2][j-1];
    }
  T = read();
  while(T --) {
    n = read(); ans = 0;
    printf("%lld\n", f[x[n]][y[n]]);
  }
  return 0;
}