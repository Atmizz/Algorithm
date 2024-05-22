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
int n, m;
void dfs(int x, std :: vector <int> a) {
	if(x == m) {
		for(int i = 0; i < m; ++ i) printf("%3d", a[i]);
		puts(""); return ;
	}
	for(int i = a.back() + 1; i <= n; ++ i)
		a.push_back(i), dfs(x + 1, a), a.pop_back();
}
int main() {
	n = read(); m = read();
	for(int i = 1; i <= n - m + 1; ++ i) {
		std :: vector <int> a; a.push_back(i);
		dfs(1, a);
	}
}