#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << endl;
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
template <class T>
T abs(T a) {
	return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1010;
int vis[N][N];
char g[N][N];
int n, m, cnt;
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
void dfs(int x, int y) {
	vis[x][y] = 1;
	for(int i = 0; i < 4; ++ i) {
		int dx = x + xx[i];
		int dy = y + yy[i];
		if(dx < 1 || dx > n || dy < 1 || dy > m || g[dx][dy] == '#' || vis[dx][dy] != 0) {
			continue ;
		}
		dfs(dx, dy);
	}
}
void dfs2(int x, int y, int id) {
	// std :: cout << x << ' ' << y << ' ' << vis[x][y] << '\n';
	cnt ++;
	if(vis[x][y] == 1) {
		vis[x][y] = id;
	}
	if(vis[x][y] < -1) {
		vis[x][y] = -id;
		return ;
	}
	if(vis[x][y] != -INF) {
		for(int i = 0; i < 4; ++ i) {
			int dx = x + xx[i];
			int dy = y + yy[i];
			if(dx < 1 || dx > n || dy < 1 || dy > m || g[dx][dy] == '#' || vis[dx][dy] == id || vis[dx][dy] == -id) {
				continue ;
			}
			dfs2(dx, dy, id);
		}
	}
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> g[i][j];
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			if(g[i][j] == '#') {
				vis[i][j] = -1;
				for(int k = 0; k < 4; ++ k) {
					int dx = i + xx[k];
					int dy = j + yy[k];
					if(g[dx][dy] == '.') {
						vis[dx][dy] = -2;
					}
				}
			}
		}
	}
	int ans = 1;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			if(g[i][j] == '.' && vis[i][j] == 0) {
				dfs(i, j);
			}
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			if(g[i][j] == '.' && vis[i][j] == 1) {
				cnt = 0;
				// std :: cout << i << ' ' << j << ' ' << "kai\n";
				dfs2(i, j, i * m + j);
				// deb(cnt);
				ans = max(ans, cnt);
			}
		}
	}
	// for(int i = 1; i <= n; ++ i) {
	// 	for(int j = 1; j <= m; ++ j) {
	// 		std :: cout << vis[i][j] << " \n"[j == m];
	// 	}
	// }
	std :: cout << ans;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	//std :: cin >> _; 
	while(_ --) solve();
	return 0;
}