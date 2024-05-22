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
const int MaxN = 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, p, dp[MaxN][MaxN], sz[MaxN], Index[MaxN], root, son[MaxN];
std :: vector <int> g[MaxN];
void dfs(int u) {
  sz[u] = 1;
  for(auto v : g[u]) {
    dfs(v); sz[u] += sz[v];
    for(int j = sz[u]; j >= 0; -- j)
      for(int k = 1; k < j; ++ k)
        dp[u][j] = min(dp[u][j], dp[u][j-k] + dp[v][k] - 1);
  }
}
int main() {
  n = read(); p = read();
  for(int i = 1; i < n; ++ i) {
    int u = read(), v = read();
    g[u].push_back(v);
    Index[v] ++; son[u] ++;
  } memset(dp, 0x3f, sizeof dp);
  for(int i = 1; i <= n; ++ i) {
    if(!Index[i]) root = i;
    dp[i][1] = son[i];
  }
  dfs(root);
  for(int i = 1; i <= n; ++ i)
    dp[root][p] = min(dp[root][p], dp[i][p] + 1);
  printf("%d", dp[root][p]);
  return 0;
}