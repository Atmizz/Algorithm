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
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 0;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll a, b, n, m, ans;
int main() {
  a = read(); b = read(); n = read(); m = a * 5ll + b * 2ll;
  ans = 7ll * (n / m); n %= m;
  if(n <= 5ll * a) ans += (n / a);
  else ans += 5, n -= 5ll * a, ans += (n / b);
  n %= b; if(n) ans ++;
  printf("%lld", ans);
  return 0;
}