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
// const int N = ;
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <i64> a(n+1), b(n+1);
	std :: vector dp(n+1, std :: vector <i64> (3, LLINF));
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i] >> b[i];
	}
	dp[0][0] = 0;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 0; j < 3; ++ j) {
			for(int k = 0; k < 3; ++ k) {
				if(a[i-1] + j != a[i] + k) {
					dp[i][k] = std :: min(dp[i][k], dp[i-1][j] + k * b[i]);
				}
			}
		}
	}
	i64 ans = LLINF;
	for(int i = 0; i < 3; ++ i) {
		ans = std :: min(ans, dp[n][i]);
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