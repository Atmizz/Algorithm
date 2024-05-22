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
const int MaxN = 1010;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int v, n, f[1010];
int main() {
  n = read(), v = read();
  for(int i = 1; i <= n; ++ i) {
    int u = read(), w = read(), z = read();
    for(int j = v; j >= 0; -- j)
      for(int x = 0; x * u <= j && x <= z; ++ x)
        f[j] = max(f[j], f[j-u*x] + w*x);
  } printf("%d", f[v]);
  return 0;
}