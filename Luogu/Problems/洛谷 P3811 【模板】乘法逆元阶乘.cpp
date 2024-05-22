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
const int MaxN = 3e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll c[MaxN], inv[MaxN], n, p;
ll Pow(ll a, ll b) {
  ll sum = 1;
  while(b) {
    if(b & 1) sum = (sum * a) % p;
    a = a * a % p; b >>= 1;
  } return sum % p;
}
int main() {
  n = read(); p = read(); c[0] = 1;
  for(int i = 1; i <= n; ++ i) c[i] = (c[i-1] * i) % p;
  inv[n] = Pow(c[n], p-2);
  for(int i = n-1; i >= 1; -- i)
    inv[i] = (inv[i+1] * (i+1)) % p;
  for(int i = 1; i <= n; ++ i)
    printf("%lld\n", (inv[i] * c[i-1]) % p);
  return 0;
}