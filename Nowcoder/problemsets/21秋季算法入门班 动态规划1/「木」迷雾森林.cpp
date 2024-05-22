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
const int Mod = 2333;
const int N = 3030;
int dp[N][N], g[N][N];
void solve() {
	int n, m;
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> g[i][j];
		}
	}
	dp[n][1] = 1;
	int xx[2] = {0, -1};
	int yy[2] = {1, 0};
	for(int i = n; i >= 1; -- i) {
		for(int j = 1; j <= m; ++ j) {
			if(g[i][j] == 1) {
				continue ;
			}
			for(int k = 0; k < 2; ++ k) {
				int dx = i + xx[k];
				int dy = j + yy[k];
				if(dx < 1 || dx > n || dy < 1 || dy > m || g[dx][dy] == 1) {
					continue ;
				}
				dp[dx][dy] += dp[i][j];
				dp[dx][dy] %= Mod;
			}
		}
	}
	// for(int i = 1; i <= n; ++ i) {
	// 	for(int j = 1; j <= m; ++ j) {
	// 		std :: cout <<  dp[i][j] << " \n"[j == m];
	// 	}
	// }
	std :: cout << dp[1][m];
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