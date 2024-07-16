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
const int M = 1e5 + 20;
int g[N][N], dp[N][N];
void solve() {
	int n, m;
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> g[i][j];
		}
	}
	std :: vector <int> minn(M, INF);
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			dp[i][j] = (i == 1 && j == 1) ? 0 : INF;
			if(i > 1) {
				dp[i][j] = min(dp[i-1][j] + 1, dp[i][j]);
			}
			if(j > 1) {
				dp[i][j] = min(dp[i][j-1] + 1, dp[i][j]);
			}
			// deb(g[i][j]);
			std :: vector <int> v;
			v.pb(g[i][j]);
			int tmp = dp[i][j];
			for(int k = 2; k * k <= g[i][j]; ++ k) {
				if(g[i][j] % k == 0) {
					// deb(k);
					dp[i][j] = min(dp[i][j], minn[k] + 1);
					v.pb(k);
					if(k * k != g[i][j]) {
						v.pb(g[i][j]/k);
						dp[i][j] = min(dp[i][j], minn[g[i][j]/k] + 1);
					}
					tmp = min(tmp, dp[i][j]);
				}
			}
			for(auto &x : v) {
				minn[x] = min(minn[x], tmp);
			}
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cout << dp[i][j] << " \n"[j == m];
		}
	}
	std :: cout << dp[n][m];
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