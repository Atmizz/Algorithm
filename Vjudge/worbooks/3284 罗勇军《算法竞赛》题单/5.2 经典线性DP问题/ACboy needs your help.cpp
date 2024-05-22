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
const int MaxN = 105;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, a[MaxN][MaxN], dp[MaxN];
int main() {
  while(n = read() , m = read()) {
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; ++ i)
      for(int j = 1; j <= m; ++ j)
        a[i][j] = read();
    for(int i = 1; i <= n; ++ i)
      for(int j = m; j >= 0; -- j)
        for(int k = 1; k <= j; ++ k)
          dp[j] = max(dp[j], dp[j-k] + a[i][k]);
    printf("%d\n", dp[m]);
  }
  return 0;
}