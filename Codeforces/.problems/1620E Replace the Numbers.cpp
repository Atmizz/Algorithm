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
const int N = 5e5 + 20;
std :: set <int> s[N];
int pos[N];
void solve() {
	int n, p = 0;
	std :: cin >> n;
	while(n --) {
		int opt, x, y;
		std :: cin >> opt >> x;
		if(opt == 1) {
			p ++;
			s[x].insert(p);	
		} else {
			std :: cin >> y;
			if(sz(s[y]) < sz(s[x])) {
				std :: swap(s[x], s[y]);
			}
			if(x != y) {
				for(auto u : s[x]) {
					s[y].insert(u);
				}
				s[x].clear();
			}
		}
	}
	for(int i = 1; i < N; ++ i) {
		for(auto x : s[i]) {
			pos[x] = i;
		}
	}
	for(int i = 1; i <= p; ++ i) {
		std :: cout << pos[i] << " ";
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