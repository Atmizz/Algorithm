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
const int MaxN = 1005;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n, s, val[MaxN], weight[MaxN], dp[MaxN];
void newBegin() {
  memset(dp, 0, sizeof dp);
}
int main() {
  T = read();
  while(T --) {
    n = read(); s = read(); newBegin();
    for(int i = 1; i <= n; ++ i) val[i] = read();
    for(int j = 1; j <= n; ++ j) weight[j] = read();
    for(int i = 1; i <= n; ++ i)
      for(int j = s; j >= weight[i]; -- j)
        dp[j] = max(dp[j], dp[j-weight[i]] + val[i]);
    printf("%d\n", dp[s]);
  }
  return 0;
}