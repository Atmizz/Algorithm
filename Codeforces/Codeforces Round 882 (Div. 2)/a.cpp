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
int T, n, k, a[MaxN];
ll ans;
int main() {
  T = read();
  while(T --) {
    n = read(); k = read(); ans = 0;
    std :: priority_queue <int> q;
    for(int i = 1; i <= n; ++ i) {
      a[i] = read();
      if(i != 1) ans += abs(a[i] - a[i-1]), q.push(abs(a[i] - a[i-1]));
    } k --;
    while(k --) {
      // std :: cout << q.top() << '\n';
      ans -= q.top(); q.pop();
    }
    printf("%lld\n", ans);
  }
  return 0;
}