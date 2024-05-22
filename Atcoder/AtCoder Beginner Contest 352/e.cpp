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
struct Disjoint_Set {
	int pa[N], sz[N];
	void init(int n) {
		for(int i = 1; i <= n; ++ i) {
			pa[i] = i;
			sz[i] = 1;
		}
	} 
	int find(int x) {
		return x == pa[x] ? x : pa[x] = find(pa[x]);
	}
	void unit(int u, int v) {
		u = find(u); v = find(v);
		if(sz[u] > sz[v]) {
			std :: swap(u, v);
		}
		pa[u] = v;
		sz[v] += sz[u];
	}
	bool query(int u, int v) {
		u = find(u); v = find(v);
		return u == v;
	}
}DS;
struct M {
	std :: vector <int> st;
	int k, c;
	friend bool operator < (M a, M b) {
		return a.c < b.c;
	}
};
void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: vector <M> s(m);
	DS.init(n);
	for(int i = 0; i < m; ++ i) {
		std :: cin >> s[i].k >> s[i].c;
		for(int j = 0; j < s[i].k; ++ j) {
			int x;
			std :: cin >> x;
			s[i].st.pb(x);
		}
	}
	std :: sort(s.begin(), s.end());
	i64 ans = 0;
	for(int i = 0; i < m; ++ i) {
		std :: set <int> st;
		for(int &j : s[i].st) {
			st.insert(DS.find(j));
		}
		ans += 1LL * s[i].c * (sz(st) - 1);
		int lst = -1;
		for(auto &j : st) {
			if(lst != -1) {
				DS.unit(lst, j);
			}
			lst = j;
		}
	}
	for(int i = 1; i <= n; ++ i) {
		DS.pa[i] = DS.find(i);
		if(i > 1) {
			if(DS.pa[i] != DS.pa[i-1]) {
				std :: cout << -1;
				return;
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