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
const int MaxN = 1002;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, map[MaxN][MaxN];
int main() {
  n = read(), m = read();
  for(int i = 1; i <= m; ++ i) {
    int x_1 = read(), y_1 = read(), x_2 = read(), y_2 = read();
    for(int k = x_1; k <= x_2; ++ k)
      for(int j = y_1; j <= y_2; ++ j)
        map[k][j] ++;
  }
  for(int i = 1; i <= n; ++ i, puts(""))
    for(int j = 1; j <= n; ++ j)
      printf("%d ", map[i][j]);
  return 0;
}