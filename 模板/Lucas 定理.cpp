#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
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
const int MaxN = 1e5+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll p;
ll Pow(ll a, ll b) {
  ll sum = 1;
  while(b) {
    if(b & 1LL) sum = sum * a % p;
    a = a * a % p; b >>= 1LL;
  } return sum % p;
}
ll C(ll N, ll M) {
  
  ll sum = 1;
  for(ll i = N; i >= N - M + 1; -- i) sum = sum * i % p;
  for(ll i = 2; i <= M; ++ i) sum = sum * Pow(i, p-2) % p;
  return sum % p;
}
ll lucas(ll a, ll b) {
  return !b ? 1 : (ll)C(a % p, b % p) * lucas(a / p, b / p) % p;
}
int main() {
  ll T = read();
  while(T --) {
    ll n = read(), m = read(); p = read();
    printf("%lld\n", (lucas(n+m, n) + p)% p);
  }
  return 0;
}