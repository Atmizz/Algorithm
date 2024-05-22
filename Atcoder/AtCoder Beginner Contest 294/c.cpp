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
const int MaxN = 1e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m;
struct Node {
  int val, id;
  friend bool operator < (Node a, Node b) {
    return a.val < b.val;
  }
}c[MaxN<<1];
int ans[MaxN << 1];
int main() {
  n = read(); m = read();
  for(int i = 1; i <= n + m; ++ i) c[i].val = read(), c[i].id = i;
  std :: sort(c + 1, c + 1 + n + m);
  for(int i = 1; i <= n + m; ++ i) ans[c[i].id] = i;
  for(int i = 1; i <= n + m; ++ i) {
    std :: cout << ans[i] << ' ';
    if(i == n) puts("");
  }
  return 0;
}