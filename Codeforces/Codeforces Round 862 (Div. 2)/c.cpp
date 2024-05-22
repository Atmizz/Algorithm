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
const int MaxN = 1e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll n, m, t;
double k[MaxN];
int main() {
  t = read();
  while(t --) {
    n = read(); m = read();
    for(int i = 1; i <= n; ++ i) k[i] = read();
    std :: sort(k + 1, k + 1 + n);
    for(int i = 1; i <= m; ++ i) {
      ll a = read(), b = read(), c = read();
      if(c < 0) {
        printf("NO\n");
        continue;
      } 
      double K = double(b - 2 * (double)sqrt(a * c));
      ll pos = std :: upper_bound(k + 1, k + 1 + n, K) - k;
      if(pos != n + 1 && k[pos] < b) {
        printf("YES\n%.0lf\n", k[pos]);
        continue;
      }
      pos = std :: lower_bound(k + 1, k + 1 + n, b) - k;
      if(pos != n + 1 && ((b - k[pos]) * (b - k[pos]) < 4 * a * c)) {
        printf("YES\n%.0lf\n", k[pos]);
        continue;
      } printf("NO\n");
    } puts("");
  }
  return 0;
}