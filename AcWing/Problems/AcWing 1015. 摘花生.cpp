#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
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
const int MaxN = 150;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, dp[MaxN][MaxN], n, m, map[MaxN][MaxN];
int main() {
  T = read();
  while(T --) {
    n = read(); m = read();
    for(int i = 1; i <= n; ++ i)
      for(int j = 1; j <= m; ++ j)
        map[i][j] = read();
    memset(dp, sizeof dp, 0);
    for(int i = 1; i <= n; ++ i)
      for(int j = 1; j <= m; ++ j)
        dp[i][j] = max(dp[i-1][j] + map[i][j], dp[i][j-1] + map[i][j]);
    printf("%d\n", dp[n][m]);
  }
  return 0;
}