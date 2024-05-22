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
	int n, q;
	std :: cin >> n >> q;
	std :: vector <int> sum(n+1);
	std :: map <int, std :: vector <int> > mp;
	mp[0].pb(0);
	for(int i = 1; i <= n; ++ i) {
		int x;
		std :: cin >> x;
		sum[i] = sum[i-1] ^ x;
		mp[sum[i]].pb(i);
	}
	while(q --) {
		int l, r;
		std :: cin >> l >> r;
		if(sum[r] == sum[l-1]) {
			std :: cout << "YES\n";
		} else {
			auto &v1 = mp[sum[l-1]], &v2 = mp[sum[r]];
			auto it1 = std :: lower_bound(v1.begin(), v1.end(), r);
			auto it2 = std :: lower_bound(v2.begin(), v2.end(), l);
			// std :: cout << (it1 != v1.end()) << ' ' << (it2 != v2.end()) << nl;
			// std :: cout << *prev(it1) << ' ' << *it2 << nl;
			if(it1 != v1.begin() && it2 != v2.end() && *it2 < *prev(it1)) {
				std :: cout << "YES\n";
			} else {
				std :: cout << "NO\n";
			}
		}
	}
	std :: cout << nl;
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