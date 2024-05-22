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
// const int N = ;
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> k(n+1), h(n+1);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> k[i];
	}
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> h[i];
	}
	i64 ans = 0, lst = k[n], lstVal = h[n];
	for(int i = n - 1; i >= 0; -- i) {
		if(k[i+1] - k[i] >= h[i+1]) {
			// deb(i);
			// deb(lstVal)
			ans += 1LL * (lstVal + 1) * lstVal / 2;
			lstVal = h[i];
			lst = k[i];
		} else {
			if(lstVal > h[i] + (lst - k[i])) {
				h[i] = lstVal - (lst - k[i]);
			} else {
				lstVal = h[i] + (lst - k[i]);
			}
			// lstVal = std :: max(h[i] + (lst - k[i]), lstVal);
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