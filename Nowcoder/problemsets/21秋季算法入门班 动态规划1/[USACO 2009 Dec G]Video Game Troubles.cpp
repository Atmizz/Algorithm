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
// const int N = ;
void solve() {
	int n, v;
	std :: cin >> n >> v;
	std :: vector <i64> dp(v+1);
	for(int _ = 1; _ <= n; ++ _) {
		int m, initV;
		std :: cin >> initV >> m;
		std :: vector <PII> a;
		for(int i = 1; i <= m; ++ i) {
			int x, y;
			std :: cin >> x >> y;
			a.pb({x, y});
		}
		// for(int j = 0; j < 1 << m; ++ j) {
		// 	i64 price = (j > 0 ? initV : 0), val = 0;
		// 	for(int i = 0; i < m; ++ i) {
		// 		if(j >> i & 1) {
		// 			price += a[i].first;
		// 			val += a[i].second;
		// 		}
		// 	}
		// 	for(int i = v; i >= price; -- i) {
		// 		dp[_&1][i] = max(dp[_&1][i], dp[_-1&1][i-price] + val);
		// 	}
		// }
		// deb(dp[_][v])
		std :: vector <i64> res(v+1);
		for(int i = initV; i <= v; ++ i) {
			res[i] = dp[i-initV];
		}
		for(int i = 0; i < m; ++ i) {
			auto [x, y] = a[i];
			for(int j = v; j >= x + initV; -- j) {
				res[j] = max(res[j], res[j-x] + y);
			}
		}
		for(int i = v; i >= initV; -- i) {
			dp[i] = max(dp[i], res[i]);
		}
	}
	std :: cout << dp[v];
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