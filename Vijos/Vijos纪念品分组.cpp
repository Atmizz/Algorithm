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
const int MaxN = 2e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int w, n, a[MaxN], ans, x = 1;
int main() {
  w = read(); n = read();
  for(int i = 1; i <= n; ++ i) a[i] = read();
  std :: sort(a + 1, a + 1 + n);
  for(int i = n; i >= x; -- i)
    if(a[i] > w) n --, ans ++;
    else if(a[i] + a[x] <= w) ans ++, x ++;
    else ans ++;
  printf("%d", ans); 
	return 0;
}