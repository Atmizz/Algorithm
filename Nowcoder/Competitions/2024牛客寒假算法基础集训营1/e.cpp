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
	int n, m, ans;
	std :: cin >> n >> m;
	ans = n;
	std :: vector <int> a(n);
	for(auto &x : a) {
		std :: cin >> x;
	}
	std :: vector <PII> b(m);
	for(auto &[x, y] : b) {
		std :: cin >> x >> y;
		x --; y --;
	}
	int r = 1;
	for(int i = 1; i <= m; ++ i) {
		r *= 3;
	}
	for(int i = 0; i <= r; ++ i) {
		std :: vector <int> c(n);
		for(int j = 0; j < n; ++ j) {
			c[j] = a[j];
		}
		int j = i;
		for(auto [x, y] : b) {
			if(j % 3 == 0) {
				c[x] += 3;
			} else if(j % 3 == 1) {
				c[y] += 3;
			} else {
				c[x] += 1;
				c[y] += 1;
			}
			j /= 3;
		}
		int cnt = 1;
		for(int i = 0; i < n; ++ i) {
			if(c[i] > c[0]) {
				cnt ++;
			}
		}
		ans = std :: min(ans, cnt);
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