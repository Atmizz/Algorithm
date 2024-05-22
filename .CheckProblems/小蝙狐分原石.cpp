#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 8010;
int dp[N], a, b, c, ans, n;
void solve() {
	std :: cin >> n >> a >> b >> c;
	std :: set <int> s;
	s.insert(a); s.insert(b); s.insert(c);
	for(int i = 0; i <= n; ++ i) {
		if(dp[i] == 0 && i != 0) continue;
		for(auto x : s)
			dp[i+x] = std :: max(dp[i+x], dp[i] + 1);
	}
	std :: cout << dp[n];
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