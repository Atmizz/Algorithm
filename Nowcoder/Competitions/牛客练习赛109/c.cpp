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
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, Dfs[MaxN], Size[MaxN];
std :: vector < std :: pair<int, int> > ans;
void dfs(int x, int id) {
  int Son = Size[x] - 1, sum = Son, u = 1;
  // std :: cout << x << " " << Son << '\n';
  if(Son == 0) return;
  std :: vector < std :: pair <int, int> > son;
  while(sum) {
    // std :: cout << sum << ' ' << u << '\n';
    // std :: cout << Size[Dfs[id+u]];
    son.push_back(std :: make_pair(Dfs[id+u], id+u));
    ans.push_back(std :: make_pair(min(x, Dfs[id+u]), max(x, Dfs[id+u])));
    sum -= Size[Dfs[id+u]]; u = Size[Dfs[id+u]] + u;
  }
  for(auto v : son) dfs(v.first, v.second);
}
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) Dfs[i] = read();
  for(int i = 1; i <= n; ++ i) Size[i] = read();
  dfs(Dfs[1], 1);
  std :: sort(ans.begin(), ans.end());
  for(auto x : ans)
    std :: cout << x.first << " " << x.second << '\n';
  return 0;
}