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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
struct Node {
  int p, l;
  friend bool operator < (Node a, Node b) {
    return a.l < b.l;
  }
}a[MaxN];
int n, l, p, ans, x;
int main() {
  n = read();
  for(int i = n; i >= 1; -- i)
    a[i].l = read(), a[i].p = read();
  l = read(), p = read();
  for(int i = 1; i <= n; ++ i) a[i].l = l - a[i].l;
  std :: sort(a + 1, a + 1 + n);
//  for(int i = 1; i <= n; ++ i) printf("%d %d\n", a[i].l, a[i].p);
  std :: priority_queue <int> q;
  for(int i = 1; i <= n; ++ i)
    if(a[i].l <= p) q.push(a[i].p);
    else {x = i; break;}
  while(!q.empty()) {
    if(p >= l) break;
    p += q.top(); q.pop(); ans ++;
    while(x <= n) {
      if(a[x].l <= p) q.push(a[x].p), x ++;
      else break;
    }
  }
  if(p >= l) printf("%d", ans);
  else printf("-1");
  return 0;
}