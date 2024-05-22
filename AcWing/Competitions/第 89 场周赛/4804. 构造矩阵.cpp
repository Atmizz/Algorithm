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
const int MaxN = 130;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int A[MaxN][MaxN], B[MaxN][MaxN], n, m, X[MaxN], Y[MaxN];
bool visX[MaxN], visY[MaxN];
int main() {
  n = read(), m = read();
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= m; ++ j) {
      A[i][j] = read();
      if(A[i][j] == 0) visX[i] = 1, visY[j] = 1;
    }
  for(int i = 1; i <= n; ++ i)
    if(visX[i])
      for(int j = 1; j <= m; ++ j)
        B[i][j] = 1;
  for(int i = 1; i <= m; ++ i)
    if(visY[i])
      for(int j = 1; j <= n; ++ j)
        B[j][i] = 1;
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= m; ++ j)
      if(B[i][j]) X[i] ++;
  for(int i = 1; i <= m; ++ i)
    for(int j = 1; j <= n; ++ j)
      if(B[j][i]) Y[i] ++;
  for(int i = 1; i <= n; ++ i)
    if(X[i] == m) visX[i] = 1;
  for(int i = 1; i <= m; ++ i)
    if(Y[i] == n) visY[i] = 1;  
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j <= m; ++ j) {
      if(A[i][j] == 0) continue;
//      printf("i %d j %d X %d Y %d\n", i, j, visX[i], visY[j]);
      if(visX[i] && visY[j]) {
        printf("NO");
        return 0;
      }
    }
  printf("YES\n");
  for(int i = 1; i <= n; ++ i, puts(""))
    for(int j = 1; j <= m; ++ j)
      printf("%d ", B[i][j] ^ 1);
  return 0;
}