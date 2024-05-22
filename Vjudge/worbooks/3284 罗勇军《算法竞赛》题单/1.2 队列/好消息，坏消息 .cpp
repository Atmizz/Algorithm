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
int n, a[MaxN << 1], ans, sum[MaxN << 1];
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) a[i] = a[i+n] = read();
  for(int i = 1; i <= n << 1; ++ i) sum[i] = sum[i-1] + a[i];
  std :: deque <int> q;
  for(int i = 1; i <= n; ++ i) {
    while(q.size() && sum[q.back()] >= sum[i]) q.pop_back();
    q.push_back(i);
  }
  for(int i = 1 + n; i <= (n << 1); ++ i) {
    while(q.size() && sum[q.back()] >= sum[i]) q.pop_back();
    q.push_back(i);
    while(q.front() <= i - n) q.pop_front();
    if(sum[q.front()] - sum[i-n] >= 0) ans ++;
  } printf("%d", ans);
  return 0;
}