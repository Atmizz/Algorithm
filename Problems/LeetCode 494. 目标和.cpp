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
int dp[23][MaxN], sum, a[MaxN], t, n;
int main() {
  n = read(), t = read();
  for(int i = 1; i <= n; ++ i) a[i] = read(), sum += a[i];
  dp[1][1000+a[1]] ++; dp[1][1000-a[1]] ++;
  for(int i = 2; i <= n; ++ i)
    for(int j = sum; j >= -sum; -- j)
      if(dp[i-1][j+1000]) dp[i][j+1000+a[i]] += dp[i-1][j+1000],  dp[i][j+1000-a[i]] += dp[i-1][j+1000];
  printf("%d", dp[n][t+1000]);
  return 0;
}