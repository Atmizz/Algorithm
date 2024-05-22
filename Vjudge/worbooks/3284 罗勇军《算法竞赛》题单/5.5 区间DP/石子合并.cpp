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
const int MaxN = 201;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int a[MaxN], dp[MaxN][MaxN], sum[MaxN], n;
void dp_min() {
  memset(dp, 0x3f, sizeof dp);
  for(int i = 1; i <= n << 1; ++ i)
    dp[i][i] = 0;
  for(int len = 2; len <= n << 1; ++ len)
    for(int i = 1; i <= n << 1; ++ i) {
      int j = i + len - 1;
      if(j > (n << 1)) break;
      for(int k = i; k < j; ++ k)
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1]);
    }
  int ans = INF;
  for(int i = 1; i <= n; ++ i)
    ans = min(ans, dp[i][i+n-1]);
  printf("%d\n", ans);
}
void dp_max() {
  memset(dp, -1, sizeof dp);
  for(int i = 1; i <= n << 1; ++ i) dp[i][i] = 0;
  for(int len = 2; len <= n; ++ len)
    for(int i = 1; i <= n << 1; ++ i) {
      int j = i + len - 1;
      if(j > (n << 1)) break;
      for(int k = i; k < j; ++ k)
        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] + sum[j] - sum[i-1]);
    }
  int ans = -1;
  for(int i = 1; i <= n; ++ i)
    ans = max(ans, dp[i][i+n-1]);
  printf("%d", ans);
}
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) a[i] = read(), a[i+n] = a[i];
  for(int i = 1; i <= n << 1; ++ i) sum[i] = sum[i-1] + a[i];
  dp_min(); dp_max();
  return 0;
}