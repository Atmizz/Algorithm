#include <bits/stdc++.h>
#define gc getchar()
typedef unsigned long long ll;
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = - 1;
	for(; ch >= '0' && ch <= '9'; ch = gc) s = (s << 3) + (s << 1) + (ch ^ 48);
	return s * f;
}
inline int abs(int a) { return a < 0 ? -a : a;}
inline int max(int a, int b) { return a > b ? a : b;}
inline int min(int a, int b) { return a < b ? a : b;}
const int MaxN = 1e6 + 200;
const int mod = 1e9 + 7;
const int INF = 0x7fffffff;
int T, n, m, Flag, ans_x, ans_y;
int main() {
	T = read();
	for(;T > 0; -- T) {
		n = read(), m = read(); Flag = 0;
		ans_x = n, ans_y = m;
		for(int i = 1; i <= n; ++ i) {
			for(int j = 1; j <= m; ++ j)
				if((i - 1 < 1 || j - 2 < 1) && (i - 1 < 1 || j + 2 > m) && (i + 1 > n || j - 2 < 1) && (i + 1 > n || j + 2 > m) && (i - 2 < 1 || j - 1 < 1) && (i - 2 < 1 || j + 1 > m) && (i + 2 > n || j - 1 < 1) && (i + 2 > n || j + 1 > m))
				{	ans_x = i, ans_y = j, Flag = 1; break;}
			if(Flag) break;
		}
		printf("%d %d\n", ans_x, ans_y);
	}
}