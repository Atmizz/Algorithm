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
	int n, k, ans = 0;
	std :: cin >> n >> k;
	std :: vector <int> a(n+1), b(n+1); a[0] = INF;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i], ans = std :: max(ans, a[i]);
	for(int i = n; i > 1; -- i) {
		int res = 0, t = k;
		if(a[i] >= a[i-1]) b[i] = a[i];
		else {
			b[i] = a[i-1]; t -= a[i-1] - a[i];
			if(t <= 0) continue;
		}
		for(int h = i - 1; h >= 1; -- h) {
			if(b[h+1] < a[h]) break;
			int temp = a[h];
			b[h] = std :: min(b[h+1] + 1, a[h] + t);
			// deb(h); deb(b[h]);
			t -= b[h] - temp;
			res = std :: max(res, b[h]);
			if(t == 0) break;
		}
		ans = std :: max(ans, res);
	}
	std :: cout << ans << endl;
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
// 6 5 4 1 5