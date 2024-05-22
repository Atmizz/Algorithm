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
inline ll abs(ll a) {return a < 0 ? -a : a;}
inline ll min(int a, int b) {return a < b ? a : b;}
inline ll max(ll a, ll b) {return a > b ? a : b;}
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll t, n, a[MaxN];
int main() {
  t = read();
  while(t --) {
    n = read(); ll Max = 0, sum = 0, Min = INF;
    for(int i = 1; i <= n; ++ i) {
      a[i] = read(); sum += a[i];
      if(Max < abs(a[i])) Max = a[i];
      if(Min > abs(a[i])) Min = a[i];
    } printf("%lld\n", max(abs(sum), max(abs(abs(Max) - abs(sum - Max)),abs(abs(Min) - abs(sum-Min)))));
  }
  return 0;
}