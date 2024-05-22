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
inline ll max(ll a, ll b) {return a > b ? a : b;}
const int MaxN = 1e6 + 200;
const int Mod = 5e7 + 7;
const int INF = 2147483647;
ll s, n, m, dp[MaxN];
ll a[11], b[11];
int main() {
  s = read(); n = read(); m = read();
  for(int i = 1; i <= m; ++ i) a[i] = read() / 1000, b[i] = read();
  while(n --) {
    ll maxv = s / 1000;
    for(int i = 1; i <= m; ++ i)
      for(int j = a[i]; j <= maxv; ++ j)
        dp[j] = max(dp[j], dp[j-a[i]] + b[i]);
    s += dp[maxv];
  } printf("%lld", s);
  return 0;
}