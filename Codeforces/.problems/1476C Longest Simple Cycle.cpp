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
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
	int n; std :: cin >> n;
	std :: vector <i64> l(n+1), r(n+1), a(n+1), b(n+1), c(n+1), dp(n+1);
	for(int i = 1; i <= n; ++ i)
		std :: cin >> c[i];
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i)
		std :: cin >> b[i];
	for(int i = 1; i < n; ++ i) {
		l[i] = a[i+1], r[i] = b[i+1];
		if(l[i] > r[i]) std :: swap(l[i], r[i]);
	}

	dp[n] = c[n]; l[n] = 1; r[n] = c[n];
	i64 ans = 0;
	for(int i = n - 1; i >= 1; -- i) {
		 // deb(i); deb(l[i+1]); deb(r[i+1]);
		int L = l[i+1], R = r[i+1];
		dp[i] = c[i+1] + r[i] - l[i] + 1;
		if(L < R)
			dp[i] = std :: max(r[i] - l[i] + 1 + dp[i+1] - 2 * (R - L) + c[i+1], dp[i]);
		else 
			dp[i] = std :: max(dp[i], c[i+1] + r[i] - l[i] + 1);
		 // deb(dp[i]);
		ans = std :: max(ans, dp[i]);
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