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
const int Mod = 1e9 + 7;
const int INF = 2147483647;
struct Node {
  int u, v, w;
  friend bool operator < (Node a, Node b) {
    return a.w < b.w;
  }
}e[MaxN];
int n, m, ans, cnt, pa[MaxN];
int Find(int x) { return x == pa[x] ? pa[x] : pa[x] = Find(pa[x]);}
int main() {
  n = read(), m = read();
  for(int i = 1; i <= n; ++ i) pa[i] = i;
  for(int i = 1; i <= m; ++ i)
    e[i].u = read(), e[i].v = read(), e[i].w = read();
  std :: sort(e + 1, e + 1 + m);
  for(int i = 1; i <= m; ++ i) {
    int u = Find(pa[e[i].u]), v = Find(pa[e[i].v]);
    if(u == v) continue; cnt ++;
    ans += e[i].w; pa[u] = v;
    if(cnt == n - 1) break;
  }
  if(cnt == n - 1) printf("%d", ans);
  else printf("orz");
  return 0;
}