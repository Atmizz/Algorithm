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
int query(int l, int r) {
	std :: cout << "? " << l << ' ' << r << '\n';
	std :: cout.flush();
	int x;
	std :: cin >> x;
	return x;
}
void answer(int x) {
	std :: cout << "! " << x << '\n';
}
void solve() {
	int n, t, k;
	std :: cin >> n >> t >> k;
	int l = 1, r = n, ans;
	while(l <= r) {
		int mid = l + r >> 1;
		if(mid - query(1, mid) >= k) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	answer(ans);
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