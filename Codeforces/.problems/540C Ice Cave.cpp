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
#define DEB std :: cout << "ok" << '\n';
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
const int N = 550;
int n, m, r1, c1, r2, c2, vis[N][N];
int xx[4] = {1, -1, 0, 0};
int yy[4] = {0, 0, 1, -1};
char g[N][N];
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> g[i][j];
			vis[i][j] = (g[i][j] == 'X');
		}
	}
	std :: cin >> r1 >> c1 >> r2 >> c2;
	auto dfs = [&](auto dfs, int x, int y) -> void {
		// std :: cout << x << ' ' << y << ' ' << vis[x][y] << nl;
		for(int i = 0; i < 4; ++ i) {
			int dx = x + xx[i];
			int dy = y + yy[i];
			if(dx < 1 || dx > n || dy < 1 || dy > m) {
				continue ;
			}
			if(vis[dx][dy] == 1) {
				if(dx == r2 && dy == c2) {
					std :: cout << "YES";
					exit(0);
				}
			} else {
				vis[dx][dy] = 1;
				dfs(dfs, dx, dy);
			}
		}
	};
	dfs(dfs, r1, c1);
	std :: cout << "NO";
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