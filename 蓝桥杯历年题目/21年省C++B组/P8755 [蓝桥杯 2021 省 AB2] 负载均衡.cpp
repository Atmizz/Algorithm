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
const int MaxN = 2e5 + 300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m;
struct Computer {
  int t, v0;
}e[MaxN];
struct Node {
  int t, c, b;
  friend bool operator < (Node a, Node b) {
    return a.t > b.t;
  }
};
std :: priority_queue <Node> q;
int main() {
  n = read(); m = read();
  for(int i = 1; i <= n; ++ i) e[i].v0 = read();
  for(int i = 1; i <= m; ++ i) {
    int a = read(), b = read(), c = read(), d = read();
    while(q.size() && q.top().t <= a) e[q.top().b].v0 += q.top().c, q.pop();
    if(d <= e[b].v0) e[b].v0 -= d, q.push({a+c, d, b}), std :: cout << e[b].v0 << '\n';
    else printf("-1\n");
  }
  return 0;
}