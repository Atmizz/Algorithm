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
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
	int n; std :: cin >> n;
	std :: vector <int> a(n + 1);
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];

	i64 ans = 0;
	for(int i = n - 1; i >= 1; -- i) {
		deb(a[i+1]); deb(ans);
		if(a[i] <= a[i+1]) continue;

		int maxx = a[i] / 2 + (a[i] & 1);
		if(maxx <= a[i+1]) {
			ans ++; a[i] /= 2;
			continue;
		}

		if(a[i] % a[i+1] == 0) {
			ans += a[i] / a[i+1] - 1;
			a[i] = a[i+1];
		}
		else {
			ans += a[i] / a[i+1];
			a[i] = (a[i+1] + (a[i] % a[i+1])) / 2;
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