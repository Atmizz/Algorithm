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
const int N = 55;
char g[N][N];
int n, m;
bool vis[N][N];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
void block(int x, int y) {
	for(int i = 0; i < 4; ++ i) {
		int dx = x + xx[i], dy = y + yy[i];
		if(dx < 1 || dx > n || dy < 1 || dy > m || g[dx][dy] == '#' || g[dx][dy] == 'G' || g[dx][dy] == 'B') continue;
		g[dx][dy] = '#';
	}
}
void dfs(int x, int y) {
	vis[x][y] = 1;
	 // deb(x); deb(y);
	for(int i = 0; i < 4; ++ i) {
		int dx = x + xx[i], dy = y + yy[i];
		if(dx < 1 || dx > n || dy < 1 || dy > m || g[dx][dy] == '#' || vis[dx][dy] == 1) continue;
		dfs(dx, dy);
	}
}
void solve() {
	std :: cin >> n >> m;
	int cnt = 0, ans = 0;
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			std :: cin >> g[i][j], vis[i][j] = 0, cnt += g[i][j] == 'G';
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			if(g[i][j] == 'B') block(i, j);
	dfs(n, m);
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j)
			if(g[i][j] == 'G' && vis[i][j] == 1) ans ++;
			else if(g[i][j] == 'B' && vis[i][j] == 1 && cnt > 0) {
				std :: cout << "No\n";
				return ;
			}
	std :: cout << (ans == cnt ? "Yes\n" : "No\n");
}

int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}