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
const int N = 110;
int n, m, l, q, a[N], b[N], c[N];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	std :: cin >> m;
	for(int i = 1; i <= m; ++ i) {
		std :: cin >> b[i];
	}
	std :: map <int, bool> s;
	std :: cin >> l;
	for(int i = 1; i <= l; ++ i) {
		std :: cin >> c[i];
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			for(int k = 1; k <= l; ++ k) {
				s[a[i]+b[j]+c[k]] = 1;
			}
		}
	}
	std :: cin >> q;
	for(int i = 1; i <= q; ++ i) {
		int x;
		std :: cin >> x;
		std :: cout << (s[x] ? "Yes\n" : "No\n");
	}
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