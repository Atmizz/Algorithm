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
int T, n, a[MaxN], sum[MaxN];
int main() {
  T = read();
  while(T --) {
    n = read();
    for(int i = 1; i <= n; ++ i) a[i] = read();
    int temp = a[1]; sum[n] = a[n];
    for(int i = n - 1; i >= 1; -- i) sum[i] = sum[i+1] & a[i];
    for(int i = 2; i <= n; ++ i) temp &= a[i];
    if(temp != 0) {
      printf("1\n");
      continue;
    }
    int ans = 0;
    for(int i = 1; i <= n; ++ i) {
      int temp = a[i];
      if(sum[i] != 0) continue;
      ans ++;
      while(temp != 0) temp &= a[++i];
    }
    printf("%d\n", ans);
  }
  return 0;
}