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
int n, dp[N][N], a[N];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	memset(dp, 88, sizeof dp);
	for(int i = 1; i <= n; ++ i)
		dp[i][i] = 1;
	for(int i = 1; i < n; ++ i)
		dp[i][i+1] = dp[i][i] + (a[i] != a[i+1]);
	for(int len = 3; len <= n; ++ len)
		for(int i = 1; i <= n; ++ i) {
			int j = i + len - 1;
			if(j > n) break;
			if(a[i] == a[j])
				dp[i][j] = std :: min(dp[i][j], dp[i+1][j-1]);
			for(int k = i; k < j; ++ k)
				dp[i][j] = std :: min(dp[i][j], dp[i][k]+dp[k+1][j]);
		}
	std :: cout << dp[1][n];
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