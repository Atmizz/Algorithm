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
const int MaxN = 110;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int a[MaxN][MaxN], b[MaxN][MaxN], ans[MaxN][MaxN], ra, ca, rb, cb;
int main() {
  ra = read(); ca = read();
  for(int i = 1; i <= ra; ++ i)
    for(int j = 1; j <= ca; ++ j)
      a[i][j] = read();
  rb = read(); cb = read();
  for(int i = 1; i <= rb; ++ i)
    for(int j = 1; j <= cb; ++ j)
      b[i][j] = read();
  if(ca != rb) {
    printf("Error: %d != %d", ca, rb);
    return 0;
  }
  for(int k = 1; k <= ca; ++ k)
    for(int i = 1; i <= ra; ++ i)
      for(int j = 1; j <= cb; ++ j)
        ans[i][j] += a[i][k] * b[k][j];
  printf("%d %d\n", ra, cb);
  for(int i = 1; i <= ra; ++ i, puts("")) {
    for(int j = 1; j < cb; ++ j)
      printf("%d ", ans[i][j]);
    std :: cout << ans[i][cb];
  }
  return 0;
}