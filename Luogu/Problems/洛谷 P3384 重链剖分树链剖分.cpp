#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int n, m, rt, p, val[N];
namespace HeavyChain {
	struct SegmentTree {
		int l, r, sum, lz;
	}t[N<<2];
	struct Edge {
		int to, net;
	}e[N<<1];
	int head[N], dep[N], sz[N], dfn[N], son[N], top[N], fa[N], id[N], w[N], dnf, cnt;
	inline void Insert(int u, int v) {
		e[++cnt] = {v, head[u]};
		head[u] = cnt;
	}
	void dfs1(int u, int pa) {
		fa[u] = pa; sz[u] = 1; dep[u] = dep[pa] + 1;
		for(int i = head[u]; i; i = e[i].net) {
			int v = e[i].to;
			if(v == pa) continue;
			dfs1(v, u); sz[u] += sz[v];
			if(!son[u] || sz[son[u]] < sz[v]) son[u] = v;
		}
	}
	void dfs2(int u, int topf) {
		top[u] = topf; dfn[u] = ++ dnf; w[dnf] = val[u];
		if(son[u]) dfs2(son[u], topf);
		for(int i = head[u]; i; i = e[i].net) {
			int v = e[i].to;
			if(v == fa[u] || v == son[u]) continue;
			dfs2(v, v);
		}
	}
	void pushUp(int k) {
		t[k].sum = (t[ls].sum + t[rs].sum) % p;
	}
	void pushDown(int k) {
		t[ls].lz = (t[k].lz + t[ls].lz) % p; t[rs].lz = (t[k].lz + t[rs].lz) % p;
    t[ls].sum = (t[ls].sum + t[k].lz * (t[ls].r - t[ls].l + 1)) % p;
    t[rs].sum = (t[rs].sum + t[k].lz * (t[rs].r - t[rs].l + 1)) % p;
    t[k].lz = 0;
	}
	void build(int l, int r, int k) {
		t[k].l = l; t[k].r = r;
		if(l == r) {
			t[k].sum = w[l];
			return ;
		}
		int mid = (l + r) >> 1;
		build(l, mid, ls); build(mid + 1, r, rs);
		pushUp(k);
	}
	void modifyAdd(int l, int r, int k, int x) {
		if(t[k].l >= l && t[k].r <= r) {
			t[k].lz = (t[k].lz + x) % p;
			t[k].sum = (t[k].sum + x * (t[k].r - t[k].l + 1)) % p;
			return ;
		}
		if(t[k].lz) pushDown(k);
		int mid = (t[k].l + t[k].r) >> 1;
		if(l <= mid) modifyAdd(l, r, ls, x);
		if(r > mid) modifyAdd(l, r, rs, x);
		pushUp(k);
	}
	int querySum(int l, int r, int k) {
		if(t[k].l >= l && t[k].r <= r) return t[k].sum;
		int mid = (t[k].l + t[k].r) >> 1;
		int sum = 0;
		if(t[k].lz) pushDown(k);
		if(l <= mid) sum = (sum + querySum(l, r, ls)) % p;
		if(r > mid) sum = (sum + querySum(l, r, rs)) % p;
		return sum;
	}
	void modifyAddOnLine(int x, int y, int z) {
		while(top[x] != top[y]) {
			if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
			modifyAdd(dfn[top[x]], dfn[x], 1, z); x = fa[top[x]];
		}
		if(dep[x] > dep[y]) std :: swap(x, y);
		modifyAdd(dfn[x], dfn[y], 1, z);
	}
	void modifyAddInTree(int x, int z) {
		modifyAdd(dfn[x], dfn[x] + sz[x] - 1, 1, z);
	}
	int querySumOnLine(int x, int y) {
		int sum = 0;
		while(top[x] != top[y]) {
			if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
			sum = (sum + querySum(dfn[top[x]], dfn[x], 1)) % p;
			x = fa[top[x]];
		}
		if(dep[x] > dep[y]) std :: swap(x, y);
		sum = (sum + querySum(dfn[x], dfn[y], 1)) % p;
		return sum;
	}
	int querySumInTree(int x) {
		return querySum(dfn[x], dfn[x] + sz[x] - 1, 1) % p;
	}
}
void solve() {
	std :: cin >> n >> m >> rt >> p;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> val[i];
	for(int i = 1; i < n; ++ i) {
		int u, v; std :: cin >> u >> v;
		HeavyChain :: Insert(u, v);
		HeavyChain :: Insert(v, u);
	}
	HeavyChain :: dfs1(rt, rt);
	HeavyChain :: dfs2(rt, rt);
	HeavyChain :: build(1, n, 1);
	for(int i = 1; i <= m; ++ i) {
		int opt, l, r, x;
		std :: cin >> opt >> l;
		if(opt == 1) {
			std :: cin >> r >> x;
			HeavyChain :: modifyAddOnLine(l, r, x);
		} else if(opt == 2) {
			std :: cin >> r;
			std :: cout << HeavyChain :: querySumOnLine(l, r) << endl;
		} else if(opt == 3) {
			std :: cin >> x;
			HeavyChain :: modifyAddInTree(l, x);
		} else std :: cout << HeavyChain :: querySumInTree(l) << endl;
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