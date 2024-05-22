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
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e6 + 20;
int n, dp[N][2], a[N], ans;
int DP(int x) {
	for(int i = 1; i <= n; ++ i)
		dp[i][0] = dp[i][1] = 0;
	dp[1][1] = x;
	for(int i = 2; i <= n; ++ i) {
		dp[i][1] = dp[i-1][0] + a[i];
		dp[i][0] = std :: max(dp[i-1][0], dp[i-1][1]);
	}
	if(x == 0) return std :: max(dp[n][0], dp[n][1]);
	return dp[n][0];
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	std :: cout << std :: max(DP(0), DP(a[1]));
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}