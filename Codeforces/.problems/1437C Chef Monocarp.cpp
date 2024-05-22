#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 550;
void solve() {
	int n; std :: cin >> n;
	std :: vector <int> a(n);
	std :: vector dp(N + 1, std :: vector <int> (N + 1));
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i];
	for(int i = 1; i <= N; ++ i)
		for(int j = 1; j <= N; ++ j)
			dp[i][j] = INF;
	std :: sort(a.begin(), a.end());
	for(int i = 1; i <= N; ++ i)
		dp[1][i] = std :: abs(a[0] - i);
	for(int i = 2; i <= n; ++ i)
		for(int j = 1; j <= N; ++ j)
			for(int k = 1; k < j; ++ k)
				dp[i][j] = std :: min(dp[i][j], dp[i-1][k] + std :: abs(a[i-1] - j));
	int ans = INF;
	for(int i = 1; i <= N; ++ i)
		ans = std :: min(ans, dp[n][i]);
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