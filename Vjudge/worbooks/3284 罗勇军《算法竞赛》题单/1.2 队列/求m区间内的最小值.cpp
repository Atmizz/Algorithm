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
const int MaxN = 2e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, a[MaxN];
void queryMin() {
  std :: deque <int> q; q.push_back(1);
  std :: cout << 0 << std :: endl;
  for(int i = 2; i <= n; ++ i) {
    while(q.front() + m < i) q.pop_front();
    printf("%d\n", a[q.front()]);
    while(q.size() && a[q.back()] >= a[i]) q.pop_back();
    q.push_back(i);
  }
}
int main() {
  n = read(); m = read();
  for(int i = 1; i <= n; ++ i) a[i] = read();
  queryMin();
  return 0;
}