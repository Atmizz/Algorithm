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
const int MaxN = 5e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int f[MaxN][22], n, m, s, cnt, head[MaxN<<1], dep[MaxN];
struct Node {
  int to, net;
}e[MaxN<<2];
inline void Insert(int u, int v) {
  e[++cnt] = {v, head[u]};
  head[u] = cnt;
}
void dfs(int u, int pa) {
  f[u][0] = pa; dep[u] = dep[pa] + 1;
  for(int i = 1; dep[u] - (1 << i) >= 0; ++ i)
    f[u][i] = f[f[u][i-1]][i-1];
  for(int i = head[u]; i; i = e[i].net)
    if(e[i].to != pa) dfs(e[i].to, u);
}
int query(int x, int y) {
  if(dep[x] < dep[y]) std :: swap(x, y);
  for(int i = 21; i >= 0; -- i)
    if(dep[f[x][i]] >= dep[y]) x = f[x][i];
  if(x == y) return x;
  for(int i = 21; i >= 0; -- i)
    if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  return f[x][0];
}
int main() {
  n =  read(), m = read(), s = read();
  for(int i = 1; i < n; ++ i) {
    int u = read(), v = read();
    Insert(u, v); Insert(v, u);
  } dfs(s, s);
  for(int i = 1; i <= m; ++ i) {
    int u = read(), v = read();
    printf("%d\n", query(u, v));
  }
  return 0;
}