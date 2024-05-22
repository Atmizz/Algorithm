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
	int a, b, c;
	std :: cin >> a >> b >> c;
	if(a != c - 1) {
		std :: cout << -1 << '\n';
		return ;
	}
	if(a == 0) {
		std :: cout << b << '\n';
		return ;
	}
	int h = std :: log2(a);
	// h -> the height of the tree
	int hNum = (1 << h + 1) - 1;
	if(hNum != a) {
		h --;
	}
	// hNum -> the total number of the vertice having 2 sons in the full binary tree.
	int ans;
	// deb(hNum)
	if(a == hNum) {
		// full binary tree -> h + b / (1 << h) + (b % (1 << h) > 0) + 1
		ans = h + b / (1 << h + 1) + (b % (1 << h + 1) > 0) + 1;
	} else {
		int res = (1 << h + 2) - a - 1;
		// deb(h);
		// deb(res);
		if(b <= res) {
			ans = h + 2;
		} else {
			// bonus = bonus * 2 + res * 2;
			b -= res;
			res += (a - (1 << h + 1) + 1) * 2;
			ans = h + 2 + (b / res) + (b % res > 0);
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