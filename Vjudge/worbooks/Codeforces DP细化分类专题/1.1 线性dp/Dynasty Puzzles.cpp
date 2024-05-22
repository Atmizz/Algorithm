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

// dp[i][j] 表示的是i开头，j结尾的王朝的最大长度。
int dp[26][26];
void solve() {
	int n;
	std :: cin >> n;
	for(int i = 0; i < n; ++ i) {
		std :: string a;
		std :: cin >> a;
		int l = a[0] - 'a', r = a[a.size() - 1] - 'a';
		for(int j = 0; j < 26; ++ j)
			if(dp[j][l])
				dp[j][r] = std :: max(dp[j][l] + (int)a.size(), dp[j][r]);
		dp[l][r] = std :: max(dp[l][r], (int)a.size());
	}
	int ans = 0;
	for(int i = 0; i < 26; ++ i)
		ans = std :: max(ans, dp[i][i]);
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