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
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
inline int abs(int a) {return a < 0 ? -a : a;}
const int INF = 0x7fffffff;
const int MaxN = 2e5 + 200;
const int Mod = 1e9 + 7;
int n, a[250], dp[250], pre[250], Sign, ans = -INF, b[250], Num, Final;
int main() {
	n = read();
	for(int i = 1; i <= n; ++ i) a[i] = read(), dp[i] = 1, pre[i] = i;
	for(int i = 2; i <= n; ++ i)
		for(int j = 1; j < i; ++ j)
			if(a[j] <= a[i] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1, pre[i] = j;
	for(int i = 1; i <= n; ++ i)
		if(ans < dp[i]) ans = dp[i], Sign = i;
	printf("max=%d\n", ans); Num = ans;
	for(int i = Sign; pre[i] != i; i = pre[i]) b[ans] = a[i], ans --, Final = pre[i];
	printf("%d ", a[Final]);
	for(int i = 2; i <= Num; ++ i) printf("%d ", b[i]);
}