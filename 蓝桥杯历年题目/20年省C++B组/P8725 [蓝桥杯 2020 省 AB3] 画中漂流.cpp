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
const int MaxN = 3000;
const ll Mod = 1e9 + 7;
const int INF = 2147483647;
ll dp[3010][1510], D, T, M;
int main() {
  D = read(); T = read(); M = read();
  dp[0][M] = 1;
  for(int i = 0; i < T; ++ i)
    for(int j = 0; j <= M; ++ j) {
      if(i - ((M - j) << 1) >= D) continue;
      dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % Mod;
      if(j != 0) dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j]) % Mod;
    }
  printf("%lld", dp[T][0] % Mod);
  return 0;
}