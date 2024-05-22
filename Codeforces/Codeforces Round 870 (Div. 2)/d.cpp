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
const int MaxN = 3e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int a[MaxN], T, n, l[MaxN], r[MaxN];
int main() {
  T = read();
  while(T --) {
    n = read(); int ans = 0; l[0] = r[n+1] = -INF;
    for(int i = 1; i <= n; ++ i) a[i] = read(), l[i] = r[i] = 0;
    for(int i = 1; i <= n; ++ i) l[i] = max(l[i-1], a[i] + i);
    for(int i = n; i >= 1; -- i) r[i] = max(r[i+1], a[i] - i);
    for(int i = 1; i <= n; ++ i)
      ans = max(ans, a[i] + l[i-1] + r[i+1]);
    printf("%d\n", ans);
  }
  return 0;
}