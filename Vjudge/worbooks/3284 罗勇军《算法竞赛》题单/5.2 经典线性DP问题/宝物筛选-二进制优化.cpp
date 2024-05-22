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
const int MaxN = 4e4 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, W, cnt, v[MaxN<<4], w[MaxN<<4], dp[MaxN];
int main() {
  n = read(); W = read();
  for(int i = 1; i <= n; ++ i) {
    int a = read(), b = read(), c = read();
    for(int j = 1; j <= c; j <<= 1)
      v[++cnt] = a * j, w[cnt] = b * j, c -= j;
    if(c) v[++cnt] = a * c, w[cnt] = b * c;
  }
  for(int i = 1; i <= cnt; ++ i)
    for(int j = W; j >= w[i]; -- j)
      dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
  printf("%d", dp[W]);
  return 0;
}