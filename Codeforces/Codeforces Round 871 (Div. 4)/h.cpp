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
const int MaxN = 2e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, k, T, f[MaxN][64];
int main() {
  T = read();
  while(T --) {
    n = read(); k = read();
    for(int i = 1; i <= n; ++ i)
      for(int j = 1; j <= 63; ++ j)
        f[i][j] = 0;
    for(int i = 1; i <= n; ++ i) {
      int x = read();
      for(int j = 0; j <= 63; ++ j) {
        f[i][j] = f[i-1][j];
        int k = (j & x);
        f[i][k] = (f[i][k] + f[i-1][j]) % Mod;
      }
      f[i][x] ++;
    }
    int ans = 0;
    for(int i = 0; i <= 63; ++ i) {
      int cnt = 0, x = i;
      for(; x; x >>= 1) cnt += (x & 1);
      if(cnt == k) ans = (ans + f[n][i]) % Mod;
    } printf("%d\n", ans);
  }
  return 0;
}