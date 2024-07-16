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
const int N = 1e5 + 20;
struct Node {
	int l, r, sum, lz;
}t[N<<2];
int p, r, n, m, oriVal[N], sz[N], dep[N], son[N], val[N], top[N], fa[N], dfn[N], dnf;
std :: vector <int> adj[N];
void dfs1(int u, int pa) {
	fa[u] = pa; sz[u] = 1;
	dep[u] = dep[pa] + 1;
	for(auto &v : adj[u]) {
		if(v == pa) {
			continue ;
		}
		dfs1(v, u);
		if(sz[v] > sz[son[u]]) {
			son[u] = v;
		}
		sz[u] += sz[v];
	}
}
void dfs2(int u, int topf) {
	dfn[u] = ++ dnf;
	top[u] = topf;
	val[dnf] = oriVal[u];
	if(son[u]) {
		dfs2(son[u], topf);
	}
	for(auto &v : adj[u]) {
		if(v == fa[u] || v == son[u]) {
			continue ;
		}
		dfs2(v, v);
	}
}
int lca(int x, int y) {
	while(top[x] != top[y]) {
		if(dep[top[x]] > dep[top[y]]) {
			x = fa[top[x]];
		} else {
			y = fa[top[y]];
		}
	}
	return dep[x] < dep[y] ? x : y;
}
void pushUp(int k) {
	t[k].sum = (t[ls].sum + t[rs].sum) % p;
}
void pushDown(int k) {
	if(t[k].lz) {
		t[ls].lz = (t[ls].lz + t[k].lz) % p;
		t[rs].lz = (t[rs].lz + t[k].lz) % p;
		t[ls].sum = (t[ls].sum + 1LL * t[k].lz * (t[ls].r - t[ls].l + 1) % p) % p;
		t[rs].sum = (t[rs].sum + 1LL * t[k].lz * (t[rs].r - t[rs].l + 1) % p) % p;
		t[k].lz = 0;
	}
}
void modify(int l, int r, int k, int x) {
	if(t[k].l >= l && t[k].r <= r) {
		t[k].lz = (t[k].lz + x) % p;
		t[k].sum = (t[k].sum + 1LL * x * (t[k].r - t[k].l + 1) % p) % p;
		return ;
	}
	int mid = t[k].l + t[k].r >> 1;
	pushDown(k);
	if(l <= mid) {
		modify(l, r, ls, x);
	}
	if(r > mid) {
		modify(l, r, rs, x);
	}
	pushUp(k);
}
int query(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) {
		return t[k].sum;
	}
	pushDown(k);
	int mid = t[k].l + t[k].r >> 1;
	int sum = 0;
	if(l <= mid) {
		sum = (sum + query(l, r, ls)) % p;
	}
	if(r > mid) {
		sum = (sum + query(l, r, rs)) % p;
	}
	return sum;
}
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	if(l == r) {
		t[k].sum = val[l] % p;
		return ;
	}
	int mid = l + r >> 1;
	build(l, mid, ls);
	build(mid + 1, r, rs);
	pushUp(k);
}
void addLine(int x, int y, int z) {
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) {
			std :: swap(x, y);
		}
		modify(dfn[top[x]], dfn[x], 1, z);
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) {
		std :: swap(x, y);
	}
	modify(dfn[x], dfn[y], 1, z);
}
int queryLine(int x, int y) {
	int sum = 0;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) {
			std :: swap(x, y);
		}
		sum = (sum + query(dfn[top[x]], dfn[x], 1)) % p;
		x = fa[top[x]];
	}
	if(dep[x] > dep[y]) {
		std :: swap(x, y);
	}
	return (sum + query(dfn[x], dfn[y], 1)) % p;
}
void solve() {
	std :: cin >> n >> m >> r >> p;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> oriVal[i];
	}
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs1(r, r); dfs2(r, r); build(1, n, 1);
	while(m --) {
		int op, x, y, z;
		std :: cin >> op >> x;
		if(op == 1) {
			std :: cin >> y >> z;
			addLine(x, y, z);
		} else if(op == 2) {
			std :: cin >> y;
			std :: cout << queryLine(x, y) << nl;
		} else if(op == 3) {
			std :: cin >> z;
			modify(dfn[x], dfn[x] + sz[x] - 1, 1, z);
		} else {
			std :: cout << query(dfn[x], dfn[x] + sz[x] - 1, 1) << nl;
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