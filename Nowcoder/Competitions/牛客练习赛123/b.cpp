#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<i64, int>
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
	std :: vector <PII> a(n);
	std :: vector <int> ans(n);
	for(int i = 0; i < n; ++ i) {
		auto &[x, y] = a[i];
		std :: cin >> x;
		y = i;
	}
	std :: sort(a.begin(), a.end(), [&](PII a, PII b) {
		return a.first < b.first;
	});
	if(n == 2 && a[0].first == a[1].first) {
		std :: cout << 0 << ' ' << 0 << '\n';
		return ;
	}
	i64 sum = 0;
	for(int i = 0; i < n - 1; ++ i) {
		auto [x, y] = a[i];
		sum += x;
	}
	// deb(sum);
	if(sum <= a[n-1].first) {
		for(int i = 0; i < n - 1; ++ i) {
			auto [x, y] = a[i];
			ans[y] = 0;
		}
		ans[a[n-1].second] = 1;
	} else {
		for(int i = 0; i < n; ++ i) {
			ans[i] = 1;
		}
		sum += a[n-1].first;
		for(int i = 0; i < n; ++ i) {
			if(a[i].first == 1 && (sum - a[i].first) & 1) {
				ans[a[i].second] = 0;
			}
		}
	}
	for(int i = 0; i < n; ++ i) {
		std :: cout << ans[i] << ' ';
	}
	std :: cout << '\n';
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