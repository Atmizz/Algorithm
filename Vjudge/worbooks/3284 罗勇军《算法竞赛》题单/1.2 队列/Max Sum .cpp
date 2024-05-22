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
int T, n, sum[MaxN], ans, ansL, ansR;
struct Node {
  int pos, sum;
  friend bool operator < (Node a, Node b) {
    return a.sum > b.sum;
  }
};
int main() {
  T = read();
  for(int _ = 1; _ <= T; ++ _) {
    n = read(); ans = -INF;
    std :: priority_queue <Node> q;
    for(int i = 1; i <= n; ++ i) {
      int x = read(); sum[i] = sum[i-1] + x;
    } q.push((Node){0, 0});
    for(int i = 1; i <= n; ++ i) {
      if(sum[i] - q.top().sum > ans) ans = sum[i] - q.top().sum, ansL = q.top().pos + 1, ansR = i;
      q.push((Node){i, sum[i]});
    }
    printf("Case %d:\n%d %d %d\n", _, ans, ansL, ansR);
    if(_ < T) puts("");
  }
  return 0;
}