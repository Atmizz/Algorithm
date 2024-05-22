#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2020;
int n, m, cntR, cntB, vis[N][N];
char g[N][N], h[N][N];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
void dfs(int x, int y) {
	vis[x][y] = 1;
	for(int i = 0; i < 4; ++ i) {
		int dx = x + xx[i];
		int dy = y + yy[i];
		if(dx < 1 || dx > n || dy < 1 || dy > m || vis[dx][dy]) {
			continue;
		}
		if(h[dx][dy] == '.' && g[dx][dy] == '.') {
			h[dx][dy] = '#';
			cntB ++;
		}
		if(g[dx][dy] == '#') {
			dfs(dx, dy);
		}
	}
}
void solve() {
	std :: cin >> n >> m; cntR = 0;
	memset(vis, 0, sizeof vis);
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> g[i][j];
			cntR += g[i][j] == '#';
		}
	}
	if(cntR == 0) {
		std :: cout << "Blue\n";
		return ;
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			if(g[i][j] == '#') {
				if(vis[i][j]) {
					continue;
				}
				memset(h, '.', sizeof h);
				cntB = 0;
				dfs(i, j);
				// deb(cntB);
				if(cntR + cntB == n * m) {
					std :: cout << "Red\n";
					return ;
				}
			}
		}
	}
	std :: cout << "Draw\n";
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