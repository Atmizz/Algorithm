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
const int MaxN = 1e5+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, a[MaxN], f[MaxN][22];
int query(int l, int r) {
  int k = 0;
  while(1 << (k + 1) <= r - l + 1) k ++;
  return max(f[l][k], f[r - (1 << k) + 1][k]);
}
int main() {
  while(1) {
    n = read();
    if(!n) break; m = read();
    memset(f, 0, sizeof f); memset(a, 0, sizeof a);
    for(int i = 1; i <= n; ++ i) a[i] = read();
    f[1][0] = 1;
    for(int i = 2; i <= n; ++ i)
      if(a[i] == a[i-1]) f[i][0] = f[i-1][0] + 1;
      else f[i][0] = 1;
    for(int j = 1; j <= 20; ++ j)
      for(int i = 1; i + (1 << j) - 1 <= n; ++ i)
        f[i][j] = max(f[i][j-1], f[i+(1<<(j-1))][j-1]);
    for(int i = 1; i <= m; ++ i) {
      int l = read(), r = read(), t = l;
      while(a[t] == a[t-1] && t <= r) t ++;
      if(t == r + 1) printf("%d\n", r - l + 1);
      else printf("%d\n", max(t - l, query(t, r)));
    }
  }
  return 0;
}