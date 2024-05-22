#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e8;

int dp[110][110][15][2];
// dp[i][j][k][l]
// 表示用了i个footman，j个horseman，且最后有连续k个footman/horseman(0/1)
// 状态转移
// dp[i+1][j][k+1][0] <- dp[i][j][k][0] (k+1 <= n1)
// dp[i+1][j][1][0]   <- dp[i][j][k][1]
// dp[i][j+1][k+1][1] <- dp[i][j][k][1] (k+1 <= n2)
// dp[i][j+1][1][1]   <- dp[i][j][k][0]
void solve() {
	int n1, n2, k1, k2;
	std :: cin >> n1 >> n2 >> k1 >> k2;
	dp[1][0][1][0] = dp[0][1][1][1] = 1;
		for(int i = 0; i <= n1; ++ i)
			for(int j = 0; j <= n2; ++ j) {
				if(i == 0 && j == 0) continue;
				if(i > 0) {
					for(int k = 2; k <= k1; ++ k)
						dp[i][j][k][0] = (dp[i][j][k][0] + dp[i-1][j][k-1][0]) % Mod;
					for(int k = 1; k <= k2; ++ k)
						dp[i][j][1][0] = (dp[i][j][1][0] + dp[i-1][j][k][1]) % Mod;
				}
				if(j > 0) {
					for(int k = 2; k <= k2; ++ k)
						dp[i][j][k][1] = (dp[i][j][k][1] + dp[i][j-1][k-1][1]) % Mod;
					for(int k = 1; k <= k1; ++ k)
						dp[i][j][1][1] = (dp[i][j][1][1] + dp[i][j-1][k][0]) % Mod;
				}
			}
	i64 ans = 0;
	for(int i = 1; i <= k1; ++ i)
		ans = (ans + dp[n1][n2][i][0]) % Mod;
	for(int i = 1; i <= k2; ++ i)
		ans = (ans + dp[n1][n2][i][1]) % Mod;
	std :: cout << ans;
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