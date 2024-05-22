#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
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
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e4 + 20;
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
void solve() {
	int n, m;
	std :: cin >> n >> m;
	DS.init(n);
	while(m --) {
		int opt, u, v;
		std :: cin >> opt >> u >> v;
		if(opt == 1) {
			DS.unit(u, v);
		} else {
			std :: cout << (DS.query(u, v) ? "Y\n" : "N\n");
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