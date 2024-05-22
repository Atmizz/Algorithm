#include <bits/stdc++.h>
#define gc getchar()
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
const int MaxN = 2200;
const int Mod = 1e9 + 7;
int ans[MaxN][MaxN], n, a, b;
int main() {
	n = read(); ans[0][0] = 1;
	for(int i = 1; i <= 2000; ++ i) ans[i][0] = 1;
	for(int i = 1; i <= 2000; ++ i)
		for(int j = 1; j <= i; ++ j)
			ans[i][j] = (ans[i-1][j] + ans[i-1][j-1]) % Mod;
	while(n)
		n --, a = read(), b = read(), printf("%d\n", ans[a][b]);
}