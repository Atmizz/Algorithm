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
const int MaxN = 6e3 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int dp[MaxN][2], n;
std :: vector <int> son[MaxN];
bool haveBoss[MaxN];
void dfsDP(int u) {
  if(son[u].empty()) return ;
  int sum = 0;
  for(auto x : son[u]) {
    dfsDP(x);
    dp[u][0] = max(dp[u][0], dp[u][0] + max(dp[x][1], dp[x][0]));
    if(dp[x][0] > 0) sum += dp[x][0];
  } dp[u][1] += sum;
}
int main() {
  while(~scanf("%d", &n)) {
    memset(haveBoss, 0, sizeof haveBoss);
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; ++ i) dp[i][1] = read(), son[i].clear();
    for(int i = 1; i < n; ++ i) {
      int u = read(), v = read();
      son[v].push_back(u);
      haveBoss[u] = 1;
    }
    for(int i = 1; i <= n; ++ i)
      if(haveBoss[i] == 0) {
        dfsDP(i);
        printf("%d\n", max(dp[i][1], dp[i][0]));
        break;
      }
  }
  return 0;
}