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
#define ll long long
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
const int MaxN = 8e4+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
struct Node
{
  int net, to, dis;
}e[MaxN];
int n, m, T, cnt, head[MaxN], f[MaxN][22], dep[MaxN], dis[MaxN];
void Insert(int u, int v, int w) {
  e[++cnt] = (Node) {head[u], v, w};
  head[u] = cnt;
}
void dfs(int u, int fa) {
  f[u][0] = fa; dep[u] = dep[fa] + 1;
  for(int i = 1; u - (1 << i) >= 0; ++ i)
    f[u][i] = f[f[u][i-1]][i-1];
  for(int i = head[u]; i; i = e[i].net) {
    int v = e[i].to;
    if(v == fa) continue;
    dis[v] = dis[u] + e[i].dis; dfs(v, u);
  }
}
int LCA(int x, int y) {
  if(dep[x] < dep[y]) std :: swap(x, y);
  for(int i = 21; i >= 0; -- i)
    if(dep[f[x][i]] >= dep[y]) x = f[x][i];
  if(x == y) return x;
  for(int i = 21; i >= 0; -- i)
    if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  return f[x][0];
}
int main() {
  T = read();
  while(T --) {
    n = read(); m = read(); cnt = 0;
    memset(head, 0, sizeof head);
    memset(dis, 0, sizeof dis);
    memset(dep, 0, sizeof dep);
    memset(head, 0, sizeof head);
    for(int i = 1; i < n; ++ i) {
      int u = read(), v = read(), w= read();
      Insert(u, v, w); Insert(v, u, w);
    } dfs(1, 1);
    for(int i = 1; i <= m; ++ i) {
      int u = read(), v = read();
      printf("%d\n", dis[u] + dis[v] - 2 * dis[LCA(u, v)]);
    }
  }
  return 0;
}