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
const int N = 131075;
int a[N];
void solve() {
	int l, r, n, res = 0;
	std :: cin >> l >> r;
	n = r - l + 1;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	for(int i = 0; i < 17; ++ i) {
		int cnt0 = 0, cnt1 = 0;
		for(int j = 1; j <= n; ++ j) {
			cnt0 += (!((a[j] >> i) & 1));
			cnt1 += ((a[j] >> i) & 1);
		}
		if(cnt1 > cnt0) {
			res += (1 << i);
		}
	}
	std :: cout << res << '\n';
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