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
const int MaxN = 2e5+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int t, n, dp[MaxN];
int main() {
  t = read();
  while(t --) {
    n = read(); memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; ++ i) {
      int x = read(); if(x == 0) continue;
      int l = ((i - x + 1) >= 1 ? (i - x + 1) : 1), r = i + 1;
      dp[l] += 1; dp[r] -= 1;
    }
    for(int i = 1; i <= n; ++ i)
      dp[i] += dp[i-1], printf("%d ", dp[i] > 1 ? 1 : dp[i]);
    puts("");
  }
  return 0;
}