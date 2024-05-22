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
int n, k, a[MaxN], c[(1<<20)], ans;
int main() {
  n = read(), k = read();
  for(int i = 1; i <= n; ++ i) a[i] = read();
  for(int i = 1; i <= n; ++ i) {
    int sum = 0;
    for(int j = 20; j >= 0; -- j) {
      if((k >> j) & 1) {
        if((a[i] >> j) & 1) {
          c[sum + (1<<j)] ++;
          c[sum + (1<<j+1)] --;
        } else {
          c[sum] ++;
          c[sum + (1<<j)] --;
          sum += 1 << j;
        }
      } else sum = sum + ((a[i] >> j & 1) << j);
    }
  }
  ans = c[0];
  for(int i = 1; i < (1 << 20); ++ i)
    c[i] += c[i-1], ans = max(ans, c[i]);
    printf("%d", ans);
  return 0;
}