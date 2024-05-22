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
const int N = 2e5 + 20;
int n, m;
std :: string s = "abc", str;
void solve() {
	std :: cin >> n >> m >> str;
	std :: vector dp(n + 1, std :: vector <int> (6));
	int now = 0;
	do {
		for(int i = 0; i < n; ++ i)
			dp[i+1][now] = dp[i][now] + (str[i] != s[i%3]);
		now ++;
	} while(std :: next_permutation(s.begin(), s.end()));
	while(m --) {
		int l, r; std :: cin >> l >> r;
		int ans = INF;
		for(int i = 0; i < 6; ++ i)
			ans = std :: min(ans, dp[r][i] - dp[l-1][i]);
		std :: cout << ans << '\n';
	}
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