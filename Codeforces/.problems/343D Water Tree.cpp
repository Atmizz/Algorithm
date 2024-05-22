#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 5e5 + 20;
namespace HeavyChain {
	int sz[N], son[N], top[N], dfn[N], dnf, fa[N], dep[N], head[N<<1], cnt;
	struct Edge {
		int to, net;
	}e[N<<1];
	struct Node {
		int val, l, r;
	}t[N<<2];
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
			if(sz[v] > sz[son[u]]) son[u] = v;
		}
	}
	void dfs2(int u, int topf) {
		top[u] = topf; dfn[u] = ++ dnf;
		if(son[u]) dfs2(son[u], topf);
		for(int i = head[u]; i; i = e[i].net) {
			int v = e[i].to;
			if(v == fa[u] || v == son[u]) continue;
			dfs2(v, v);
		}
	}
	void pushup(int k) {
		if(t[ls].val == t[rs].val) t[k].val = t[ls].val;
		else t[k].val = -1;
	}
	void pushdown(int k) {
		t[ls].val = t[rs].val = t[k].val;
	}
	void build(int l, int r, int k) {
		t[k].l = l; t[k].r = r; t[k].val = 0;
		if(l == r) return ;
		int mid = (l + r) >> 1;
		build(l, mid, ls); build(mid+1, r, rs);
	}
	void modify(int l, int r, int k, int x) {
		if(t[k].l >= l && t[k].r <= r) {
			t[k].val = x;
			return ;
		}
		if(t[k].val != -1) pushdown(k);
		int mid = (t[k].l + t[k].r) >> 1;
		if(l <= mid) modify(l, r, ls, x);
		if(r > mid) modify(l, r, rs, x);
		pushup(k);
	}
	int query(int l, int r, int k) {
		if(l >= t[k].l && r <= t[k].r && t[k].val != -1)
			return t[k].val;
		if(t[k].val != -1) pushdown(k);
		int mid = (t[k].l + t[k].r) >> 1;
		if(l <= mid) return query(l, r, ls);
		else return query(l, r, rs);
	}
	void update1(int u) {
		modify(dfn[u], dfn[u] + sz[u] - 1, 1, 1);
	}
	void update2(int y) {
		int x = 1;
		while(top[x] != top[y]) {
			if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
			modify(dfn[top[x]], dfn[x], 1, 0); x = fa[top[x]];
		}
		if(dep[x] > dep[y]) std :: swap(x, y);
		modify(dfn[x], dfn[y], 1, 0);
	}
	int Query(int u) {
		return query(dfn[u], dfn[u], 1);
	}
}
void solve() {
	int n;
	std :: cin >> n;
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		HeavyChain :: Insert(u, v);
		HeavyChain :: Insert(v, u);
	}
	HeavyChain :: dfs1(1, 1);
	HeavyChain :: dfs2(1, 1);
	HeavyChain :: build(1, n, 1);
	int m; std :: cin >> m;
	for(int i = 1; i <= m; ++ i) {
		int opt, u;
		std :: cin >> opt >> u;
		if(opt == 1) HeavyChain :: update1(u);
		else if(opt == 2) HeavyChain :: update2(u);
		else std :: cout << HeavyChain :: Query(u) << endl;
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