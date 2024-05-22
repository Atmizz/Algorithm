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
const int MaxN = 1030;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
std :: vector <int> g[MaxN];
int vis[MaxN], v, e, k, n, color[MaxN], flag;
void dfs(int u) {
  if(!flag) return ;
  for(auto v : g[u]) {
    if(color[v] == color[u]) {
      flag = 0; return ;
    } 
    if(!vis[v]) vis[v] = 1, dfs(v);
  }
}
int main() {
  v = read(); e = read(), k = read();
  for(int i = 1; i <= e; ++ i) {
    int u = read(), v = read();
    g[u].push_back(v); g[v].push_back(u);
  } n = read();
  while(n --) {
    memset(vis, 0, sizeof vis); flag = 1; int cnt = 0;
    std :: unordered_set <int> s;
    for(int i = 1; i <= v; ++ i) {
      color[i] = read();
      if(!s.count(color[i])) cnt ++, s.insert(color[i]);
    }
    if(cnt != k) flag = 0;
    for(int i = 1; i <= v; ++ i)
      if(!vis[i]) dfs(i);
    printf(flag ? "Yes\n" : "No\n");
  }
  return 0;
}