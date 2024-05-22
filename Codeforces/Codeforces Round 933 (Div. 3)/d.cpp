#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1010;
int dp[N][N], n, m, x, a[N];
char ch[N];
int calc(int x, int y) {
	// deb(x);
	// deb(y);
	x = (x + n + y);
	x %= n;
	return x == 0 ? n : x;
}
void solve() {
	std :: cin >> n >> m >> x;
	for(int i = 0; i <= n; ++ i) {
		for(int j = 0; j <= m; ++ j) {
			dp[i][j] = -1;
		}
	}
	for(int i = 1; i <= m; ++ i) {
		std :: cin >> a[i] >> ch[i];
	}
	dp[x][0] = 0;
	for(int j = 1; j <= m; ++ j) {
		for(int i = 1; i <= n; ++ i) {
			if(dp[i][j-1] == -1) {
				continue;
			}
			if(ch[j] != '1') {
				dp[calc(i, a[j])][j] = 1;
			}
			if(ch[j] != '0') {
				dp[calc(i, -a[j])][j] = 1;
			}
		}
	}
	std :: set <int> ans;
	for(int i = 1; i <= n; ++ i) {
		if(dp[i][m] == 1) {
			ans.insert(i);
		}
	}
	std :: cout << ans.size() << '\n';
	for(auto x : ans) {
		std :: cout << x << ' ';
	}
	std :: cout << '\n';
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