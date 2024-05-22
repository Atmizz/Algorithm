#include <bits/stdc++.h>
#define gc getchar()
#define ll long long
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
const int MaxN = 150;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, V,f[MaxN], x[MaxN], y[MaxN][MaxN], z[MaxN][MaxN];
int main() {
  n = read(); V = read();
  for(int i = 1; i <= n; ++ i) {
    x[i] = read();
    for(int j = 1; j <= x[i]; ++ j)
      y[i][j] = read(), z[i][j] = read();
  }
  for(int k = 1; k <= n; ++ k)
    for(int j = V; j >= 0; -- j)
      for(int i = 1; i <= x[k]; ++ i)
        if(j >= y[k][i])
          f[j] = max(f[j], f[j-y[k][i]] + z[k][i]);
  printf("%d", f[V]);
	return 0;
}