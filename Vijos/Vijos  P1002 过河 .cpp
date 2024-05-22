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
int n, s, t, l, x = 1, a[MaxN], f[MaxN], ans = INF;
int main() {
	l = read(); s = read(); t = read(); n = read();
	for(int i = 1; i <= n; ++ i) a[i] = read();
	for(int i = 1; i <= n; ++ i)
		if(a[i] >= s && a[i] <= t)
			f[i] = 1, x = i + 1;
		else break;
	for(int i = x; i <= n; ++ i) {
		f[i] = f[i-1] + 1;
		for(int j = 1; j < i; ++ j)
			if(a[i] - a[j] >= s && a[i] - a[j] <= t)
				f[i] = min(f[i], f[j] + 1);
			else break;
	}
	for(int i = 1; i <= n; ++ i) std :: cout << f[i] << " ";
	puts("");
	for(int i = n; i >= 1; -- i)
		if(a[i] >= l - t) ans = min(ans, f[i]);
	printf("%d", ans);
	return 0;
}