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
const int MaxN = 2550;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int k, n;
double dp[MaxN][MaxN], s[MaxN], p[MaxN], sz[MaxN], a[MaxN];
std :: vector <int> g[MaxN];
void dfs(int u) {
  dp[u][1] = a[u]; sz[u] = 1;
  for(auto v : g[u]) {
    dfs(v); sz[u] += sz[v];
    for(int i = min(k+1, sz[u]); i >= 1; -- i)
      for(int j = 0; j <= min(i-1, sz[v]); ++ j)
        dp[u][i] = max(dp[u][i], dp[u][i-j] + dp[v][j]);
  }
}
bool check(double mid) {
  for(int i = 1; i <= n; ++ i) a[i] = p[i] - mid * s[i];
  // for(int i = 0; i <= n; ++ i)
  //   printf("%.3lf\n", a[i]);
  for(int i = 0; i <= n; ++ i)
    for(int j = 1; j <= k + 1; ++ j)
      dp[i][j] = -1e9;
  dfs(0);
  return dp[0][k+1] >= 0.0;
}
int main() {
  k = read(); n = read();
  for(int i = 1; i <= n; ++ i) {
    scanf("%lf %lf", &s[i], &p[i]);
    int r = read(); g[r].push_back(i);
  }
  double l = 0, r = 10000;
  while(r - l > 1e-4) {
    double mid = (l + r) / 2;
    if(check(mid)) l = mid;
    else r = mid;
  }
  printf("%.3lf", l);
  return 0;
}