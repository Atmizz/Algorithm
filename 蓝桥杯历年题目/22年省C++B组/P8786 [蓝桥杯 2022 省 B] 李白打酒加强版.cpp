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
const int MaxN = 120;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll n, m, dp[MaxN<<1][MaxN][MaxN];
int main() {
  n = read(); m = read(); dp[0][0][2] = 1;
  for(int i = 0; i < n + m; ++ i)
    for(int j = 0; j < m; ++ j)
      for(int k = 0; k <= m; ++ k) {
        if(k > 0) dp[i+1][j+1][k-1] += dp[i][j][k], dp[i+1][j+1][k-1] %= Mod;
        if(k <= 50) dp[i+1][j][k<<1] += dp[i][j][k], dp[i+1][j][k<<1] %= Mod;
      }
  printf("%lld", dp[n+m][m][0]);
  return 0;
}