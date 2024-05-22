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
	int h, w, n;
	std :: cin >> h >> w >> n;
	std :: set <PII> s[2];
	s[0].insert({h, 0});
	s[1].insert({w, 0});
	std :: multiset <int> slen[2];
	slen[0].insert(h);
	slen[1].insert(w);
	while(n --) {
		char ch; int x;
		std :: cin >> ch >> x;
		int op = (ch == 'Y');
		// deb(op);
		auto pos = s[op].lower_bound({x, 0});
		auto [u, v] = *pos;
		auto sop = slen[op].lower_bound(u - v);
		slen[op].erase(sop);
		s[op].erase(pos);
		s[op].insert({u, x});
		s[op].insert({x, v});
		slen[op].insert(u - x);
		slen[op].insert(x - v);
		// for(auto res : slen[0]) {
		// 	deb(res);
		// }
		// for(auto les : slen[1]) {
		// 	deb(les);
		// }
		// std :: cout << u << ' ' << x << ' ' << v << nl;
		// std :: cout << *slen[0].rbegin() << ' ' << *slen[1].rbegin() << nl;
		std :: cout << 1LL * *slen[0].rbegin() * *slen[1].rbegin() << nl;
	}
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