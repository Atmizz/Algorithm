#include <bits/stdc++.h>
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
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n, a[MaxN];
struct Node {
  int l, r;
  friend bool operator < (Node a, Node b) {
    return (a.r - a.l + 1) == (b.r - b.l + 1) ? a.l > b.l : (a.r - a.l + 1) < (b.r - b.l + 1);
  }
};
int main() {
  T = read();
  while(T --) {
    n = read(); int k = 0;
    std :: priority_queue <Node> q;
    q.push({1, n});
    while(q.size()) {
      Node p = q.top(); q.pop();
      if(p.l == p.r) {
        a[p.l] = ++k;
        continue;
      }
      int len = p.r - p.l + 1;
      int x = (len % 2) ? ((p.l + p.r) >> 1) : ((p.l + p.r - 1) >> 1);
      a[x] = ++k;
      if(x > p.l) q.push({p.l, x-1});
      q.push({x+1, p.r});
    }
    for(int i = 1; i <= n; ++ i) printf("%d ", a[i]);
    puts("");
  }
  return 0;
}