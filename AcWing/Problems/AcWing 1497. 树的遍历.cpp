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
const int MaxN = 1e6+300;
const int Mod = 35;
const int INF = 2147483647;
int n, inorder[MaxN], postorder[MaxN];
std :: unordered_map <int, int> l, r, pos;
int dfs(int il, int ir, int pl, int pr) {
  int root = postorder[pr], k = pos[root];
  if(il < k) l[root] = dfs(il, k - 1, pl, pl + k - 1 - il);
  if(ir > k) r[root] = dfs(k + 1, ir, pl + k - il, pr - 1);
  return root;
}
void bfs(int root) {
  std :: queue <int> q; q.push(root);
  while(!q.empty()) {
    auto u = q.front(); q.pop();
    printf("%d ", u);
    if(l.count(u)) q.push(l[u]);
    if(r.count(u)) q.push(r[u]);
  }
}
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) postorder[i] = read();
  for(int i = 1; i <= n; ++ i) inorder[i] = read(), pos[inorder[i]] = i;
  int root = dfs(1, n, 1, n); bfs(root);
  return 0;
}