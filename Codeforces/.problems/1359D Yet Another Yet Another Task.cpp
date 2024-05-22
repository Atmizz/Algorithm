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
const int N = 1e5 + 20;
int a[N], n, s1[N], s2[N], ans;
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	for(int j = 1; j <= 30; ++ j) {
		int res = 0;
		for(int i = 1; i <= n; ++ i) {
			res += a[i];
			if(a[i] > j || res < 0) {
				res = 0;
			}
			s1[i] = res;
		}
		res = 0;
		for(int i = n; i >= 1; -- i) {
			res += a[i];
			if(a[i] > j || res < 0) {
				res = 0;
			}
			s2[i] = res;
		}
		for(int i = 1; i <= n; ++ i) {
			if(a[i] == j) {
				ans = std :: max(ans, s1[i-1] + s2[i+1]);
			}
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