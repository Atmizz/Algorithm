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
const int MaxN = 5e4 + 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, ans;
struct Node {
  int x, y, r, flag;
  friend bool operator < (Node a, Node b) {
    return a.x < b.x;
  }
}p[MaxN];
double dis(int x1, int y1, int x2, int y2) {
  return sqrt(double((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1)));
}
void dfs(int x, int y, int R) {
  int l = std :: lower_bound(p + 1, p + 1 + n, (Node){x-R, 0}) - p;
  int r = std :: lower_bound(p + 1, p + 1 + n, (Node){x+R, 0}) - p;
  r = p[r].x <= x + R ? r : r - 1;
  for(int i = l; i <= r; ++ i)
    if(dis(x, y, p[i].x, p[i].y) <= R && !p[i].flag) ans ++, p[i].flag = 1, dfs(p[i].x, p[i].y, p[i].r);
}
int main() {
  n = read(); m = read();
  for(int i = 1; i <= n; ++ i)
    p[i].x = read(), p[i].y = read(), p[i].r = read(), p[i].flag = 0;
  std :: sort(p + 1, p + 1 + n);
  for(int i = 1; i <= m; ++ i) {
    int x = read(), y = read(), r = read();
    dfs(x, y, r);
  } printf("%d", ans);
  return 0;
}