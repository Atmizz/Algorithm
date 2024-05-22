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
const int MaxN = 5e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, ans;
int main() {
  n = read(); m = read();
  for(int i = 1; i <= n; ++ i) {
    int x = i, z = 10;
    while(x) {
      if(x % z == m) ans ++;
      x /= z;
    }
  } printf("%d", ans);
}