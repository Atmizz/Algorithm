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
const int N = 2e5 + 20;
void solve() {
	int n, k;
	std :: cin >> n >> k;
	std :: vector <PII> p(n);
	for(auto &[x, y] : p) {
		std :: cin >> x;
	}
	for(auto &[x, y] : p) {
		std :: cin >> y;
	}
	if(n == 1) {
		std :: cout << 1 << nl;
		return ;
	}
	std :: sort(p.begin(), p.end());
	std :: map <int, int> sum;
	int lst = 0;
	for(int i = 0; i < n; ++ i) {
		auto &[x, y] = p[i];
		if(sum.count(x)) {
			sum[x] ++;
		} else {
			sum[x] = lst + 1;
		}
		lst = sum[x];
	}
	std :: vector <int> maxPoint(n), maxx(n);
	for(int i = 0; i < n; ++ i) {
		auto &[x, y] = p[i];
		int pos = std :: lower_bound(p.begin(), p.end(), mk(x - k, 0)) - p.begin();
		maxPoint[i] = i - pos + 1;
	}
	int ans = 0;
	maxx[0] = maxPoint[0];
	for(int i = 1; i < n; ++ i) {
		auto &[x, y] = p[i];
		maxx[i] = max(maxPoint[i], maxx[i-1]);
		ans = max(ans, maxPoint[i]);
		int j = std :: lower_bound(p.begin(), p.end(), mk(x - k, 0)) - p.begin();
		if(j > 0) {
			ans = max(ans, maxPoint[i] + maxx[j-1]);
		}
		// if(i != j) {

		// }
	}
	std :: cout << ans << nl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}