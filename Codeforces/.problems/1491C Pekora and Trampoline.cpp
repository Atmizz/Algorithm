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
const int N = 5050;
int n, a[N];
i64 c[N<<1];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		c[i] = 0;
	}
	c[0] = 0;
	i64 ans = 0;
	for(int i = 1; i <= n; ++ i) {
		c[i] += c[i-1];
		// if(a[i] <= 1) {
		// 	continue;
		// }
		int res = 0;
		if(c[i] >= a[i] - 1) {
			res = c[i] - (a[i] - 1);
		} else {
			ans += (a[i] - c[i] - 1);
		}
		if(a[i] > n) {
			a[i] = n;
		}
		// deb(i);
		// deb(c[i])
		// deb(a[i]);
		// deb(res);
		// deb(ans);
		// std :: cout << i + 2 << ' ' << i + a[i] << '\n';
		c[i+2] ++;
		c[i+a[i]+1] --; // <-> a[i] - 1
		c[i+1] += res;
		c[i+2] -= res;
	}
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