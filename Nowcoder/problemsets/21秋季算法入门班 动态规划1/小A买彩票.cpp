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
const int N = 150;
i64 dp[40][N];
i64 gcd(i64 a, i64 b) {
	return !b ? a : gcd(b, a % b);
}
void solve() {
	int n;
	std :: cin >> n;
	dp[0][0] = 1;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= 4; ++ j) {
			for(int k = i - 1; k <= 4 * (i - 1); ++ k) {
				dp[i][k+j] += dp[i-1][k];
				// print(dp[i][k+j]);
			}
		}
	}
	i64 ans = 0;
	for(int i = n * 3; i <= n * 4; ++ i) {
		ans += dp[n][i];
	}
	i64 p = 1;
	for(int i = 1; i <= n; ++ i) {
		p *= 4;
	}
	i64 g = gcd(ans, p);
	std :: cout << ans / g << '/' << p / g;
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