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
int n, m, deg[MaxN], cnt, ans[MaxN], flag = 1;
std :: vector <int> G[MaxN];
int main() {
  n = read(); m = read();
  for(int i = 1; i <= m; ++ i) {
    int u = read(), v = read();
    G[u].push_back(v); deg[v] ++;
  }
  std :: queue <int> q;
  for(int i = 1; i <= n; ++ i)
    if(!deg[i]) q.push(i);
  while(q.size()) {
    int u = q.front(); q.pop();
    ans[u] = ++ cnt; flag &= q.empty();
    for(int v : G[u])
      if(!(--deg[v])) q.push(v);
  }
  if(cnt == n && flag) {
    printf("Yes\n");
    for(int i = 1; i <= n; ++ i)
      printf("%d ", ans[i]);
  }
  else printf("No");
  return 0;
}