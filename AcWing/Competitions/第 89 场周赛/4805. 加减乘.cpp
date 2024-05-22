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
inline ll min(ll a, ll b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 1e7+300;
const int Mod = 1e9 + 7;
const ll INF = 2147483649;
ll n, x, y, f[MaxN];
int main() {
  n = read(), x = read(), y = read();
  memset(f, 0x3f, sizeof f); f[0] = 0;
  for(ll i = 1; i <= n; ++ i)
    if(i % 2) f[i] = min(f[(i + 1) / 2] + x + y, f[i - 1] + x);
    else f[i] = min(f[i / 2] + y, f[i-1] + x);
  printf("%lld", f[n]);
  return 0;
}