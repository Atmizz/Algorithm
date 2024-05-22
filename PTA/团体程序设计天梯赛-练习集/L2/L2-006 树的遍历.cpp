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
const int MaxN = 50;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int Back[MaxN], Mid[MaxN], n;
std :: unordered_map <int, int> l, r, pos;
int dfs(int ml, int mr, int bl, int br) {
  int root = Back[br], k = pos[root];
  if(ml < k) l[root] = dfs(ml, k - 1, bl, bl + k - 1 - ml);
  if(mr > k) r[root] = dfs(k + 1, mr, bl + k - ml, br - 1);
  return root;
}
void BFS(int root) {
  std :: queue <int> q; q.push(root);
  std :: vector <int> ans;
  while(q.size()) {
    auto u = q.front(); q.pop();
    ans.push_back(u);
    if(l.count(u)) q.push(l[u]);
    if(r.count(u)) q.push(r[u]);
  }
  printf("%d", ans[0]);
  for(int i = 1; i < ans.size(); ++ i) printf(" %d", ans[i]);
}
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) Back[i] = read();
  for(int i = 1; i <= n; ++ i) Mid[i] = read(), pos[Mid[i]] = i;
  int root = dfs(1, n, 1, n); BFS(root);
  return 0;
}