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
const int N = 1e6 + 20;
int fa[N][22], dep[N], q;
int lca(int x, int y) {
	if(dep[x] < dep[y]) {
		std :: swap(x, y);
	}
	for(int i = 21; i >= 0; -- i) {
		if(dep[fa[x][i]] >= dep[y]) {
			x = fa[x][i];
		}
	}
	if(x == y) {
		return x;
	}
	for(int i = 21; i >= 0; -- i) {
		if(fa[x][i] != fa[y][i]) {
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	return fa[x][0];
}
void solve() {
	std :: cin >> q;
	dep[1] = 1;
	dep[2] = dep[3] = dep[4] = 2;
	fa[1][0] = fa[2][0] = fa[3][0] = fa[4][0] = 1;
	int n = 4, a = 3, b = 2, ans = 2;
	while(q --) {
		int x, u = n + 1, v = n + 2; n += 2;
		std :: cin >> x;
		fa[u][0] = fa[v][0] = x;
		dep[u] = dep[v] = dep[x] + 1;
		for(int i = 1; i <= 21; ++ i) {
			fa[u][i] = fa[fa[u][i-1]][i-1];
			fa[v][i] = fa[fa[v][i-1]][i-1];
		}
		int LCA = lca(a, u);
		// deb(LCA)
		if(dep[a] + dep[u] - 2 * dep[LCA] > ans) {
			ans = dep[a] + dep[u] - 2 * dep[LCA];
			b = u;
		}
		LCA = lca(b, u);
		if(dep[b] + dep[u] - 2 * dep[LCA] > ans) {
			ans = dep[b] + dep[u] - 2 * dep[LCA];
			a = u;
		}
		// deb(a);
		// deb(b);
		// deb(dep[b])
		// deb(dep[u])
		// deb(dep[LCA])
		// deb(dep[b] + dep[u] - 2 * dep[LCA])
		std :: cout << ans << '\n';
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}