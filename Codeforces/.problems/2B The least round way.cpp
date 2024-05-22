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
int n, num[N][N][2], dp[N][N][2], g[N][N], ans[N][N];
void solve() {
	std :: cin >> n;
	bool isZero = 0;
	int zx, zy;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			std :: cin >> g[i][j];
			int x = g[i][j];
			if(x == 0) {
				isZero = 1;
				zx = i, zy = j;
			}
			while(x && x % 2 == 0) {
				num[i][j][0] ++;
				x /= 2;
			}
			x = g[i][j];
			while(x && x % 5 == 0) {
				num[i][j][1] ++;
				x /= 5;
			}
		}
	}
	for(int i = 2; i <= n; ++ i) {
		for(int k = 0; k < 2; ++ k) {
			dp[0][i][k] = dp[i][0][k] = INT_MAX / 2;
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			for(int k = 0; k < 2; ++ k) {
				dp[i][j][k] = min(dp[i-1][j][k], dp[i][j-1][k]) + num[i][j][k];
			}
			ans[i][j] = min(dp[i][j][0], dp[i][j][1]);
		}
	}
	auto dfs = [&](auto dfs, int x, int y, int z) -> void{
		int xx[2] = {0, -1};
		int yy[2] = {-1, 0};
		std :: string s = "RD";
		for(int i = 0; i < 2; ++ i) {
			int dx = x + xx[i];
			int dy = y + yy[i];
			if(dx < 1 || dx > n || dy < 1 || dy > n) {
				continue ;
			}
			if(dp[x][y][z] == dp[dx][dy][z] + num[x][y][z]) {
				dfs(dfs, dx, dy, z);
				// std :: cout << x << ' ' << y << '\n';
				std :: cout << s[i];
				return ;
			}
		}
	};
	if(isZero && ans[n][n] != 0) {
		std :: cout << 1 << '\n';
		for(int i = 1; i < zx; ++ i) {
			std :: cout << "D";
		}
		for(int i = 1; i < zy; ++ i) {
			std :: cout << "R";
		}
		for(int i = zx; i < n; ++ i) {
			std :: cout << "D";
		}
		for(int i = zy; i < n; ++ i) {
			std :: cout << "R";
		}
	} else {
		std :: cout << ans[n][n] << nl;
		if(dp[n][n][1] > dp[n][n][0]) {
			dfs(dfs, n, n, 0);
		} else {
			dfs(dfs, n, n, 1);
		}
	}
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