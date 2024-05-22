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
const int N = 2023;
int n, h, l, r, dp[N][N];
void solve() {
	std :: cin >> n >> h >> l >> r;
	std :: vector <int> a(n);
	memset(dp, -0x3f, sizeof dp); dp[0][0] = 0;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i)
		for(int j = 0; j < h; ++ j)
			dp[i][j] = std :: max(dp[i-1][(j-a[i]+h)%h], dp[i-1][(j-a[i]+1+h)%h]) + (l <= j && j <= r);
	int ans = 0;
	for(int i = 0; i < h; ++ i)
		ans = std :: max(ans, dp[n][i]);
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