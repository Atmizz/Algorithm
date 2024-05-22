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
// const int N = ;
void solve() {
	int n;
	std :: cin >> n;
	std :: set <PII> s;
	int cnt1 = 2, cnt2 = 2;
	for(int i = 1; i <= n; ++ i) {
		int r, c;
		std :: cin >> r >> c;
		r --;
		s.insert({r, c});
		if(c < 0) {
			cnt1 = std :: min(cnt1, 1);
		} else if(c > 0) {
			cnt2 = std :: min(cnt2, 1);
		} else {
			cnt1 = std :: min(cnt1, 1);
			cnt2 = std :: min(cnt2, 1);
		}
	}
	for(auto [r, c] : s) {
		if(c < 0) {
			for(int j = -1; j <= 1; ++ j) {
				if(s.count({r^1, c+j})) {
					cnt1 = 0;
				}
			}
		} else if(c > 0) {
			for(int j = -1; j <= 1; ++ j) {
				if(s.count({r^1, c+j})) {
					cnt2 = 0;
				}
			}
		}
	}
	int ans = std :: min(cnt1 + cnt2, (int)(3 - s.count({1, 0}) - s.count({0, 1}) - s.count({0, -1})));
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