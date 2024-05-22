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
const int N = 1e6;
int getnumber(int a, int b) {
	return rand() % (b - a + 1) + a;
}
void solve() {
	srand(time(0));
	int n = 100000, m = 300000;
	std :: cout << n << ' ' << m << '\n';
	int i = 1;
	for(; i < n; ++ i) {
		std :: cout << i << ' ' << i + 1 << ' ' << getnumber(2, 1000) << '\n';
	} i --;
	for(; i <= m; ++ i) {
		int u = getnumber(1, n), v = getnumber(1, n), w = getnumber(2, 1000);
		if(u == v) {
			i --;
			continue;
		}
		std :: cout << u << ' ' << v << ' ' << w << '\n';
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	freopen("10.in", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}
