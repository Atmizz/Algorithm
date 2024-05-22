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
const int MaxN = 35;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, mid[MaxN], frt[MaxN], pos[MaxN];
std :: unordered_map <int, int> l, r;
int dfs(int fl, int fr, int ml, int mr) {
  int root = frt[fl], k = pos[root];
  if(k > ml) l[root] = dfs(fl + 1, k - ml + fl, ml, k - 1);
  if(k < mr) r[root] = dfs(fl + 1 + k - ml, fr, k + 1, mr);
  return root;
}
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) mid[i] = read();
  for(int i = 1; i <= n; ++ i) frt[i] = read();
  for(int i = 1; i <= n; ++ i) pos[mid[i]] = i;
  int root = dfs(1, n, 1, n);
  std :: queue <int> q; q.push(root);
  std :: vector <int> ans;
  while(q.size()) {
    int u = q.front(); q.pop();
    ans.push_back(u);
    if(r.count(u)) q.push(r[u]);
    if(l.count(u)) q.push(l[u]);
  }
  for(int i = 0; i < ans.size() - 1; ++ i)
    printf("%d ", ans[i]);
  printf("%d", *(ans.end()- 1));
  return 0;
}