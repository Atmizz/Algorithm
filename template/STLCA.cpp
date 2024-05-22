#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << endl;
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
struct STQueryLCA {
	struct Edge {
		int to, net;
	}e[N<<1];
	int head[N], st[N][21], dep[N], cnt;
	void insert(int u, int v) {
		e[++cnt] = {v, head[u]};
		head[u] = cnt;
	}
	void dfs(int u, int fa) {
		st[u][0] = fa;
		dep[u] = dep[fa] + 1;
		for(int i = 1; dep[u] - (1 << i) > 0; ++ i) {
			st[u][i] = st[st[u][i-1]][i-1];
		}
		for(int i = head[u]; i; i = e[i].net) {
			int v = e[i].to;
			if(v == fa) {
				continue ;
			}
			dfs(v, u);
		}
	}
	int LCA(int x, int y) {
		if(dep[x] < dep[y]) {
			std :: swap(x, y);
		}
		for(int i = 20; i >= 0; -- i) {
			if(dep[st[x][i]] >= dep[y]) {
				x = st[x][i];
			}
		}
		if(x == y) {
			return x;
		}
		for(int i = 20; i >= 0; -- i) {
			if(st[x][i] != st[y][i]) {
				x = st[x][i];
				y = st[y][i];
			}
		}
		return st[x][0];
	}
}STLCA;
void solve() {
	int n, m, s;
	std :: cin >> n >> m >> s;
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		STLCA.insert(u, v);
		STLCA.insert(v, u);
	}
	STLCA.dfs(s, s);
	while(m --) {
		int x, y;
		std :: cin >> x >> y;
		std :: cout << STLCA.LCA(x, y) << nl;
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