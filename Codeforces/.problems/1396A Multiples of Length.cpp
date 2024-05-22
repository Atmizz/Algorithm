#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
#define int ll
inline int read() {
  int s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 1e5 + 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, a[MaxN];
signed main() {
  n = read();
  for(int i = 1; i <= n; ++ i) a[i] = read();
  if(n == 1) {
    printf("1 1\n%lld\n", a[1]);
    printf("1 1\n%lld\n", a[1]);
    printf("1 1\n%lld\n", -3*a[1]);
    return 0;
  }
  printf("1 1\n%lld\n", -a[1]);
  a[1] = 0;
  printf("2 %lld\n", n);
  for(int i = 2; i <= n; ++ i)
    printf("%lld ", a[i] * (n-1));
  puts("");
  printf("1 %lld\n", n);
  for(int i = 1; i <= n; ++ i)
    printf("%lld ", -n * a[i]);
  return 0;
}