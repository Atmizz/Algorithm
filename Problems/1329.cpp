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
int n, m, ans;
bool Flag[150][150];
char Map[150][150];
struct Node {
	int x, y;
};
bool Check(int x, int y) {
	if(x >= 1 && x <= n && y >= 1 && y <= m && !Flag[x][y] && Map[x][y] != '0') return true;
	return false;
}
void BFS(int x, int y) {
	Flag[x][y] = 1;
	std :: queue <Node> Q;
	Q.push({x, y});
	while(!Q.empty()) {
		int x0 = Q.front().x, y0 = Q.front().y; Q.pop();
		if(Check(x0+1, y0)) Q.push({x0+1, y0}), Flag[x0+1][y0] = 1;
		if(Check(x0-1, y0)) Q.push({x0-1, y0}), Flag[x0-1][y0] = 1;
		if(Check(x0, y0+1)) Q.push({x0, y0+1}), Flag[x0][y0+1] = 1;
		if(Check(x0, y0-1)) Q.push({x0, y0-1}), Flag[x0][y0-1] = 1;
	}
}
int main() {
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			std :: cin >> Map[i][j];
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			if(Check(i, j)) BFS(i, j), ans ++;
	printf("%d", ans);
}