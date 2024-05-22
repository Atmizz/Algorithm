#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
#define int long long
typedef long long ll;
inline int read() {
  int s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n, k, a[MaxN], sum[MaxN];
signed main() {
  T = read();
  while(T --) {
    n = read(); k = read();
    int ans = 0;
    for(int i = 1; i <= n; ++ i) a[i] = read();
    std :: sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++ i) sum[i] = sum[i-1] + a[i];
    for(int i = 0; i <= k; ++ i)
      ans = max(ans, sum[n] - sum[i<<1] - (sum[n] - sum[n-k+i]));
    printf("%lld\n", ans);
  }
  return 0;
}