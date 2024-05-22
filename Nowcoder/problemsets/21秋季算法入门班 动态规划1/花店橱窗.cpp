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
const int N = 110;
i64 val[N][N], dp[N][N];
int F, V;
void solve() {
	std :: cin >> F >> V;
	for(int i = 1; i <= F; ++ i) {
		for(int j = 1; j <= V; ++ j) {
			std :: cin >> val[i][j];
		}
	}
	for(int i = 1; i <= V; ++ i) {
		dp[1][i] = val[1][i];
	}
	for(int i = 2; i <= F; ++ i) {
		for(int j = 1; j <= V; ++ j) {
			dp[i][j] = -LLONG_MAX / 2;
			for(int k = 1; k < j; ++ k) {
				dp[i][j] = max(dp[i][j], dp[i-1][k] + val[i][j]);
			}
		}
	}
	i64 ans = -LLONG_MAX / 2;
	for(int i = 1; i <= V; ++ i) {
		// deb(dp[F][i])
		ans = max(ans, dp[F][i]);
	}
	std :: cout << ans << nl;
	std :: vector <int> path;
	for(int i = F; i >= 1; -- i) {
		for(int j = 1; j <= V; ++ j) {
			if(ans == dp[i][j]) {
				path.pb(j);
				ans -= val[i][j];
				break;
			}
		}
	}
	for(int i = sz(path) - 1; i >= 0; -- i) {
		std :: cout << path[i] << ' ';
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