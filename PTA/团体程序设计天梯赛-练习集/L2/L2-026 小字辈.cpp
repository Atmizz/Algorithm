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
int n, ANS;
std :: vector <int> g[MaxN], ans;
void dfs(int u, int depth) {
  ANS = max(ANS, depth);
  for(auto v : g[u])
    dfs(v, depth + 1);
}
void dfs2(int u, int depth) {
  if(depth == ANS) ans.push_back(u);
  for(auto v : g[u])
    dfs2(v, depth+1);
}
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    int x = read();
    if(x != -1)
      g[x].push_back(i);
    else g[n+1].push_back(i);
  } dfs(n+1, 0);
  dfs2(n+1, 0);
  std :: sort(ans.begin(), ans.end());
  printf("%d\n", ANS);
  for(int i = 0; i < ans.size() - 1; ++ i)
    printf("%d ", ans[i]);
  printf("%d", ans[ans.size()-1]);
  return 0;
}