#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

char g[510][510];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n, m, k;
int lx, ly, num, cnt, now;
void dfs(int x, int y) {
	if(now == num - k) return ;
	now ++; g[x][y] = '.';
	for(int i = 0; i < 4; ++ i) {
		int xx = x + dx[i], yy = y + dy[i];
		if(xx < 1 || xx > n || yy < 1 || yy > m || g[xx][yy] != 'X') continue;
		dfs(xx, yy);
	}
}
void clean(int x, int y) {
	g[x][y] = 'X';
	for(int i = 0; i < 4; ++ i) {
		int xx = x + dx[i], yy = y + dy[i];
		if(xx < 1 || xx > n || yy < 1 || yy > m || g[xx][yy] != '.') continue;
		dfs(xx, yy);
	}
}
void solve() {
	std :: cin >> n >> m >> k;
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			std :: cin >> g[i][j];
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			if(g[i][j] == '.')
				num ++, g[i][j] = 'X';
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			if(g[i][j] == 'X') {
				now = 0;
				dfs(i, j);
				if(now != num - k) clean(i, j);
				else return ;
			}
}

int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j)
			std :: cout << g[i][j];
		std :: cout << endl;
	}
	return 0;
}