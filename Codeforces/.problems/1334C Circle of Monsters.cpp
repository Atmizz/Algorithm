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
const int MaxN = 3e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, T, a[MaxN], b[MaxN], ans, sum;
signed main() {
  T = read();
  while(T --) {
    n = read(); sum = 0;
    for(int i = 1; i <= n; ++ i) a[i] = read(), b[i] = read();
    for(int i = 1; i <= n; ++ i)
      if(i == 1) sum += max(a[1] - b[n], ll(0));
      else sum += max(a[i] - b[i-1], ll(0));
    for(int i = 1; i <= n; ++ i)
      if(i == 1) ans = sum + a[1] - max(a[1] - b[n], ll(0));
      else ans = min(ans, sum + a[i] - max(a[i] - b[i-1], ll(0)));
    printf("%lld\n", ans);
  }
  return 0;
}