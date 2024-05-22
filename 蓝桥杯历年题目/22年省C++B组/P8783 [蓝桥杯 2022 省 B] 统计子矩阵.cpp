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
const int MaxN = 550;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, K, g[MaxN][MaxN];
ll ans;
int main() {
  n = read(); m = read(); K = read();
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= m; ++ j) {
      int x = read();
      g[i][j] = g[i-1][j] + x;
    }
  for(int i = 1; i <= n; ++ i)
    for(int j = i; j <= n; ++ j) {
      int l = 1, r = 1, cnt = 0;
      for(; r <= m; ++ r) {
        cnt += g[j][r] - g[i-1][r];
        while(cnt > K) cnt -= g[j][l] - g[i-1][l], l ++;
        ans += r - l + 1;
      }
    }
  printf("%lld", ans);
  return 0;
}