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
// const int N = ;
bool check(int x, int y) {
	if(x == 10000) return true;
	x = std :: abs(x);
	y = std :: abs(y);
	// deb(x); deb(y);
	if(x % 2 == 1 && y % 2 == 0) return true;
	if(x % 2 == 0 && y % 2 == 1) return true;
	return false;
}
void solve() {
	int n, ans = -INF; std :: cin >> n;
	std :: vector <int> dp(n + 1), a(n + 1);
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i], dp[i] = a[i];
	a[0] = 10000;
	for(int i = 1; i <= n; ++ i) {
		if(dp[i-1] >= 0 && check(a[i-1], a[i]))
			dp[i] = dp[i-1] + a[i];
		ans = std :: max(ans, dp[i]);
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