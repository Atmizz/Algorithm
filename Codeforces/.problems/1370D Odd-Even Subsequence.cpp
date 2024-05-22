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
	int n, k;
	std :: cin >> n >> k;
	std :: vector <int> a(n+1);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	auto check = [=](int x) -> bool {
		int cnt = 0;
		for(int i = 1; i <= n; ++ i) {
			if(cnt & 1) {
				if(a[i] <= x) {
					cnt ++;
				}
			} else {
				cnt ++;
			}
		}
		if(cnt >= k) {
			return true;
		}
		cnt = 0;
		for(int i = 1; i <= n; ++ i) {
			if(!(cnt & 1)) {
				if(a[i] <= x) {
					cnt ++;
				}
			} else {
				cnt ++;
			}
		}
		return cnt >= k;
	};
	int l = 1, r = Range, ans;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			r = mid - 1;
			ans = mid;
		} else {
			l = mid + 1;
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