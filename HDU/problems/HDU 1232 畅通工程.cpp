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
int n, m, pa[MaxN], k;
int Find(int x) { return pa[x] == x ? x : pa[x] = Find(pa[x]);}
int main() {
  while(1) {
    n = read();
    if(n == 0) break;
    m = read(); k = 0;
    for(int i = 1; i <= n; ++ i) pa[i] = i;
    for(int i = 1; i <= m; ++ i) {
      int u = read(), v= read();
      u = Find(u), v = Find(v);
      if(u != v) k ++, pa[u] = v;
    } printf("%d\n", n - k - 1);
  }
  return 0;
}