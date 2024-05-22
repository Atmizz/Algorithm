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
const int N = 1e7;
i64 ans[N];
void solve() {
	int n; std :: cin >> n;
	std :: cout << ans[n] << '\n';
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	ans[0] = 1;
	i64 add = 1, now = 2;
	for(int i = 1; i <= 9; ++ i)
		ans[i] = ans[i-1] + now, now += add;
	for(int i = 1; i <= N; ++ i) {
		if(i % 10 == 1 && i != 1) {
			// if(i <= 20) {
			// 	deb(i);
			// 	deb()
			// }
			add = ans[i-1], now = ans[i-1] * 2;
			for(int j = 0; j < 9; ++ j)
				ans[i+j] = ans[i+j-1] + now, now += add;
		}
		// std :: cout << i << ' ' << ans[i] << '\n';
		i64 res = i;
		while(res * 10 <= N) ans[res*10] = ans[res], res *= 10;
	}
	// for(int i = 1; i <= 100; ++ i)
	// 	std :: cout << i << ' ' << ans[i] << '\n';
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}