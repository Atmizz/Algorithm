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
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 5050;
int dp[N>>1][N], n, a[N], b[N], cnt;
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		if(a[i] & 1) {
			b[++cnt] = i;
		}
	}
	memset(dp, INF, sizeof dp);
	for(int i = 0; i <= n; ++ i) {
		dp[0][i] = 0;
	}
	for(int i = 1; i <= cnt; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			// if(a[j]) = 0 : only not sit down
			// dp[i][j] <- dp[i][j-1]
			//==========================
			// if a[j] = 1 : sit down or not sit down
			// dp[i][j] <- min(dp[i][j-1], dp[i-1][j-1] + abs(b[i] - j))
			if(a[j] & 1) {
				dp[i][j] = dp[i][j-1];
			} else {
				dp[i][j] = std :: min(dp[i][j-1], 
					dp[i-1][j-1] + std :: abs(b[i] - j));
			}
		}
	}
	std :: cout << dp[cnt][n];
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