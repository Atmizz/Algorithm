#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define int long long
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 2147483647;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

void solve() {
	int n, k;
	std :: cin >> n >> k;
	std :: vector <pi> a(n);
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i].first, a[i].second = i + 1 ;
	std :: sort(a.begin(), a.end());
	int minn = INF, pos1, pos2, x1, x2;
	for(int i = 1; i < n; ++ i)
		if(minn > (a[i].first ^ a[i-1].first)) {
			minn = a[i].first ^ a[i-1].first;
			pos1 = a[i-1].second, pos2 = a[i].second;
			x1 = a[i-1].first, x2 = a[i].first;
		}
	i64 ans = 0;
	for(i64 i = 0; i < k; ++ i) {
		if(((x1 >> i) & 1) == ((x2 >> i) & 1)) ans = (i64) ans + (i64)((((x1 >> i) & 1) ^ 1) << i);
	}
	std :: cout << pos1 << ' ' << pos2 << ' ' << ans << endl;
}

signed main() {
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