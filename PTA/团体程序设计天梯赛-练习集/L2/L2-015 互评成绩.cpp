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
inline double min(double a, double b) {return a < b ? a : b;}
inline double max(double a, double b) {return a > b ? a : b;}
const int MaxN = 1e4 + 300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
double judge[MaxN][13], ans[MaxN];
int n, m, k;
int main() {
  n = read(); k = read(); m = read();
  for(int i = 1; i <= n; ++ i) judge[i][k+1] = 120.00;
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= k; ++ j)
      scanf("%lf", &judge[i][j]), judge[i][0] += judge[i][j], judge[i][k+1] = min(judge[i][k+1], judge[i][j]), judge[i][k+2] = max(judge[i][k+2], judge[i][j]);
  for(int i = 1; i <= n; ++ i)
    judge[i][0] -= (judge[i][k+1] + judge[i][k+2]), ans[i] = judge[i][0] / (k - 2);
  std :: sort(ans + 1, ans + 1 + n);
  for(int i = n - m + 1; i <= n - 1; ++ i)
    printf("%.3lf ", ans[i]);
  printf("%.3lf", ans[n]);
  return 0;
}