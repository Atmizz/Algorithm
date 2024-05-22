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
const int Mod = 1e9 + 7;
const int N = 5e3 + 20;
i64 dp[N][N], sum[N], a[N], ans;
int n, m, k;
void solve() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i)
		sum[i] = sum[i-1] + a[i];
	memset(dp, -1, sizeof dp);
	for(int i = 0; i <= n; ++ i) dp[i][0] = 0;
	for(int i = m; i <= n; ++ i)
		dp[i][1] = sum[i] - sum[i-m];
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= k; ++ j) {
			dp[i][j] = dp[i-1][j];
			if(i >= m && dp[i-m][j-1] > -1) dp[i][j] = std :: max(dp[i][j], dp[i-m][j-1] - sum[i-m] + sum[i]);
		}
	printf("%lld", dp[n][k]);
}

int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}