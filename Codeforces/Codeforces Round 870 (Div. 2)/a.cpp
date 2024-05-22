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
int a[MaxN], n, t;
bool check(int x) {
  return (std :: upper_bound(a + 1, a + 1 + n, n - x) - a - 1) >= n - x;
}
int main() {
  t = read();
  while(t --) {
    n = read();
    for(int i = 1; i <= n; ++ i) a[i] = read();
    std :: sort(a + 1, a + 1 + n);
    int ans = -1; a[n+1] = a[n] + 1;
    for(int i = 1; i <= n; ++ i) {
      if(a[i] == a[i+1]) continue;
      if(n - i < a[i+1] && n - i >= a[i]) ans = n - i;
    }
    if(a[n] == 0) ans = 0;
    printf("%d\n", ans);
  } 
  return 0;
}