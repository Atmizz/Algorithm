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

void solve() {
	int n, k;
	std :: cin >> n >> k;
	std :: vector dp(n+1, std :: vector <int> (2));
	std :: vector <int> sum(n+1);
	std :: string str;
	std :: cin >> str;
	str = "*" + str;
	for(int i = 1; i <= n; ++ i)
		sum[i] = sum[i-1] + (str[i] == '1');
	for(int i = 1; i <= n; ++ i) {
		int x = std :: max(0, i - k);
		dp[i][0] = std :: min(dp[i-1][0], dp[i-1][1]) + (str[i] == '1');
		dp[i][1] = std :: min(sum[i-1], dp[x][1] + sum[i-1] - sum[x]) + (str[i] == '0');
	}
	std :: cout << std :: min(dp[n][0], dp[n][1]) << endl;
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