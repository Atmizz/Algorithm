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
ll gcd(ll a, ll b) {
  return b == 0 ? a : gcd(b, a % b);
}
ll a, b, GCD;
signed main() {
  ll n = read(); a = read(); b = read();
  GCD = gcd(abs(a), b);
  if(a) a /= GCD, b /= GCD;
  for(int i = 2; i <= n; ++ i) {
    ll x = read(), y = read();
    GCD = gcd(b, y);
    a = a * y / GCD;
    x = x * b / GCD;
    y = b = y * b / GCD;
    a += x;
    GCD = gcd(abs(a), b);
    a /= GCD; b /= GCD;
  }
  ll ans1 = a / b;
  ll ans2 = abs(a) % b;
  GCD = gcd(ans2, b);
  ans2 /= GCD; b /= GCD;
  if(a < 0 && ans1 < 0) ans2 = - ans2;
  if(ans1 == 0 && ans2 == 0) std :: cout << 0;
  else if(ans1 == 0) std :: cout << ans2 << '/' << b;
  else if(ans2 == 0) std :: cout << ans1;
  else std :: cout << ans1 << ' ' << ans2 << '/' << b;
  return 0;
}