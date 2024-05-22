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
const int MaxN = 1e5;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, dp[MaxN], w[120], ans, maxx, vis[MaxN];
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) w[i] = read(), maxx += w[i];
  for(int i = 1; i <= n; ++ i)
    for(int j = maxx; j >= w[i]; -- j)
      dp[j] = max(dp[j], dp[j-w[i]] + w[i]);
  for(int i = 1; i <= maxx; ++ i) 
    if(i == dp[i]) ans ++, vis[i] = 1;
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= maxx - w[i]; ++ j)
      dp[j] = max(dp[j], dp[j+w[i]] - w[i]);
  for(int i = 1; i <= maxx; ++ i)
    if(i == dp[i] && !vis[i]) ans ++;
  printf("%d", ans);
  return 0;
}