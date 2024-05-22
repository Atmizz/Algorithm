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
int n, dp[MaxN], a[MaxN], sum;
bool Check() {
  for(int i = 1; i <= n; ++ i)
    for(int j = sum; j >= 0; -- j)
      if(j >= a[i])
       dp[j] = dp[j] | dp[j-a[i]];
  if(dp[sum]) return true;
  return false;
}
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) a[i] = read(), sum += a[i];
  if(sum % 2) {printf("Flase"); return 0;}
  sum /= 2; dp[0] = 1;
  if(Check()) printf("True");
  else printf("False");
  return 0;
}