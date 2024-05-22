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
const int N = 501;
std :: mt19937 rd(114514);
int n, m, x, dp[3][N][1001];
char g[N][N];
void solve() {
	std :: cin >> n >> m >> x;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> g[i][j];
		}
	}
	for(int i = 0; i <= 2; ++ i) {
		for(int j = 0; j <= m; ++ j) {
			for(int k = 0; k <= x; ++ k) {
				dp[i][j][k] = -1;
			}
		}
	}
	dp[0][1][0] = dp[1][0][0] = 0;

	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			for(int k = 0; k <= x; ++ k) {

				if(dp[0][j][k] != -1) {
					if(g[i][j] == '?' && k != x) {
						dp[1][j][k+1] = std :: max(dp[1][j][k+1], dp[0][j][k] + 1);
					} else {
						dp[1][j][k] = std :: max(dp[1][j][k], dp[0][j][k] + (g[i][j] == '1'));
					}
				}

				if(dp[1][j-1][k] != -1) {
					if(g[i][j] == '?' && k != x) {
						dp[1][j][k+1] = std :: max(dp[1][j][k+1], dp[1][j-1][k] + 1);
					} else {
						dp[1][j][k] = std :: max(dp[1][j][k], dp[1][j-1][k] + (g[i][j] == '1'));
					}
				}

			}
		}

		for(int j = 1; j <= m; ++ j) {
			for(int k = 0; k <= x; ++ k) {
				dp[0][j][k] = dp[1][j][k];
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= x; ++ i) {
		ans = std :: max(ans, dp[1][m][i]);
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