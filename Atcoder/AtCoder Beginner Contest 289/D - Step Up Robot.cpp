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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, A[12], B[MaxN], f[MaxN], X;
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) A[i] = read();
  m = read();
  for(int i = 1; i <= m; ++ i) {
    int x = read(); B[x] = 1;
  } X = read();
  for(int i = 1; i <= X; ++ i) f[i] = INF;
  for(int i = 0; i <= n; ++ i)
    if(!B[A[i]]) f[A[i]] = 1;
  for(int i = 1; i <= X; ++ i) {
    if(B[i]) continue;
    for(int j = 1; j <= n; ++ j) {
      if(B[i-A[j]] || i - A[j] < 0 || f[i-A[j]] == INF) continue;
      f[i] = min(f[i], f[i-A[j]] + 1);
    }
  }
  // printf("%d\n", f[X]);
  if(f[X] != INF && f[X] != 0) printf("Yes");
  else printf("No");
  return 0;
}