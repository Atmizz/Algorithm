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
int T, n, d[MaxN], ans, Flag, a[MaxN];
int main() {
	T = read();
	for(;T > 0; -- T) {
		n = read(); a[0] = 0; Flag = 0;
		for(int i = 1; i <= n; ++ i)	d[i] = read();
		for(int i = 1; i <= n; ++ i) {
			if(d[i] <= a[i-1] && d[i] != 0) {
				printf("-1"); Flag = 1; break;
			}
			a[i] = d[i] + a[i-1];
		}
		if(!Flag)
			for(int i = 1; i <= n; ++ i)
				printf("%d ", a[i]);
		puts("");
	}
}