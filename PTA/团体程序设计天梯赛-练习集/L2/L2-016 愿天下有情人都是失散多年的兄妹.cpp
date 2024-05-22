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
const int MaxN = 1e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
std :: map <std :: string, int> mr;
int n, cnt, flag;
bool vis[MaxN];
struct Node {
  std :: string sex;
  int fa = - 1, ma = - 1;
}t[MaxN];
void dfs1(int u, int step) {
  if(u == -1 || step > 5) return ;
  vis[u] = 1;
  dfs1(t[u].fa, step + 1);
  dfs1(t[u].ma, step + 1);
}
void dfs2(int u, int step) {
  if(u == -1 || step > 5 || flag) return ;
  if(vis[u] == 1) flag = 1;
  dfs2(t[u].fa, step + 1);
  dfs2(t[u].ma, step + 1);
}
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    int id; id = read();
    std :: cin >> t[id].sex;
    t[id].fa = read(), t[id].ma = read();
    if(t[id].fa != -1) t[t[id].fa].sex = "M";
    if(t[id].ma != -1) t[t[id].ma].sex = "F";
  } int k = read();
  while(k --) {
    int u = read(), v = read(); flag = 0;
    if(t[u].sex == t[v].sex) std :: cout << "Never Mind\n";
    else {
      memset(vis, 0, sizeof vis);
      dfs1(u, 1); dfs2(v, 1);
      printf(flag ? "No\n" : "Yes\n");
    }
  }
  return 0;
}