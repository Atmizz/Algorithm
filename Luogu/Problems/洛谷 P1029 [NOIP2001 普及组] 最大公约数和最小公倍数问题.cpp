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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll p, q, ans;
int main() {
  p = read(), q = read();
  for(ll i = 1; i <= sqrt(q * p); ++ i)
    if(q % i == 0 && std :: __gcd(i, p * q / i) == p) {
      ans += 2;
      if(i * i == p * q) ans --;
    }
  printf("%lld", ans);
  return 0;
}