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
int n, ans;
void dfs(int x) {
  if(x < 10) {ans = x; return ;}
  int s = 0, k = 10;
  while(x) {
    s += (x % k);
    x /= k; k *= 10;
  } dfs(s);
}
int main() {
  n = read(); dfs(n);
  printf("%d", ans);
	return 0;
}