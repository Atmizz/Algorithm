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
ll t, n, sum, Even, Odd, q;
int main() {
  t = read();
  while(t --) {
    Even = Odd = sum = 0;
    n = read(); q = read();
    for(int i = 1; i <= n; ++ i) {
      int x = read(); sum += x;
      if(x % 2) Odd ++;
      else Even ++;
    }
    for(int i = 1; i <= q; ++ i) {
      int x = read(), y = read();
      if(x == 0) {
        sum += y * Even;
        if(y % 2) Odd += Even, Even = 0;
      } else {
        sum += y * Odd;
        if(y % 2) Even += Odd, Odd = 0;
      } printf("%lld\n", sum);
    }
  }
  return 0;
}