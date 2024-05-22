#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
#define int long long
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
int n, d;
i64 m;
void solve() {
	std :: cin >> n >> d >> m;
	std :: vector <i64> a(n), low, high;
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i];
	for(int i = 0; i < n; ++ i)
		if(a[i] > m) high.push_back(a[i]);
		else low.push_back(a[i]);
	std :: sort(low.rbegin(), low.rend());
	std :: sort(high.rbegin(), high.rend());

	int l = low.size(), r = high.size();

	std :: vector <i64> sa(l+1), sb(r+1);
	for(int i = 1; i <= l; ++ i)
		sa[i] = sa[i-1] + low[i-1];
	for(int i = 1; i <= r; ++ i)
		sb[i] = sb[i-1] + high[i-1];

	i64 ans = sa[l];

	for(int i = 1; i <= r; ++ i) {
		int res = (i - 1) * (d + 1) + 1;

		if(res > n) break;

		res = n - res;
		ans = std :: max(ans, sb[i] + sa[std :: min(res, l)]);
	}

	std :: cout << ans;
}
signed main() {
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