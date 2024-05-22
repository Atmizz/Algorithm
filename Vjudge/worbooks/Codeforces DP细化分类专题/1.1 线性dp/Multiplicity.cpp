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
const int N = 1e6 + 20;
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <i64> dp(N);
	for(int j = 0; j < n; ++ j) {
		int x; std :: cin >> x;
		std :: vector <int> res;
		for(int i = 1; i <= sqrt(x); ++ i)
			if(x % i == 0) {
				// if(i > n) break;
				res.push_back(i);
				if(i * i != x) res.push_back(x / i);
			}
		std :: sort(res.begin(), res.end());
		for(int i = res.size() - 1; i >= 0; -- i)
			dp[res[i]] = (dp[res[i]] + dp[res[i]-1]) % Mod;
		dp[1] ++;
		// deb(dp[1]); deb(dp[2]); deb(dp[3]); deb(dp[4]);
	}
	i64 ans = 0;
	for(int i = 1; i <= n; ++ i)
		ans = (ans + dp[i]) % Mod;
	std :: cout << ans << endl;
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