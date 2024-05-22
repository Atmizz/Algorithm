#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 55;
int n, m, ans, vis[N][N];
char g[N][N];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
int xxx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int yyy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
void dfs1(int x, int y) {
	vis[x][y] = 1;
	// std :: cout << x << ' ' << y << '\n';
	for(int i = 0; i < 8; ++ i) {
		int dx = x + xxx[i];
		int dy = y + yyy[i];
		if(dx < 1 || dx > n || dy < 1 || dy > m || vis[dx][dy] || g[dx][dy] == '1') {
			continue ;
		}
		dfs1(dx, dy);
	}
}
void dfs2(int x, int y) {
	vis[x][y] = 1;
	// std :: cout << x << ' ' << y << ' ' << 1 << '\n';
	for(int i = 0; i < 4; ++ i) {
		int dx = x + xx[i];
		int dy = y + yy[i];
		if(dx < 1 || dx > n || dy < 1 || dy > m || vis[dx][dy] || g[dx][dy] == '0') {
			continue ;
		}
		dfs2(dx, dy);
	}
}
void solve() {
	std :: cin >> n >> m; ans = 0;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> g[i][j];
			vis[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; ++ i) {
		if(!vis[i][1] && g[i][1] == '0') {
			// std :: cout << i << ' ' << 1 << ' ' << 0 << '\n';
			dfs1(i, 1);
		}
		if(!vis[i][m] && g[i][m] == '0') {
			dfs1(i, m);
		}
	}
	for(int i = 1; i <= m; ++ i) {
		if(!vis[1][i] && g[1][i] == '0') {
			dfs1(1, i);
		}
		if(!vis[n][i] && g[n][i] == '0') {
			dfs1(n, i);
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			if(g[i][j] == '1' || (g[i][j] == '0' && !vis[i][j])) {
				continue;
			}
			// std :: cout << i << ' ' << j << '\n';
			for(int k = 0; k < 4; ++ k) {
				int dx = i + xx[k];
				int dy = j + yy[k];
				if(dx < 1 || dx > n || dy < 1 || dy > m || vis[dx][dy] || g[dx][dy] == '0') {
					continue ;
				}
				ans ++;
				dfs2(dx, dy);
			}
		}
	}
	std :: cout << ans << '\n';
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