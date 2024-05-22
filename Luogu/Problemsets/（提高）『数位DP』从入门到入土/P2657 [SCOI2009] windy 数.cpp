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
const int N = 11;
int dp[N][N], a[N];
int dfs(int pos, int dig, bool limit, bool lead) {
	if(pos == 0) {
		return !lead;
	}

	if(!limit && !lead && dp[pos][dig] != -1) {
		return dp[pos][dig];
	}

	int lim = limit ? a[pos] : 9;
	int res = 0;
	for(int i = 0; i <= lim; ++ i) {
		if(std :: abs(i - dig) < 2) {
			continue;
		}
		if(lead && i == 0) {
			res += dfs(pos-1, -2, limit && i == lim, lead);
		} else {
			res += dfs(pos-1, i, limit && i == lim, lead && i == 0);
		}
	}
	if(!limit && !lead) {
		dp[pos][dig] = res;
	}
	return res;
}
int calc(int x) {
	memset(dp, -1, sizeof dp);
	int num = 0;
	while(x) {
		a[++num] = x % 10;
		x /= 10;
	}
	return dfs(num, -2, true, true);
}
void solve() {
	int l, r;
	std :: cin >> l >> r;
	std :: cout << calc(r) - calc(l - 1);
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