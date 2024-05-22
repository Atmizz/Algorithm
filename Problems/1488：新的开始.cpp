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
const int MaxN = 320;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
struct Node {
  int u, v, w;
  friend bool operator < (Node a, Node b) {
    return a.w < b.w;
  }
}a[MaxN << 4];
int n, ans, map[MaxN][MaxN], cnt, k, pa[MaxN], val[MaxN];
int Find(int x) {
  return x == pa[x] ? pa[x] : pa[x] = Find(pa[x]);
}
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) pa[i] = i;
  for(int i = 1; i <= n; ++ i) val[i] = read();
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= n; ++ j)
      map[i][j] = read();
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= n; ++ j)
      a[++cnt] = {i, j, map[i][j]};
//  printf("%d\n", ans);
  std :: sort(a + 1, a + 1 + cnt);
  for(int i = 1; i <= cnt; ++ i) {
    int u = a[i].u, v = a[i].v, w = a[i].w;
    u = Find(u); v = Find(v);
    if(u == v) continue;
    pa[u] = v; ans += w; k ++;
    if(k == n - 1) break;
  }
  for(int i = 1; i <= n; ++ i)
    if(val[pa[i]] > 0 && pa[i] == i) ans += val[pa[i]], val[pa[i]] = 0;
  printf("%d", ans);
  return 0;
}