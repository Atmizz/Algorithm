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
const int N = 200;
std :: mt19937 rd(114514);
int dp[20][N], a[20];
// dp[i][j] 表示第 i 位时和为 j 且后面没有限制的和
int dfs(int pos, int sum, bool limit) {
	if(pos == 0) {
		return sum;
	}
	if(!limit && dp[pos][sum] != -1) {
		return dp[pos][sum];
	}
	int lim = limit ? a[pos] : 9;
	int res = 0;
	for(int i = 0; i <= lim; ++ i) {
		res += dfs(pos-1, sum+i, limit && i == lim);
		res %= Mod;
	}
	dp[pos][sum] = res;
	return res;
}
int calc(i64 x) {
	int num = 0;
	memset(dp, -1, sizeof dp);
	while(x) {
		a[++num] = x % 10;
		x /= 10;
	}
	return dfs(num, 0, true);
}
void solve() {
	i64 l, r;
	std :: cin >> l >> r;
	std :: cout << (calc(r) - calc(l-1) + Mod) % Mod << '\n';
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