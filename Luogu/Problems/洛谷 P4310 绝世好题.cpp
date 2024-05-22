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
int a[MaxN], dp[33], n, ans;
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i)
    a[i] = read();
  for(int i = 1; i <= n; ++ i) {
    int k = 0;
    for(int j = 0; j < 32; ++ j)
      if(a[i] & (1 << j))
        dp[j] ++, k = max(k, dp[j]);
    for(int j = 0; j < 32; ++ j)
      if(a[i] & (1 << j))
        dp[j] = k;
  }
  for(int i = 0; i < 32; ++ i)
    ans = max(dp[i], ans);
  printf("%d", ans);
  return 0;
}