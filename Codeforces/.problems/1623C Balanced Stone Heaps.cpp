#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl '\n'
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
int h[N], n;
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> h[i];
	}

	auto check = [&](int x) -> bool{
		std :: vector <int> res(n + 1), temp(n + 1);
		for(int i = 1; i <= n; ++ i) {
			res[i] = h[i]; temp[i] = 0;
		}
		// std :: vector <int> dg;
		for(int i = n; i >= 3; -- i) {
			if(res[i] + temp[i] > x) {
				int d = std :: min(res[i], temp[i] + res[i] - x) / 3;
				res[i] -= d * 3;
				temp[i-1] += d;
				temp[i-2] += d * 2;
				// dg.push_back(d);
			}
		}
		// for(auto x : dg) {
		// 	std :: cout << x << ' ';
		// }
		// std :: cout << '\n';
		for(int i = 1; i <= n; ++ i) {
			if(temp[i] + res[i] < x) {
				// deb(x); deb(i);
				// deb(temp[i] + res[i]);
				return false;
			}
		}
		return true;
	};

	int l = 1, r = Range, ans;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
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