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
const int MaxN = 1005;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, q;
int a[MaxN][MaxN], b[MaxN][MaxN];
int main() {
  n = read(); m = read(); q = read();
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= m; ++ j)
      a[i][j] = read();
  for(int i = 1; i <= q; ++ i) {
    int x1 = read(), y1 = read(), x2 = read(), y2 = read(), c = read();
    b[x1][y1] += c; b[x2+1][y2+1] += c;
    b[x1][y2+1] -= c; b[x2+1][y1] -= c;
  }
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= m; ++ j)
      b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
  for(int i = 1; i <= n; ++ i, puts(""))
    for(int j = 1; j <= m; ++ j)
      printf("%d ", a[i][j] + b[i][j]);
  return 0;
}