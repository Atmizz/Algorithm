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
const int MaxN = 2e3 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int N, a[MaxN], b[MaxN], f[MaxN][MaxN];
int dp() {
  for(int i = 1; i <= N; ++ i) b[i] = a[i];
  std :: sort(b + 1, b + 1 + N);
  for(int i = 1; i <= N; ++ i) {
    int minv = INF;
    for(int j = 1; j <= N; ++ j) {
      minv = min(minv, f[i-1][j]);
      f[i][j] = minv + abs(a[i]-b[j]);
    }
  }
  int res = INF;
  for(int i = 1; i <= N; ++ i) res = min(res, f[N][i]);
  return res;
}
int main() {
  N = read();
  for(int i = 1; i <= N; ++ i) a[i] = read();
  int res = dp();
  std :: reverse(a + 1, a + 1 + N);
  res = min(res, dp());
  printf("%d", res);
  return 0;
}