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
const int MaxN = 1300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int sum[MaxN][MaxN], n, m, q;
int main() {
  n = read(); m = read(); q = read();
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= m; ++ j) {
      int x = read();
      sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + x;
    }
  for(int i = 1; i <= q; ++ i) {
    int x_1 = read(), y_1 = read(), x_2 = read(), y_2 = read();
    printf("%d\n", sum[x_2][y_2] - sum[x_1-1][y_2] - sum[x_2][y_1-1] + sum[x_1-1][y_1-1]);
  }
  return 0;
}