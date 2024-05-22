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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int f_max[255][255][21], f_min[255][255][21], b, n, k, Log2;
int Query(int l, int r) {
  int maxn = -INF, minn = INF;
  for(int i = r; i < r + b; ++ i) {
    minn = min(minn, min(f_min[l][i][Log2], f_min[l+b-(1<<Log2)][i][Log2]));
    maxn = max(maxn, max(f_max[l][i][Log2], f_max[l+b-(1<<Log2)][i][Log2]));
//    printf("l:%d l':%d f_min1:%d f_min2:%d\n", l, l + b - (1 << Log2), f_min[l][i][Log2], f_min[l+b-(1<<Log2)][i][Log2]);
  }
//  printf("max : %d  min : %d\n", maxn, minn);
  return maxn - minn;
}
int main() {
  n = read(), b = read(), k = read();
  while((1 << (Log2 + 1)) <= b) Log2 ++;// std :: cout << "Log2 : " << Log2 << '\n';
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= n; ++ j)
      f_max[i][j][0] = f_min[i][j][0] = read();
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= 20; ++ j)
      for(int k = 1; k + (1 << (j-1)) - 1 <= n; ++ k) {
        f_max[k][i][j] = max(f_max[k][i][j-1], f_max[k+(1<<(j-1))][i][j-1]);
        f_min[k][i][j] = min(f_min[k][i][j-1], f_min[k+(1<<(j-1))][i][j-1]);
//        printf("%d %d %d %d %d\n",k,i,j,f_max[k][i][j],f_min[k][i][j]);
      }
  for(int i = 1; i <= k; ++ i) {
    int l = read(), r = read();
    printf("%d\n", Query(l, r));
  }
  return 0;
}