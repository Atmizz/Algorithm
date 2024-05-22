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
const int N = 25;
int xx[9] = {0, -1, -2, -2, -1, 1, 2, 2, 1};
int yy[9] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
int n, m, x, y;
i64 dp[N][N];
void solve() {
	std :: cin >> n >> m >> x >> y;
	dp[0][0] = 1;
	for(int i = 0; i < 9; ++ i) {
		int dx = x + xx[i];
		int dy = y + yy[i];
		if(dx < 0 || dx > n || dy < 0 || dy > m) {
			continue ;
		}
		dp[dx][dy] = -1;
	}
	for(int i = 0; i <= n; ++ i) {
		for(int j = 0; j <= m; ++ j) {
			if(dp[i][j] == -1) {
				continue ;
			}
			if(i - 1 >= 0 && dp[i-1][j] != -1) {
				dp[i][j] += dp[i-1][j];
			}
			if(j - 1 >= 0 && dp[i][j-1] != -1) {
				dp[i][j] += dp[i][j-1];
			}
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