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
const int MaxN = 550;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int t, x, n, a[MaxN], b[MaxN], ans;
int main() {
  t = read();
  while(t --) {
    n = read(); x = read(); ans = 0;
    int Min = INF, Max = -INF, Index; bool flag = 1;
    for(int i = 1; i <= n; ++ i) {
      a[i] = b[i] = read(), Min = min(Min, a[i]);
      if(a[i] > Max) Max = a[i], Index = i;
    }
    for(int i = 1; i <= n; ++ i) if(a[i] < a[i-1]) {flag = 0; break;}
    if(flag) {printf("0\n"); continue;}
    if(Min < x || (Min == x && a[1] != Min)) {
      printf("-1\n"); continue;
    }
    if(Min == x && a[1] == Min) {
      bool flag = 1, SS = 0;
      for(int i = 2; i <= n; ++ i)
        if(a[i] == Min) {
          if(flag) continue;
          printf("-1\n");
          flag = 0; SS = 1; break;
        } else flag = 0;
      if(SS) continue;
    }
    b[Index] = x; std :: sort(b + 1, b + 1 + n);
    for(int i = 1; i <= n; ++ i)
      if(a[i] != b[i]) ans ++;
    printf("%d\n", ans);
  }
  return 0;
}