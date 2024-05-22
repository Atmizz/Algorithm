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
const int MaxN = 0;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll C(ll n, ll m) {
  ll sum = 1ll;
  for(ll i = n; i >= n - m + 1; -- i) sum = sum * i;
   for(ll i = 2; i <= m; ++ i) sum /= i;
  return sum; 
}
ll A(ll n) {
  ll sum = 1ll;
  for(ll i = 2; i <= n; ++ i) sum *= i;
  return sum;
}
int main() {
  int n = read();
  printf("%lld", C(n, n / 2) / 2ll * A(n / 2 - 1) * A(n / 2 - 1));
  return 0;
}