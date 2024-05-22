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
inline ll max(ll a, ll b) {return a > b ? a : b;}
const int MaxN = 12;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
struct Node {
  int a, b, c, x, y;
}a[MaxN];
int n, t, p, vis[MaxN];
ll ans;
void dfs(int x, int T, ll score) {
  ans = max(ans, score);
  for(int i = 1; i <= n; ++ i)
    if(T + a[i].x <= t && !vis[i]) vis[i] = 1, dfs(i, T + a[i].x, score + max(a[i].c, a[i].a - (T + a[i].x) * a[i].b - a[i].y * p)), vis[i] = 0;
}
int main() {
  n = read(); t = read(); p = read();
  for(int i = 1; i <= n; ++ i)
    a[i].a = read(), a[i].b = read(), a[i].c = read(), a[i].x = read(), a[i].y = read();
  for(int i = 1; i <= n; ++ i)
    if(t >= a[i].x) vis[i] = 1, dfs(i, a[i].x, max(a[i].c, a[i].a - a[i].x * a[i].b - a[i].y * p)), vis[i] = 0;
  printf("%lld", ans);
  return 0;
}