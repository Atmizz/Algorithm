#include <bits/stdc++.h>
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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, ans, pa[MaxN];
int Find(int x) { return x == pa[x] ? x : pa[x] = Find(pa[x]);}
void Unity(int u, int v) { u = Find(pa[u]); v = Find(pa[v]); pa[u] = v;}
int main() {
  n = read(); m = read();
  for(int i = 1; i <= n * 3; ++ i) pa[i] = i;
  for(; m; -- m) {
    int opt = read(), u = read(), v = read();
    if(u > n || v > n) {ans ++; continue;}
    if(opt == 1) {
      if(Find(u + n) == Find(v) || Find(u + 2 * n) == Find(v)) {ans ++; continue;}
      Unity(u, v); Unity(u + n, v + n); Unity(u + 2 * n, v + 2 * n);
    } else {
      if(Find(u) == Find(v) || Find(u + 2 * n) == Find(v)) {ans ++; continue;}
      Unity(u + n, v); Unity(u + 2 * n, v + n); Unity(u, v + 2 * n);
    }
//    std :: cout << m << " " << ans << '\n';
  } printf("%d", ans);
  return 0;
}