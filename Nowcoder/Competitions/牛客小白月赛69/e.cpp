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
const int MaxN = 500;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int x[MaxN], y[MaxN];
int n, ans;
int d(int a, int b) {
  return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) x[i] = read(), y[i] = read();
  for(int i = 1; i <= n; ++ i)
    for(int j = i + 1; j <= n; ++ j)
      for(int k = j + 1; k <= n; ++ k) {
          if((y[k] - y[i]) * (x[j] - x[i]) == (y[j] - y[i]) * (x[k] - x[i])) continue;
          int d1 = d(i, j), d2 = d(i, k), d3 = d(k, j);
          if(d1 == d2 || d2 == d3 || d1 == d3) ans ++;
        }
  printf("%d", ans);
  return 0;
}