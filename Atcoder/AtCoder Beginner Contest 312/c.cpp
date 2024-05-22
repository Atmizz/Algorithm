#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

void solve() {
	int n, m;
	std :: cin >> n >> m;

	std :: vector <int> a(n), b(m);
	for(int i = 0; i < n; ++ i) std :: cin >> a[i];
	for(int i = 0; i < m; ++ i) std :: cin >> b[i];

	std :: sort(a.begin(), a.end());
	std :: sort(b.begin(), b.end());

	auto check = [&] (int x) -> bool {
		int pos1 = std :: upper_bound(a.begin(), a.end(), x) - a.begin();
		int pos2 = std :: lower_bound(b.begin(), b.end(), x) - b.begin();
		return pos1 >= (m - pos2);
	};
	int l = 0, r = 1e9 + 1; int ans;
	while(l <= r) {
		int mid = (l + r ) >> 1;
		if(check(mid)) r = mid - 1,ans=mid;
		else l = mid + 1;
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
	// std :: cin >> T; 
	while(T --) solve();
	return 0;
}