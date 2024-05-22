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
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <i64> a(n+1), b(n+1);
	std :: vector dp(n+2, std :: vector <i64> (n+2));
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	for(int j = 1; j <= n; ++ j) {
		std :: cin >> b[j];
	}
	for(int len = n; len >= 1; -- len) {
		for(int i = 1; i <= n; ++ i) {
			int j = i + len - 1;
			if(j > n) {
				break;
			}
			dp[i][j-1] = max(dp[i][j-1], dp[i][j] + a[j] * b[n - len + 1]);
			dp[i+1][j] = max(dp[i+1][j], dp[i][j] + a[i] * b[n - len + 1]);
		}
	}
	i64 ans = 0;
	for(int i = 1; i <= n; ++ i) {
		ans = max(ans, dp[i][i-1]);
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