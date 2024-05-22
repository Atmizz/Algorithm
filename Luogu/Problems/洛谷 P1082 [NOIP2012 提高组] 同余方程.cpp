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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll a, b, x_1, y_1;
ll exgcd(ll a, ll b, ll &x_1, ll &y_1) {
  if(!b) {x_1 = 1; y_1 = 0; return a;}
  ll gcd = exgcd(b, a%b, x_1, y_1);
  ll temp = x_1;
  x_1 = y_1; y_1 = temp - a / b * y_1;
  return gcd;
}
int main() {
  a = read(), b = read();
  ll gcd = exgcd(a, b, x_1, y_1);
  printf("%lld", ((x_1/gcd) % (b/gcd) + (b/gcd)) % (b/gcd));
  return 0;
}