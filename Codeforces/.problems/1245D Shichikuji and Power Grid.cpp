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
const int N = 2020;
struct Node {
	int u, v;
	i64 w;
	friend bool operator < (Node a, Node b) {
		return a.w < b.w;
	}
};
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <PII> pos(n);
	for(auto &[x, y] : pos) {
		std :: cin >> x >> y;
	}
	std :: vector <i64> c(n), k(n);
	for(auto &x : c) {
		std :: cin >> x;
	}
	for(auto &x : k) {
		std :: cin >> x;
	}
	std :: vector <Node> a;
	for(int i = 0; i < n; ++ i) {
		a.pb({0, i + 1, c[i]});
	}
	for(int i = 0; i < n; ++ i) {
		for(int j = i + 1; j < n; ++ j) {
			if(i != j) {
				auto &[xx1, yy1] = pos[i];
				auto &[xx2, yy2] = pos[j];
				a.pb({i + 1, j + 1, (k[i] + k[j]) * (abs(xx1 - xx2) + abs(yy1 - yy2))});
			}
		}
	}
	std :: vector <int> pa(n+1);
	for(int i = 1; i <= n; ++ i) {
		pa[i] = i;
	}
	std :: sort(a.begin(), a.end());
	auto find = [&](auto find, int x) -> int {
		return x == pa[x] ? x : pa[x] = find(find, pa[x]);
	};
	i64 ans = 0;
	std :: vector <PII> b;
	for(auto &[u, v, w] : a) {
		int uu = find(find, u);
		int vv = find(find, v);
		if(uu == vv) {
			continue ;
		}
		pa[vv] = uu;
		ans += w;
		b.pb({u, v});
	}
	int cnt = 0;
	for(auto &[u, v] : b) {
		if(u == 0) {
			cnt ++;
		}
	}
	std :: cout << ans << nl;
	std :: cout << cnt << nl;
	for(auto &[u, v] : b) {
		if(u == 0) {
			std :: cout << v << nl;
		}
	}
	std :: cout << sz(b) - cnt << nl;
	for(auto &[u, v] : b) {
		if(u != 0) {
			std :: cout << u << ' ' << v << nl;
		}
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