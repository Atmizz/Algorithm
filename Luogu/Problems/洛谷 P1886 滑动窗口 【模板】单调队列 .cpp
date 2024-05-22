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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
struct Node {
  int id, val;
}a[MaxN];
int n, m;
void Min() {
  std :: deque <Node> q;
  for(int i = 1; i <= n; ++ i) {
    while(!q.empty() && q.front().val >= a[i].val) q.pop_front();
    q.push_front(a[i]);
    while(q.back().id <= i - m) q.pop_back();
    if(i >= m) printf("%d ", q.back().val);
  } puts("");
}
void Max() {
  std :: deque <Node> q;
  for(int i = 1; i <= n; ++ i) {
    while(!q.empty() && q.front().val <= a[i].val) q.pop_front();
    q.push_front(a[i]);
    while(q.back().id <= i - m) q.pop_back();
    if(i >= m) printf("%d ", q.back().val);
  }
}
int main() {
  n = read(), m = read();
  for(int i = 1; i <= n; ++ i) a[i].val = read(), a[i].id = i;
  Min(); Max();
  return 0;
}