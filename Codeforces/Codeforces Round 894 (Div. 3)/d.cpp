#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = unsigned long long;
const i64 INF = 1e10;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

void solve() {
	i64 n;
	std :: cin >> n;
	if(n == 1) {
		std :: cout << 2 << endl;
		return ;
	}
	i64 l = 1ll, r = INF, ans;
	while(l <= r) {
		i64 mid = (l + r) / 2ll;
		if(mid * (mid - 1ll) <= n * 2ll) ans = mid, l = mid + 1ll;
		else r = mid - 1ll;
	}
	// deb(ans);
	std :: cout << ans + (n - ans * (ans - 1ll) / 2ll) << endl;
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