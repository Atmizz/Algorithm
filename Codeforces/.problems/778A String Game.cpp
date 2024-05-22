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
const int N = 2e5 + 20;
int n, m, p[N], q[N];
std :: string s, t;
void solve() {
	std :: cin >> s >> t;
	n = (int) s.size();
	m = (int) t.size();
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> p[i];
		q[p[i]] = i;
	}
	// for(int i = 1; i <= n; ++ i) {
	// 	std :: cout << i << ' ' << q[i] << '\n';
	// }
	s = "0" + s;
	t = "0" + t;
	auto check = [](int x) {
		std :: string res = "0";
		for(int i = 1; i <= n; ++ i) {
			if(q[i] <= x) {
				continue ;
			}
			res += s[i];
		}
		// deb(x);
		// deb(res);
		int pos = 1;
		for(int i = 1; i <= (int) res.size(); ++ i) {
			if(pos <= m && t[pos] == res[i]) {
				pos ++;
			}
		}
		return pos > m;
	};
	int l = 0, r = n, ans;
	while(l <= r) {
		int mid = l + r >> 1;
		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
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