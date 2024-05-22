#include <bits/stdc++.h>
#define gc getchar()
typedef long long ll;
inline int read() {
  int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
inline int max(int a, int b) { return a > b ? a : b;}
inline int min(int a, int b) { return a < b ? a : b;}
inline int abs(int a) { return a < 0 ? -a : a;}
const int MaxN = 1e4 + 200;
const int Mod = 1e9 + 7;
const int INF = 0x7fffffff;
int n, m, ans, du[MaxN], Money[MaxN];
std :: vector <int> son[MaxN];
int main() {
	n = read(), m = read();
	for(int i = 1; i <= m; ++ i) {
		int x = read(), y = read();
		du[x] ++; son[y].push_back(x);
	}
	bool Flag = 0;
	std :: queue <int> q;
	for(int i = 1; i <= n; ++ i)
		if(!du[i]) q.push(i), Flag = 1, ans += 100, Money[i] = 100;
	if(!Flag) {std :: cout << "Poor Xed"; return 0;}
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int i = 0; i < son[x].size(); ++ i) {
			ans += (Money[x] + 1); du[son[x][i]] --;
			if(du[son[x][i]] == 0) Money[son[x][i]] = Money[x] + 1, q.push(son[x][i]);
		}
	} printf("%d", ans);
}