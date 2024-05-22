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
const int MaxN = 1e4 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, a[MaxN];
double ans;
int main() {
  n = read();
  for(int i = 1; i <= n * 5; ++ i) a[i] = read();
  std :: sort(a + 1, a + 1 + n * 5);
  for(int i = n + 1; i <= n * 4; ++ i)
    ans += (double) a[i];
  printf("%.15lf", ans / (double)(n * 3));
  return 0;
}