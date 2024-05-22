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
ll n, D, a[MaxN], ans;
int main() {
  n = read(); D = read();
  for(int i = 1; i <= n; ++ i) a[i] = read();
  std :: sort(a + 1, a + 1 + n);
  int x = 1, y = n;
  while(y > x) {
    if(a[y] > D) {ans ++, y --; continue;}
    ll t = 1;
    while(t * a[y] <= D && x < y) t ++, x ++;
 //   printf("t * a[%lld] : %lld   t : %lld\n", y, t * a[y], t);
    if(t * a[y] > D) y--, ans ++;
    if(x == y) break;
  } 
  if(a[x] > D) ans ++;
  printf("%lld", ans);
  return 0;
}