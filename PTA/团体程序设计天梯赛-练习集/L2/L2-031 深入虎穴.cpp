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
const int MaxN = 1e5 + 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, dp[MaxN], ans = 1, pos = 1, du[MaxN];
std :: vector <int> g[MaxN];
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    int a = read();
    for(int j = 1; j <= a; ++ j) {
      int b = read(); du[b] ++;
      g[i].push_back(b);
    }
  }
  std :: queue <int> q;
  for(int i = 1; i <= n; ++ i)
    if(!du[i]) q.push(i);
  while(q.size()) {
    int u = q.front(); q.pop();
    for(auto v : g[u]) {
      du[v] --;
      dp[v] = max(dp[v], dp[u] + 1);
      if(dp[v] > ans) ans = dp[v], pos = v;
      if(!du[v]) q.push(v);
    }
  } printf("%d", pos);
  return 0;
}