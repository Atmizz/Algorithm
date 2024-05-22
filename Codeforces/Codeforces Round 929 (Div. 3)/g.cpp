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
// const int N = ;
int get(int a, int b) {
	return (a % b == 0) ? b : a % b;
}
void solve() {
	int n, m, q;
	std :: cin >> n >> m >> q;
	int g[9][5][5] = {0}, h[9][5][5] = {0};
	g[1][1][2] = g[1][2][2] = g[1][3][1] = g[1][4][1] = 1;
	g[3][1][2] = g[3][2][1] = g[3][3][1] = g[3][4][2] = 1;
	g[5][1][3] = g[5][1][4] = g[5][2][1] = g[5][2][2] = 1;
	g[7][1][2] = g[7][1][3] = g[7][2][1] = g[7][2][4] = 1;
	for(int k = 2; k <= 8; k += 2) {
		for(int i = 1; i <= 4; ++ i) {
			for(int j = 1; j <= 4; ++ j) {
				g[k][i][j] = g[k-1][i][j] ^ 1;
			}
		}
	}
	for(int k = 1; k <= 8; k ++) {
		for(int i = 1; i <= 4; ++ i) {
			for(int j = 1; j <= 4; ++ j) {
				h[k][i][j] = g[k][i][j];
			}
		}
	}

	int ans = 8;
	bool vis[9] = {0};
	std :: cout << ans << '\n';
	while(q --) {
		int x, y;
		std :: string str;
		std :: cin >> x >> y >> str;
		int val = (str == "square");

		int dx = get(x, 4);
		int dy = get(y, 2);
		for(int k = 1; k <= 4; ++ k) {
			if(vis[k]) {
				continue;
			}
			h[k][dx][dy] = val;
			if(val != g[k][dx][dy]) {
				vis[k] = 1;
				ans --;
			}
		}

		dx = get(x, 2);
		dy = get(y, 4);
		for(int k = 5; k <= 8; ++ k) {
			if(vis[k]) {
				continue;
			}
			h[k][dx][dy] = val;
			if(val != g[k][dx][dy]) {
				vis[k] = 1;
				ans --;
			}
		}

		// for(int i = 1; i <= 8; ++ i) {
		// 	if(!vis[i]) {
		// 		deb(i);
		// 	}
		// }
		std :: cout << ans << '\n';
	}
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