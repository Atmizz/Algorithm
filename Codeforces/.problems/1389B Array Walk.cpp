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
const int N = 1e5 + 20;
void solve() {
	int n, k, z, ans = 0;
	std :: cin >> n >> k >> z;
	std :: vector <int> a(n);
	std :: vector <std :: vector <std :: vector <i64> > > dp(k+2, std :: vector <std :: vector<i64> > (z+2, std :: vector <i64> (3)));
	for(int i = 0; i < n; ++ i) std :: cin >> a[i];
	dp[1][0][0] = a[0] + a[1];
	for(int i = 1; i <= k; ++ i)
		for(int j = 0; j <= z; ++ j)
			for(int h = 0; h <= 1; ++ h)
				if(dp[i][j][h]) {
					if(h == 0) {
						dp[i+1][j][0] = std :: max(dp[i+1][j][0], dp[i][j][0] + a[i-2*j+1]);
						if(j < z) dp[i+1][j+1][1] = std :: max(dp[i+1][j+1][1], dp[i][j][0] + a[i-2*j-1]);
					} else {
						dp[i+1][j][0] = std :: max(dp[i+1][j][0], dp[i][j][1] + a[i-2*j+1]);
					}
				}
	for(int i = 0; i <= z; ++ i)
		for(int j = 0; j <= 1; ++ j)
		ans = std :: max((i64)ans, dp[k][i][j]);
	std :: cout << ans << endl;
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