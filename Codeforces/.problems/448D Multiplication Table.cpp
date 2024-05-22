#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

void solve() {
	i64 n, m, k;
	std :: cin >> n >> m >> k;
	auto check = [&] (i64 x) -> bool {
		i64 sum = 0;
		for(i64 i = 1; i <= n; ++ i)
			sum += std :: min(m, x / i);
		return sum >= k;
	};
	i64 l = 1, r = n * m, ans;
	while(l <= r) {
		i64 mid = (l + r) / 2;
		if(check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	std :: cout << ans;
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