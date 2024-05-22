#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x7f7f7f7f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const i64 Range = 1e18;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 88;
i64 dis[N][N][N][N], money[N][N], ans[N][N];
i64 p[N][N], r[N][N], d[N][N];
int n;
void solve() {
	std :: cin >> n;
	for(int i = 0; i <= n; ++ i) {
		for(int j = 0; j <= n; ++ j) {
			for(int k = 0; k <= n; ++ k) {
				for(int h = 0; h <= n; ++ h) {
					dis[i][j][k][h] = Range;
				}
			}
		}
	}
	for(int i = 0; i <= n; ++ i) {
		for(int j = 0; j <= n; ++ j) {
			ans[i][j] = Range;
			for(int k = i; k <= n; ++ k) {
				for(int h = j; h <= n; ++ h) {
					if(i == k && j == h && i > 0 && j > 0) {
						dis[i][j][k][h] = 0;
					}
				}
			}
		}
	}
	ans[1][1] = 0;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			std :: cin >> p[i][j];
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j < n; ++ j) {
			std :: cin >> r[i][j];
		}
	}
	for(int i = 1; i < n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			std :: cin >> d[i][j];
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			for(int k = i; k <= n; ++ k) {
				for(int h = j; h <= n; ++ h) {
					if(i == k && j == h) {
						continue;
					}
					dis[i][j][k][h] = std :: min(dis[i][j][k][h],
						std :: min(dis[i][j][k][h-1] + r[k][h-1],
							dis[i][j][k-1][h] + d[k-1][h]));
				}
			}
		}
	}
//////////////////////////////////////////////////////////////

	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			for(int k = 1; k <= i; ++ k) {
				for(int h = 1; h <= j; ++ h) {
					if(i == k && j == h) {
						continue;
					}
					i64 step = std :: max(0.0, std :: ceil(1.0 * (dis[k][h][i][j] - money[k][h]) / p[k][h]));
					if(i - k + j - h + step + ans[k][h] < ans[i][j]) {
						ans[i][j] = ans[k][h] + step + i - k + j - h;
						money[i][j] = money[k][h] + step * p[k][h] - dis[k][h][i][j];
					} else if(i - k + j - h + step + ans[k][h] == ans[i][j]) {
						money[i][j] = std :: max(money[i][j], money[k][h] + step * p[k][h] - dis[k][h][i][j]);
					}
					// std :: cout << k << ' ' << h << ' ' << i << ' ' << j << ' ' << ans[i][j] << ' ' << step << '\n';
				}
			}
		}
	}
	std :: cout << ans[n][n];
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
	return 0;
}