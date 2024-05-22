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
	int n, m = 0;
	std :: cin >> n;
	std :: vector <i64> cnt(N), dp(N);
	for(int i = 1; i <= n; ++ i) {
		int x; std :: cin >> x;
		cnt[x] ++;
		m = std :: max(m, x);
	}
	dp[1] = cnt[1];
	for(int i = 2; i <= m; ++ i)
		dp[i] = std :: max(dp[i-1], dp[i-2] + cnt[i] * i);
	std :: cout << dp[m] << endl;
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