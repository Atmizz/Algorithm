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
const int MaxN = 5e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, a[MaxN], sum[MaxN];
struct Node {
  int pos, sum;
  friend bool operator < (Node a, Node b) {
    return a.sum > b.sum;
  }
};
void queryAns() {
  int ans = -INF;
  std :: priority_queue <Node> q;
  q.push((Node){0, 0});
  for(int i = 1; i <= n; ++ i) {
    while(q.top().pos + m < i) q.pop();
    ans = max(ans, sum[i] - q.top().sum);
    q.push((Node){i, sum[i]});
  } printf("%d", ans);
}
int main() {
  n = read(); m = read(); 
  for(int i = 1; i <= n; ++ i) a[i] = read(), sum[i] = sum[i-1] + a[i];
  queryAns();
  return 0;
}