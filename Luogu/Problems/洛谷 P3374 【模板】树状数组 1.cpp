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
int n, m, a[MaxN];
namespace Tree_Array {
  inline int lowbit(int x) { return x & (-x);}
  inline void Modify(int k, int x) {
    for(; k <= n; k += lowbit(k)) a[k] += x;
  }
  inline int Query(int x) {
    int sum = 0;
    for(; x; x -= lowbit(x)) sum += a[x];
    return sum;
  }
}
int main() {
  n = read(), m = read(); int x;
  for(int i = 1; i <= n; ++ i) x = read(), Tree_Array :: Modify(i, x);
  for(int i = 1; i <= m; ++ i) {
    int opt = read(), l = read(), r = read();
    if(opt == 1) Tree_Array :: Modify(l, r);
    else printf("%d\n", Tree_Array :: Query(r) - Tree_Array :: Query(l-1));
  }
  return 0;
}