#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 32;
int dp[N][N][N], a[N];
int dfs(int pos, int sum0, int sum1, bool limit, bool lead) {
	if(pos == 0) {
		if(lead) {
			return 0;
		}
		return sum0 >= sum1;
	}
	if(!limit && !lead && dp[pos][sum0][sum1] != -1) {
		return dp[pos][sum0][sum1];
	}
	int lim = limit ? a[pos] : 1;
	int res = 0;
	for(int i = 0; i <= lim; ++ i) {
		if(lead && i == 0) {
			res += dfs(pos-1, sum0, sum1, limit && i == lim, lead);
		} else {
			res += dfs(pos-1, sum0+(i==0), sum1+(i==1), limit && i == lim, false);
		}
	}
	dp[pos][sum0][sum1] = res;
	return res;
}
int calc(int x) {
	int num = 0;
	memset(dp, -1, sizeof dp);
	while(x) {
		a[++num] = x & 1;
		x >>= 1;
	}
	return dfs(num, 0, 0, true, true);
}
void solve() {
	int l, r;
	std :: cin >> l >> r;
	std :: cout << calc(r) - calc(l-1);
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