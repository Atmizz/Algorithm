// LUOGU_RID: 122071375
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
	long double a, b, c, res = INF;
	i64 ans = INF;
	std :: cin >> a >> b >> c;
	i64 res1 = c * 2.00 / (a + b);
	long double temp;
	if(res1 == 0) {
		ans = 2;
		temp = c - (a + b) / 2.0;
		res = std :: fabs(temp);
	} else {
		temp = c - ((a + b) * res1) / 2.0 / res1;
		res = std :: fabs(temp);
		ans = res1 << 1;
	}
	temp = c - (a + b) * (res1 + 1);
	if(res > std :: fabs(temp)) {
		res = std :: fabs(temp);
		ans = (res1 + 1) << 1;
	}
	if(a + b == c * 2) {
		std :: cout << ans << endl;
		return ;
	}
	if((b - c) / (a + b - c * 2) > 0) {
		i64 res2 = (b - c) / (a + b - c * 2);
		temp = c - (a * res2 + b * (res2 - 1)) / (res2 * 2 - 1);
		if(temp < 0) temp = -temp;
		if(res > temp) {
			res = temp;
			ans = res2 * 2 - 1;
		}
		temp = c - (a * (res2 + 1) + b * res2) / (res2 * 2 + 1);
		if(temp < 0) temp = -temp;
		if(res > temp) {
			res = temp;
			ans = res2 * 2 + 1;
		}
	}
	std :: cout << ans << endl;
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
// 249,984,250,230
// 499,998.00000200008400352814818222
// 249,985,250,207
// 499,997.99999799992399711189025183
// 0.00000200007600288810974817
// 0.00000200008400352814818222