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
// const int N = ;
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <PII> p;
	for(auto &[x, y] : p) {
		std :: cin >> x >> y;
	}
	auto gcd = [&](auto gcd, i64 a, i64 b) -> i64 {
		return b ? gcd(gcd, b, a % b) : a;
	};
	i64 ans = 0;
	for(int i = 0; i < n; ++ i) {
		auto &[x_1, y_1] = p[i];
		std :: map <i64, std :: map <i64, std :: map <i64, int> > > mp;
		for(int j = i + 1; j < n; ++ j) {
			auto &[x_2, y_2] = p[j];
			i64 d = 1LL * (x_2 - x_1) * (x_2 - x_1) + 1LL * (y_2 - y_1) * (y_2 - y_1);
			i64 G = gcd(gcd, x_2 - x_1, y_2 - y_1);
			mp[d][(y_2-y_1)/G][(x_2-x_1)/G] ++;
		}
		for(auto &[d, pm] : mp) {
			int tot = mp.count(d);
			if(tot < 2) {
				continue ;
			}
			for(auto &[Y, mm] : pm) {
				for(auto &[X, val] : mm) {
					if(tot - val < 2) {
						continue ;
					}
					ans += 1LL * (tot - val) * (tot - val) / 2;
				}
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
	int _ = 1;
	//std :: cin >> _; 
	while(_ --) solve();
	return 0;
}