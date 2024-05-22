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
const int N = 1e5;
int n;
int get(int x) {
	int y = 0;
	for(int i = 5; i >= 0; -- i) {
		y = y * 10 + (x >> i & 1);
	}
	return y;
}
void solve() {
	int x;
	std :: cin >> x;
	for(int _ = (1 << 5) - 1; _ >= 2; -- _) {
		int r = get(_);
		while(x % r == 0) {
			x /= r;
		}
		if(x == 1) {
			break;
		}
	}
	// deb(x);
	std :: cout << (x == 1 ? "YES\n" : "NO\n");
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
