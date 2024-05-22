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
const int MaxN = 2e5 + 10;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, t;
double ans, d, h, y[MaxN];
int main() {
  t = read();
  while(t --) {
    n = read(); scanf("%lf %lf", &d, &h); ans = 0;
    for(int i = 1; i <= n; ++ i) scanf("%lf", &y[i]);
    std :: sort(y + 1, y + 1 + n); y[n+1] = INF;
    for(int i = n; i >= 1; -- i) {
      if(y[i+1] >= y[i] + h) ans += d * h / 2;
      else ans += (d + d * ((h-y[i+1]+y[i])/h)) * (y[i+1] - y[i]) / 2;
    } printf("%.7lf\n", ans);
  }
  return 0;
}