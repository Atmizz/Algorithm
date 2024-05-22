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
const int MaxN = 2e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, l, r, f[MaxN << 1], ans = -INF, a[MaxN << 1];
struct Node {
  int val, pos;
  friend bool operator < (Node a, Node b) {
    return a.val == b.val ? a.pos < b.pos : a.val < b.val;
  }
};
std :: priority_queue <Node> q;
int main() {
  n = read(); l = read(); r = read();
  for(int i = 0; i <= n; ++ i) a[i] = read();
  memset(f, 0xcf, sizeof f);
  for(int i = l; i <= r; ++ i) f[i] = a[i];

  for(int i = 1; i <= n; ++ i) {
    while(q.size() && i - q.top().pos > r - l) q.pop();
    q.push({f[i], i}); f[i+l] = max(f[i+l], q.top().val + a[i+l]);
    if(i + l > n) ans = max(ans, f[i+l]);
  } printf("%d", ans);
  return 0;
}
/*
2 4
0 1 2 3 4 5 
now : 4
0 ~ 2
*/