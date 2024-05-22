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
const int N = 1e5 + 20;
struct HeavyDecomp {
	// Don't forget to dfs1, dfs2 and build!
	struct Segment {
		int l, r;
		i64 sum, lz;
	}t[N<<2];
	struct Edge {
		int to, net;
	}e[N<<1];
	i64 p;
	int head[N], dep[N], sz[N], dfn[N], fa[N], son[N], val[N], top[N], w[N], cnt, dnf;
	void insert(int u, int v) {
		e[++cnt] = {v, head[u]};
		head[u] = cnt;
	}
	void dfs1(int u, int pa) {
		fa[u] = pa; sz[u] = 1; dep[u] = dep[pa] + 1;
		for(int i = head[u]; i; i = e[i].net) {
			int v = e[i].to;
			if(v == pa) {
				continue ;
			}
			dfs1(v, u);
			sz[u] += sz[v];
			if(sz[son[u]] < sz[v]) {
				son[u] = v;
			}
		}
	}
	void dfs2(int u, int topf) {
		top[u] = topf; dfn[u] = ++ dnf; w[dnf] = val[u];
		if(son[u]) {
			dfs2(son[u], topf);
		}
		for(int i = head[u]; i; i = e[i].net) {
			int v = e[i].to;
			if(v == fa[u] || v == son[u]) {
				continue ;
			}
			dfs2(v, v);
		}
	}
	int LCA(int x, int y) {
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
			t[ls].sum = (t[ls].sum + t[k].lz * (t[ls].r - t[ls].l + 1) % p) % p;
			t[rs].sum = (t[rs].sum + t[k].lz * (t[rs].r - t[rs].l + 1) % p) % p;
			t[k].lz = 0;
		}
	}
	void build(int l, int r, int k) {
		t[k].l = l; t[k].r = r;
		if(l == r) {
			t[k].sum = w[l] % p;
			return ;
		}
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid+1, r, rs);
		pushUp(k);
	}
	void modifyAdd(int l, int r, int k, i64 x) {
		if(t[k].l >= l && t[k].r <= r) {
			t[k].lz = (t[k].lz + x) % p;
			t[k].sum = (t[k].sum + x * (t[k].r - t[k].l + 1) % p) % p;
			return ;
		}
		pushDown(k);
		int mid = t[k].l + t[k].r >> 1;
		if(l <= mid) {
			modifyAdd(l, r, ls, x);
		}
		if(r > mid) {
			modifyAdd(l, r, rs, x);
		}
		pushUp(k);
	}
	i64 querySum(int l, int r, int k) {
		if(t[k].l >= l && t[k].r <= r) {
			return t[k].sum;
		}
		pushDown(k);
		int mid = (t[k].l + t[k].r) >> 1;
		i64 sum = 0;
		if(l <= mid) {
			sum = (sum + querySum(l, r, ls)) % p;
		}
		if(r > mid) {
			sum = (sum + querySum(l, r, rs)) % p;
		}
		return sum;
	}
	void modifyAddOnLine(int x, int y, i64 z) {
		while(top[x] != top[y]) {
			if(dep[top[x]] < dep[top[y]]) {
				std :: swap(x, y);
			}
			modifyAdd(dfn[top[x]], dfn[x], 1, z);
			x = fa[top[x]];
		}
		if(dep[x] > dep[y]) {
			std :: swap(x, y);
		}
		modifyAdd(dfn[x], dfn[y], 1, z);
	}
	void modifyAddInTree(int x, i64 z) {
		modifyAdd(dfn[x], dfn[x] + sz[x] - 1, 1, z);
	}
	i64 querySumOnLine(int x, int y) {
		i64 sum = 0;
		while(top[x] != top[y]) {
			if(dep[top[x]] < dep[top[y]]) {
				std :: swap(x, y);
			}
			sum = (sum + querySum(dfn[top[x]], dfn[x], 1)) % p;
			x = fa[top[x]];
		}
		if(dep[x] > dep[y]) {
			std :: swap(x, y);
		}
		sum = (sum + querySum(dfn[x], dfn[y], 1)) % p;
		return sum;
	}
	i64 querySumInTree(int x) {
		return querySum(dfn[x], dfn[x] + sz[x] - 1, 1);
	}
}HeavyD;
void solve() {
	int n, m, r;
	std :: cin >> n >> m >> r >> HeavyD.p;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> HeavyD.val[i];
	}
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		HeavyD.insert(u, v);
		HeavyD.insert(v, u);
	}
	HeavyD.dfs1(r, r);
	HeavyD.dfs2(r, r);
	HeavyD.build(1, n, 1);
	while(m --) {
		int opt, x, y; i64 z;
		std :: cin >> opt >> x;
		if(opt == 1) {
			std :: cin >> y >> z;
			HeavyD.modifyAddOnLine(x, y, z);
		} else if(opt == 2) {
			std :: cin >> y;
			std :: cout << HeavyD.querySumOnLine(x, y) << nl;
		} else if(opt == 3) {
			std :: cin >> z;
			HeavyD.modifyAddInTree(x, z);
		} else {
			std :: cout << HeavyD.querySumInTree(x) << nl;
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