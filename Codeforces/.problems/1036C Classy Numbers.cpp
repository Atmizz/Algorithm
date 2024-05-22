#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << endl;
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
template <class T>
T abs(T a) {
	return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
std :: vector dp(20, std :: vector <i64> (4));
int a[20];
i64 dfs(int pos, int dig, bool limit, bool lead) {
	if(dig > 3) {
		return 0;
	}

	if(pos == 0) {
		return !lead;
	}

	if(!limit && !lead && dp[pos][dig] != -1) {
		return dp[pos][dig];
	}

	int lim = limit ? a[pos] : 9;
	i64 res = 0;
	for(int i = 0; i <= lim; ++ i) {
		if(lead && i == 0) {
			res += dfs(pos-1, dig, limit && i == lim, lead);
		} else {
			res += dfs(pos-1, dig+(i!=0), limit && i == lim, lead && i == 0);
		}
	}
	if(!limit && !lead) {
		dp[pos][dig] = res;
	}
	return res;
}
i64 calc(i64 x) {
	for(int i = 0; i < sz(dp); ++ i) {
		for(int j = 0; j < sz(dp[i]); ++ j) {
			dp[i][j] = -1;
		}
	}
	int cnt = 0;
	while(x) {
		a[++cnt] = x % 10;
		x /= 10;
	}
	return dfs(cnt, 0, true, true);
}
void solve() {
	i64 l, r;
	std :: cin >> l >> r;
	std :: cout << calc(r) - calc(l-1) << nl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}