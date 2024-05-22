#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const i64 INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
i64 dp[N][2];
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> c(n);
	for(int i = 0; i < n; ++ i) std :: cin >> c[i];
	std :: vector <std :: string> s(n), t(n);
	for(int i = 0; i < n; ++ i) std :: cin >> s[i];
	for(int i = 0; i < n; ++ i) {
		t[i] = s[i];
		std :: reverse(t[i].begin(), t[i].end());
		// if(i > 0 && s[i] < s[i-1] && s[i] < t[i-1] && t[i] < s[i-1] && t[i] < t[i-1]) {
		// 	std :: cout << -1 << endl;
		// 	return ;
		// }
	}
	dp[0][0] = 0; dp[0][1] = c[0];
	for(int i = 1; i < n; ++ i) {
		dp[i][0] = INF; dp[i][1] = INF;
		if(s[i] >= s[i-1]) dp[i][0] = std :: min(dp[i][0], dp[i-1][0]);
		if(s[i] >= t[i-1]) dp[i][0] = std :: min(dp[i][0], dp[i-1][1]);
		if(t[i] >= s[i-1]) dp[i][1] = std :: min(dp[i-1][0], dp[i][1]);
		if(t[i] >= t[i-1]) dp[i][1] = std :: min(dp[i-1][1], dp[i][1]);
		dp[i][1] += c[i];
	}
	if(std :: min(dp[n-1][0], dp[n-1][1]) == INF) puts("-1");
	else std :: cout << std :: min(dp[n-1][0], dp[n-1][1]);
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