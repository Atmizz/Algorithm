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
const int MaxN = 2e5 + 200;
const int Mod = 998244353;
const int INF = 2147483647;
int n, f[MaxN][2], x[MaxN], y[MaxN];
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) x[i] = read(), y[i] = read();
  f[1][0] = f[1][1] = 1;
  for(int i = 2; i <= n; ++ i) {
    if(x[i] != x[i-1]) f[i][0] = (f[i][0] + f[i-1][0]) % Mod;
    if(x[i] != y[i-1]) f[i][0] = (f[i][0] + f[i-1][1]) % Mod;
    if(y[i] != x[i-1]) f[i][1] = (f[i][1] + f[i-1][0]) % Mod;
    if(y[i] != y[i-1]) f[i][1] = (f[i][1] + f[i-1][1]) % Mod;
  } printf("%d", (f[n][1] + f[n][0]) % Mod);
  return 0;
}