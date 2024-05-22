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
const int MaxN = 1e5 + 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int dp[MaxN][10];
int main() {
  int n = read();
  for(int i = 1; i <= n; ++ i) {
    int x = read(), a = x % 10, b;
    while(x) b = x % 10, x /= 10;
    for(int j = 0; j <= 9; ++ j) dp[i][j] = dp[i-1][j];
    dp[i][a] = max(dp[i][a], dp[i][b] + 1);
  }
  int maxx = 0;
  for(int i = 0; i <= 9; ++ i)
    maxx = max(maxx, dp[n][i]);
  printf("%d", n - maxx);
  return 0;
}