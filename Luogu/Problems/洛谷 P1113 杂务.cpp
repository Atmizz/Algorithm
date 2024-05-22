#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
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
const int MaxN = 1e4 + 300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, du[MaxN], pre[MaxN][101], len[MaxN], ans[MaxN];
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    int x = read(), y; len[i] = read();
    while(1) {
      y = read();
      if(y == 0) break ;
      pre[y][++pre[y][0]] = x, du[x] ++;
    }
  }
  std :: queue <int> q;
  for(int i = 1; i <= n; ++ i)
    if(du[i] == 0) q.push(i), ans[i] = len[i];
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int i = 1; i <= pre[u][0]; ++ i) {
      int v = pre[u][i]; du[v] --;
      if(du[v] == 0) q.push(v);
      ans[v] = max(ans[v], ans[u] + len[v]);
    }
  }
  for(int i = 1; i <= n; ++ i)
    ans[0] = max(ans[0], ans[i]);
  printf("%d", ans[0]);
  return 0;
}