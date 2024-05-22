#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << '\n';
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
template <class T>
T abs(T a) {
	return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 5050;
int a[N], n;
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	auto dfs = [&](auto dfs, int l, int r) -> int {
		if(l > r) {
			return 0;
		}
		if(l == r) {
			return a[l] > 0;
		}
		int minn = INF, pos;
		for(int i = l; i <= r; ++ i) {
			if(minn > a[i]) {
				minn = a[i];
				pos = i;
			}
		}
		int ans = minn;
		for(int i = l; i <= r; ++ i) {
			a[i] -= minn;
		}
		ans += dfs(dfs, l, pos - 1);
		ans += dfs(dfs, pos + 1, r);
		return min(r - l + 1, ans);
	};
	std :: cout << dfs(dfs, 1, n);
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	//std :: cin >> _; 
	while(_ --) solve();
	return 0;
}