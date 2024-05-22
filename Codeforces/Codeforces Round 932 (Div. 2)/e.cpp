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
const int N = 2e5 + 20;
int n, q;
struct Grade {
	int minn, maxx;
}g[N];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> g[i].minn >> g[i].maxx;
	}
	std :: cin >> q;
	while(q --) {
		int l, r, ans = 0;
		std :: cin >> l >> r;
		for(int i = 0; i < 30; ++ i) {
			bool flag = 0;
			for(int j = l; j <= r; ++ j) {
				if(g[j].minn < (1 << i) && g[j].maxx >= (1 << i)) {
					flag = 1;
					break;
				}
				flag ^= (g[j].maxx >> i);
			}
			if(flag) {
				deb(i);
				ans += (1 << i);
			}
		}
		std :: cout << ans << ' ';
	}
	std :: cout << '\n';
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