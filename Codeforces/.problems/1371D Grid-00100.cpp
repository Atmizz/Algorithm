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
const int MaxN = 320;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n, k, g[MaxN][MaxN];
void solve() {
  n = read(); k = read();
  if(k % n == 0) puts("0");
  else puts("2");
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= n; ++ j)
      g[i][j] = 0;
  int p = 1, q = 1;
  while(k --) {
    std :: cout << p << ' ' << q << '\n';
    g[p][q] = 1;
    p ++, q ++; q %= (n + 1), q = (q == 0 ? 1 : q);
    if(p == n + 1)
      p = 1, q ++, q %= (n + 1), q = (q == 0 ? 1 : q);
  }
  for(int i = 1; i <= n; ++ i, puts(""))
    for(int j = 1; j <= n; ++ j)
      std :: cout << g[i][j];
}
int main() {
  T = read();
  while(T --) solve();
  return 0;
}