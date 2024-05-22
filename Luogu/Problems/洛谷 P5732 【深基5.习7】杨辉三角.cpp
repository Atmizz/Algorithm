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
int n, a[25][25];
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i)
    a[i][1] = a[i][i] = 1;
  for(int i = 2; i <= n; ++ i)
    for(int j = 2; j <= i; ++ j)
      a[i][j] = a[i-1][j] + a[i-1][j-1];
  for(int i = 1; i <= n; ++ i) {
    for(int j = 1; j <= i; ++ j)
      printf("%d ", a[i][j]);
    puts("");
  }
  return 0;
}