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
const int N = 3e5 + 20;
i64 n, c, a[N];
void solve() {
	std :: cin >> n >> c;
	i64 ans = 1LL * (c + 2) * (c + 1) / 2;
	int odd = 0, even = 0;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		odd += (a[i] & 1);
		even += (!(a[i] & 1));
		if(a[i] & 1) {
			ans += odd;
		} else {
			ans += even;
		}
	}
	for(int i = 1; i <= n; ++ i) {
		ans -= (a[i] / 2 + 1);
	}
	// deb(ans);
	for(int i = 1; i <= n; ++ i) {
		i64 res = c - a[i];
		ans -= (res + 1);
	}
	// deb(ans);
	// deb(odd);
	// deb(even);
	std :: cout << ans << '\n';
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