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
const int Range = 1e5;
const double eps = 1e-6;
const int N = 1e5 + 20;
struct Edge {
	int to, net;
}e[N<<1];
int T, cnt, head[N], n, q, p[N];
inline void Insert(int u, int v) {
	e[++cnt] = {v, head[u]};
	head[u] = cnt;
}
int t, sz[N], dep[N], dfn[N], dnf, fa[N], top[N], son[N], rt1[N], tot1, rt2[N], tot2, lst[N], ll;
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
	top[u] = topf; dfn[u] = ++ dnf; lst[++ll] = u;
	if(son[u]) dfs2(son[u], topf);
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}
struct Node1 {
	int l, r, sum;
}t1[N * 40], t2[N * 40];

void Insert1(int &k, int bk, int l, int r, int x) {
	if(!k) k = ++ tot1;
	t1[k].sum = t1[bk].sum; t1[k].sum ++;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	if(x <= mid) {
		t1[k].r = t1[bk].r;
		Insert1(t1[k].l, t1[bk].l, l, mid, x);
	} else {
		t1[k].l = t1[bk].l;
		Insert1(t1[k].r, t1[bk].r, mid + 1, r, x);
	}
}
void Insert2(int &k, int bk, int l, int r, int x) {
	if(!k) k = ++ tot2;
	t2[k].sum = t2[bk].sum; t2[k].sum ++;
	if(l == r) return ;
	int mid = (l + r) >> 1;
	if(x <= mid) {
		t2[k].r = t2[bk].r;
		Insert2(t2[k].l, t2[bk].l, l, mid, x);
	} else {
		t2[k].l = t2[bk].l;
		Insert2(t2[k].r, t2[bk].r, mid + 1, r, x);
	}
}
bool query(int k1, int k2, int k3, int k4, int l, int r) {
	// std :: cout << l << ' ' << r << '\n';
	if(l == r) return true;
	if(t1[k1].sum - t1[k2].sum > ((l + r) >> 1) && t2[k3].sum - t2[k4].sum > ((l + r) >> 1))
		return true;
	int res1 = t1[t1[k1].l].sum - t1[t1[k2].l].sum;
	int res2 = t2[t2[k3].l].sum - t2[t2[k4].l].sum;
	int res3 = t1[t1[k1].r].sum - t1[t1[k2].r].sum;
	int res4 = t2[t2[k3].r].sum - t2[t2[k4].r].sum;
	// deb(t2[t2[k3].r].sum);
	// std :: cout << res1 << ' ' << res2 << ' ' << res3 << ' ' << res4 << '\n';
	bool flag = 0;
	int mid = (l + r) >> 1;
	if(res2 > 0 && res1 > 0)
		flag |= query(t1[k1].l, t1[k2].l, t2[k3].l, t2[k4].l, l, mid);
	if(flag == 1) return true;
	if(res3 > 0 && res4 > 0)
		flag |= query(t1[k1].r, t1[k2].r, t2[k3].r, t2[k4].r, mid + 1, r);
	return flag;
}

void init() {
	std :: fill(rt1 + 1, rt1 + 1 + n, 0);
	std :: fill(rt2 + 1, rt2 + 1 + n, 0);
	for(int i = 1; i <= tot1; ++ i)
		t1[i].l = t1[i].r = t1[i].sum = 0;
	for(int i = 1; i <= tot2; ++ i)
		t2[i].l = t2[i].r = t2[i].sum = 0;
	cnt = tot1 = tot2 = dnf = 0; ll = 0;
	std :: fill(head + 1, head + 1 + n, 0);
	std :: fill(son + 1, son + 1 + n, 0);
}
void solve() {
	std :: cin >> n >> q;
	for(int i = 1; i < n; ++ i) {
		int u, v; std :: cin >> u >> v;
		Insert(u, v); Insert(v, u);
	}
	for(int i = 1; i <= n; ++ i)
		std :: cin >> p[i];
	dfs1(1, 1); dfs2(1, 1);
	for(int i = 1; i <= n; ++ i)
		Insert1(rt1[i], rt1[i-1], 1, n, lst[i]);
	for(int i = 1; i <= n; ++ i)
		Insert2(rt2[i], rt2[i-1], 1, n, p[i]);
	for(int i = 1; i <= q; ++ i) {
		int l, r, x;
		std :: cin >> l >> r >> x;
		if(query(rt1[dfn[x] + sz[x] - 1], rt1[dfn[x]-1], rt2[r], rt2[l-1], 1, n))
			std :: cout << "YES\n";
		else std :: cout << "NO\n";
	}
	std :: cout << '\n';
	if(T != 0) init();
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	T = 1;
	std :: cin >> T;
	while(T --) solve();
	return 0;
}