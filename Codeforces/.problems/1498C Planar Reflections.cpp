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
int dp[N][N][2], x, y;
int dfs(int n, int k, int d) {
	if(n == 0 || k == 1) return 1;
	if(dp[n][k][d] != -1) return dp[n][k][d];
	return (dp[n][k][d] = (dfs(n-1, k, d) % Mod + dfs(x-n, k-1, d^1) % Mod) % Mod);
}
void solve() {
	std :: cin >> x >> y;
	memset(dp, -1, sizeof dp);
	std :: cout << dfs(x, y, 1) % Mod << '\n';
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