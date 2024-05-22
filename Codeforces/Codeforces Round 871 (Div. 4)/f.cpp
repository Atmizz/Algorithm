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
const int MaxN = 220;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int du[MaxN], T, n, m;
int main() {
  T = read();
  while(T --) {
    n = read(), m = read();
    for(int i = 1; i <= n; ++ i) du[i] = 0;
    for(int i = 1; i <= m; ++ i) {
      int l = read(), r = read();
      du[l] ++; du[r] ++;
    }
    std :: sort(du + 1, du + 1 + n);
    int x;
    if(du[n] == du[n-1]) {
      for(int i = 1; i <= n; ++ i)
        if(du[i] > 1) {x = du[i]; break;}
    } else x = du[n];
    printf("%d %d\n", x, m / x - 1);
  }
  return 0;
}