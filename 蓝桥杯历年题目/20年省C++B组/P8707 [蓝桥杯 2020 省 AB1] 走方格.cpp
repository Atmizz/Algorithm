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
const int MaxN = 32;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int dp[MaxN][MaxN], n, m;
int xx[2] = {0, 1};
int yy[2] = {1, 0};
int main() {
  n = read(); m = read(); dp[1][1] = 1;
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= m; ++ j)
      for(int k = 0; k < 2; ++ k) {
        int dx = i + xx[k], dy = j + yy[k];
        if(dx % 2 == 0 && dy % 2 == 0) continue;
        dp[dx][dy] += dp[i][j];
      }
  printf("%d", dp[n][m]);
  return 0;
}