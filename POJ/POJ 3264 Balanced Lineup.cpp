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
int n, m, a[MaxN][22], b[MaxN][22];
int Anwser(int l, int r) {
  int k = 0;
  while((1 << (k + 1)) <= r - l + 1) k ++;
  return max(a[l][k], a[r - (1 << k) + 1][k]) - min(b[l][k], b[r - (1 << k) + 1][k]);
}
int main() {
  n = read(); m = read();
  for(int i = 1; i <= n; ++ i)
    a[i][0] = b[i][0] = read();
  for(int j = 1; j <= 20; ++ j)
    for(int i = 1; i + (1 << j) - 1 <= n; ++ i) {
      a[i][j] = max(a[i][j-1], a[i + (1 << (j - 1))][j-1]);
      b[i][j] = min(b[i][j-1], b[i + (1 << (j - 1))][j-1]);
    }
  for(int i = 1; i <= m; ++ i) {
    int l = read(), r = read();
    printf("%d\n", Anwser(l, r));
  }
  return 0;
}