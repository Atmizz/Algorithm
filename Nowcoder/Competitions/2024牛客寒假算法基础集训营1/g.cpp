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
const i64 Range = 1e18;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
	int n; i64 m;
	std :: cin >> n >> m;
	std :: vector <PII> a(n);
	for(auto &[x, y] : a) {
		std :: cin >> x >> y;
	}
	std :: sort(a.begin(), a.end());
	i64 sum = 0, ans = m;
	for(int i = 0; i < n; ++ i) {
		int x = a[i].first, y = a[i].second;
		sum += y;
		if(1LL * x - sum <= m) {
			ans = std :: max(ans, m + sum);
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