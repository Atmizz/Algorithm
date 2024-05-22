#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 4e5 + 20;
struct Node {
	int l, r;
	i64 sum, lz;
}t[N<<2];
struct Egde {
	int to, net;
}e[N<<1];
int n, m, col[N], w[N], cnt, head[N<<1], son[N];
int dep[N], fa[N], dfn[N], dnf, top[N], sz[N];
void insert(int u, int v) {
	e[++cnt] = {v, head[u]};
	head[u] = cnt;
}
void dfs1(int u, int pa) {
	fa[u] = pa; dep[u] = dep[pa] + 1; sz[u] = 1;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == pa) continue;
		dfs1(v, u); sz[u] += sz[v];
		if(sz[son[u]] < sz[v]) son[u] = v;
	}
}
void dfs2(int u, int topf) {
	top[u] = topf; dfn[u] = ++ dnf; w[dnf] = col[u];
	if(son[u]) dfs2(son[u], topf);
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}
void pushUp(int k) {
	t[k].sum = t[ls].sum | t[rs].sum;
}
void pushDown(int k) {
	t[ls].sum = t[ls].lz = t[k].lz;
	t[rs].sum = t[rs].lz = t[k].lz;
	t[k].lz = 0;
}
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	if(l == r) {
		t[k].sum = (1ll << w[l]);
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls); build(mid+1, r, rs);
	pushUp(k);
}
void modify(int l, int r, int k, i64 c) {
	if(t[k].l >= l && t[k].r <= r) {
		t[k].sum = t[k].lz = 1ll << c;
		return ;
	}
	if(t[k].lz != 0) pushDown(k);
	int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) modify(l, r, ls, c);
	if(r > mid) modify(l, r, rs, c);
	pushUp(k);
}
i64 query(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) return t[k].sum;
	if(t[k].lz != 0) pushDown(k);
	int mid = (t[k].l + t[k].r) >> 1;
	i64 sum = 0;
	if(l <= mid) sum |= query(l, r, ls);
	if(r > mid) sum |= query(l, r, rs);
	return sum;
}
void modifyCol(int x, int c) {
	modify(dfn[x], dfn[x] + sz[x] - 1, 1, c);
}
int queryCol(int x) {
	i64 sum = query(dfn[x], dfn[x] + sz[x] - 1, 1);
	int ans = 0;
	for(; sum; sum >>= 1ll)
		if(sum & 1ll) ans ++;
	return ans;
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> col[i];
	for(int i = 1; i < n; ++ i) {
		int u, v; std :: cin >> u >> v;
		insert(u, v); insert(v, u);
	}
	dfs1(1, 1); dfs2(1, 1); build(1, n, 1);
	while(m --) {
		int opt, x, y;
		std :: cin >> opt >> x;
		if(opt == 1) {
			std :: cin >> y;
			modifyCol(x, y);
		} else std :: cout << queryCol(x) << endl;
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