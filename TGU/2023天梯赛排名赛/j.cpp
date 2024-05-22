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
const int MaxN = 0;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
double ans = 0.006;
int main() {
  int x = read();
  if(x >= 0 && x < 73) {
    ans = 90 - x;
  }
  else if(x >= 74 && x <= 88) {
    for(int i = 1; i <= x - 74; ++ i)
      ans = ans + 0.06;
    ans = 1 / ans;
  } else ans = 1;
  if(ans > 90 - x) ans = 90 - x;
  printf("%.3lf", ans);
  return 0;
}