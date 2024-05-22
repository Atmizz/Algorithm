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
ll a, b, n, ans, mod; 
ll Pow(ll x, ll y) {
  ll sum = 1ll;
  while(y) {
    if(y & 1) sum = sum * x % mod;
    x = x * x % mod; y >>= 1;
  } return sum;
}
int main() {
  a = read(); b = read(); n = read();
  mod = b * 1000;
  ans = (a * Pow(10, n+2)) % mod /b;
  printf("%03d", ans);
  return 0;
}