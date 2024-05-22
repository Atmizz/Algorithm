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
inline ll min(ll a, ll b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll n, x_1, x_2, y_1, y_2;
int main() {
  n = read();
  while(n --) {
    x_1 = read(); y_1 = read(); x_2 = read(); y_2 = read();
    if(x_1 == x_2) {
      printf("%lld %lld\n", x_1 - 1, y_1);
      continue;
    }
    if(y_1 == y_2) {
      printf("%lld %lld\n", y_1 + 1, x_1);
      continue;
    }
    int dx = std :: abs(x_2 - x_1), dy = abs(y_1 - y-2);
    while((dx ^ 1) && (dy ^ 1)) dx >>= 1, dy >>= 1;
    double k = 1.0 * (x_2 - x_1) / (y_2 - y_1);
    if(dx == dy) printf("%lld %lld\n", x_1, y_1 + (k > 0 ? 1 : -1));
    else printf("%lld %lld\n", )
    }
  return 0;
}