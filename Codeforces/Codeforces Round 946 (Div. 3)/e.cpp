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
const int N = 1e5 + 20;
void solve() {
	int n, x;
	std :: cin >> n >> x;
	std :: vector <PII> v(n+1);
	i64 m = 0;
	for(int i = 1; i <= n; ++ i) {
		auto &[c, h] = v[i];
		std :: cin >> c >> h;
		m += h;
	}
	std :: vector dp(n+1, std :: vector <i64> (m+1));
	for(int i = 0; i <= m; ++ i) {
		dp[0][i] = -1;
	}
	dp[0][0] = 0;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 0; j <= m; ++ j) {
			dp[i][j] = dp[i-1][j];
		}
		auto &[c, h] = v[i];
		if(i == 1 && c == 0) {
			dp[i][h] = 0;
		}
		for(int j = h; j <= m; ++ j) {
			for(int k = 1; k < i; ++ k) {
				if(dp[k][j-h] != -1) {
					if(dp[k][j-h] + 1LL * (i - k) * x < c) {
						continue ;
					}
					dp[i][j] = max(dp[i][j], dp[k][j-h] + 1LL * (i - k) * x - c);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= m; ++ i) {
		if(dp[n][i] != -1) {
			ans = i;
		}
	}
	std :: cout << ans << nl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}