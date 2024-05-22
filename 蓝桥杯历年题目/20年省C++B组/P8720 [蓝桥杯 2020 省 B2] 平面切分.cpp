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
const int MaxN = 1010;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, ans;
double a[MaxN], b[MaxN];
std :: set <std :: pair<double, double> > s, p;
int main() {
  n = read();
  a[1] = read(), b[1] = read();
  s.insert({a[1], b[1]}); ans = 2;
  for(int i = 2; i <= n; ++ i) {
    scanf("%lf %lf", &a[i], &b[i]); int cnt = 0;
    if(s.count({a[i], b[i]})) continue;
    s.insert({a[i], b[i]}); p.clear();
    for(int j = 1; j < i; ++ j) {
      if(a[i] == a[j]) continue;
      double x = (b[i] - b[j]) / (a[i] - a[j]);
      double y = a[i] * x + b[i];
      if(p.count({x, y})) continue;
      p.insert({x, y}); cnt ++;
    } ans += cnt + 1;
  } printf("%d", ans);
  return 0;
}