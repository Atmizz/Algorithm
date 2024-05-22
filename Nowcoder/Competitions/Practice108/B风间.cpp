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
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int t, n;
ll ans, a[MaxN], b[MaxN], c[MaxN];
bool flag;
int main() {
  t = read();
  while(t --) {
    bool flag = 1; ans = 0; n = read();
    for(int i = 1; i <= n; ++ i) a[i] = read();
    for(int i = 1; i <= n; ++ i) b[i] = read();
    for(int i = 1; i <= n; ++ i) c[i] = b[i] - a[i];
    for(int i = 2; i <= n; ++ i) {
      // printf("i %d c[i-1] %d c[i] %d %d\n", i, c[i-1], c[i], std :: abs(c[i-1] >> 1));
      if(c[i] % 2) {flag = 0; break;}
      if(c[i-1] < 0) c[i] -= std :: abs(c[i-1]);
      else c[i] += std :: abs(c[i-1]);
      // printf("i %d c[i-1] %d c[i] %d %d\n", i, c[i-1], c[i], std :: abs(c[i-1] >> 1));
      ans += (std :: abs(c[i-1]) >> 1);
    }
    if(c[n] || !flag) printf("-1\n");
    else printf("%lld\n", ans);
  }
  return 0;
}