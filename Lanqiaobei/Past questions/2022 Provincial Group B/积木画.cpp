#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e7 + 2;
int dp[N][3], n;
// dp[i][j] -> 第i列状态为j的方案数
// j = 0 -> 上非空
// j = 1 -> 下非空
// j = 2 -> 非空
void solve() {
	std :: cin >> n;
	dp[1][2] = 1; dp[2][0] = dp[2][1] = 1; dp[2][2] = 2;
	for(int i = 3; i <= n; ++ i) {
		dp[i][0] = ((dp[i][0] + dp[i-1][1]) % Mod + dp[i-2][2]) % Mod;
		dp[i][1] = ((dp[i][1] + dp[i-1][0]) % Mod + dp[i-2][2]) % Mod;
		dp[i][2] = ((((dp[i][2] + dp[i-1][2]) % Mod + dp[i-2][2]) % Mod + dp[i-1][0]) % Mod + dp[i-1][1]) % Mod;
	}
	std :: cout << dp[n][2];
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