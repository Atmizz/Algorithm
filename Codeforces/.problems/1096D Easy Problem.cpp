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
	int n;
	std :: cin >> n;
	std :: string s;
	std :: cin >> s;
	s = '0' + s;
	std :: vector <i64> a(n+1);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	std :: vector dp(n+1, std ::vector <i64> (4));
	for(int i = 1; i <= n; ++ i) {
		for(int j = 0; j < 4; ++ j) {
			dp[i][j] = dp[i-1][j];
		}
		if(s[i] == 'h') {
			dp[i][0] += a[i];
		} else if(s[i] == 'a') {
			dp[i][1] = std :: min(dp[i][0], dp[i][1] + a[i]);
		} else if(s[i] == 'r') {
			dp[i][2] = std :: min(dp[i][1], dp[i][2] + a[i]);
		} else if(s[i] == 'd') {
			dp[i][3] = std :: min(dp[i][2], dp[i][3] + a[i]);
		}
	}
	i64 ans = LLINF;
	for(int i = 0; i < 4; ++ i) {
		// deb(i);
		// deb(dp[n][i])
		ans = min(ans, dp[n][i]);
	}
	std :: cout << ans;
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