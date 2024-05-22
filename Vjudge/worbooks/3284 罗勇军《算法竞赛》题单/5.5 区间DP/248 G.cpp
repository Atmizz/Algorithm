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
const int MaxN = 250;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, dp[MaxN][MaxN], ans;
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) dp[i][i] = read();
  for(int len = 2; len <= n; ++ len)
    for(int i = 1; i <= n; ++ i) {
      int j = i + len - 1;
      if(j > n) break;
      for(int k = i; k < j; ++ k)
        if(dp[i][k] == dp[k+1][j] && dp[i][k]) {
          dp[i][j] = max(dp[i][j], dp[i][k] + 1);
          // std :: cout << "i : " << i << " k : " << k << " j : " << j << " dp[i][k] : " << dp[i][k] << " dp[k+1][j] : " << dp[k+1][j] << '\n';
        }
    }
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= i; ++ j)
      ans = max(ans, dp[j][i]);
  printf("%d", ans);
  return 0;
}