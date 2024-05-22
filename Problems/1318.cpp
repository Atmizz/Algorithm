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
int n;
void dfs(int Savings, int Now, std :: vector <int> ans) {
	if(Savings < Now && Savings != 0) return ;
	if(Savings == 0) {
		printf("%d=", n);
		for(int i = 0; i < ans.size() - 1; ++ i)
			printf("%d+", ans[i]);
		printf("%d\n", ans.back());
		return ;
	}
	for(int i = Now; i <= Savings; ++ i)
		ans.push_back(i), dfs(Savings - i, i, ans), ans.pop_back();
}
int main() {
	n = read();
	for(int i = 1; i <= n / 2; ++ i) {
		std :: vector <int> ans; ans.push_back(i);
		dfs(n - i, i, ans);
	}
}