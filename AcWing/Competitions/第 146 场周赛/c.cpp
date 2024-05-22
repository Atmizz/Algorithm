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
int n, a[N];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	int l = 1, r = n, ans = 0, now = 0;
	while(1) {
		if(l > r || (a[l] <= now && a[r] <= now)) {
			break;
		}
		// deb(l);
		// deb(r);
		// deb(now);
		if(a[l] == a[r]) {
			int cnt1 = 0, cnt2 = 0, res = now;
			for(int i = l; i <= r; ++ i) {
				if(a[i] > res) {
					cnt1 ++;
					res = a[i];
				} else {
					break;
				}
			}
			res = now;
			for(int i = r; i >= l; -- i) {
				if(a[i] > res) {
					res = a[i];
					cnt2 ++;
				} else {
					break;
				}
			}
			std :: cout << std :: max(ans + cnt1, ans + cnt2);
			return ;
		} else if((a[l] < a[r] && a[l] > now) || a[r] <= now) {
			ans ++;
			now = a[l];
			l ++;
		} else {
			ans ++;
			now = a[r];
			r --;
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