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
struct Node_1 {
  int t, b;
  friend bool operator < (Node_1 &a, Node_1 &b) {
    return a.t < b.t;
  }
}a[MaxN];
struct Node_2 {
  int t, b;
  friend bool operator < (Node_2 &a, Node_2 &b) {
    return a.b + a.t > b.b + b.t;
  }
}b[MaxN];
int z, n, T, num_1, num_2, _;
int main() {
  z = read();
  while(z --) {
    num_1 = num_2 = _ = 0;
    n = read(); T = read();
    for(int i = 1; i <= n; ++ i) {
      int x = read(), y = read();
      if(y > 0) a[++num_1].t = x, a[num_1].b = y;
      else b[++num_2].t = x, b[num_2].b = y;
    }
    std :: sort(a + 1, a + 1 + num_1);
    std :: sort(b + 1, b + 1 + num_2);
    for(int i = 1; i <= num_1; ++ i)
      if(T > a[i].t) T += a[i].b;
      else {
        _ = 1; break;
      }
    for(int i = 1; i <= num_2; ++ i) {
      if(T > b[i].t) T += b[i].b;
      else {
        _ = 1; break;
      } if(T <= 0) {
        _ = 1; break;
      }
    }
    if(_) printf("-1s\n");
    else printf("+1s\n");
  }
  return 0;
}