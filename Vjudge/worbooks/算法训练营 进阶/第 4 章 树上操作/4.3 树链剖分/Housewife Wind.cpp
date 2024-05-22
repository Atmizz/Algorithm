#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <stack>
#include <cmath>
#include <bitset>
#include <complex>
#include <cstdlib>
#include <set>
#include <cstring>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
typedef long long i64;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int n, m, s, val[N], u[N], v[N];
namespace HeavyChain {
	struct SegmentTree {
		int l, r, sum;
	}t[N<<2];
	struct Edge {
		int to, net, dis;
	}e[N<<1];
	int head[N], dep[N], sz[N], dfn[N], son[N], top[N], fa[N], id[N], w[N], dnf, cnt;
	inline void Insert(int u, int v, int w) {
		e[++cnt].to = v;
		e[cnt].net = head[u];
		e[cnt].dis = w;
		head[u] = cnt;
	}
	void dfs1(int u, int pa) {
		fa[u] = pa; sz[u] = 1; dep[u] = dep[pa] + 1;
		for(int i = head[u]; i; i = e[i].net) {
			int v = e[i].to;
			if(v == pa) continue;
			val[v] = e[i].dis;
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
		t[k].sum = t[ls].sum + t[rs].sum;
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
	void modifyAssign(int l, int r, int k, int x) {
		if(t[k].l >= l && t[k].r <= r) {
			t[k].sum = x;
			return ;
		}
		int mid = (t[k].l + t[k].r) >> 1;
		if(l <= mid) modifyAssign(l, r, ls, x);
		if(r > mid) modifyAssign(l, r, rs, x);
		pushUp(k);
	}
	int querySum(int l, int r, int k) {
		if(t[k].l >= l && t[k].r <= r) return t[k].sum;
		int mid = (t[k].l + t[k].r) >> 1;
		int sum = 0;
		if(l <= mid) sum = sum + querySum(l, r, ls);
		if(r > mid) sum = sum + querySum(l, r, rs);
		return sum;
	}
	void modifyTheNode(int x, int z) {
		modifyAssign(dfn[x], dfn[x], 1, z);
	}
	int querySumOnLine(int x, int y) {
		int sum = 0;
		while(top[x] != top[y]) {
			if(dep[top[x]] < dep[top[y]]) std :: swap(x, y);
			sum = sum + querySum(dfn[top[x]], dfn[x], 1);
			x = fa[top[x]];
		}
		if(dep[x] > dep[y]) std :: swap(x, y);
		sum = sum + querySum(dfn[x]+1, dfn[y], 1);
		return sum;
	}
}
void solve() {
	scanf("%d %d %d", &n, &m, &s);
	for(int i = 1; i < n; ++ i) {
		int w; scanf("%d %d %d", &u[i], &v[i], &w);
		HeavyChain :: Insert(u[i], v[i], w);
		HeavyChain :: Insert(v[i], u[i], w);
	}
	HeavyChain :: dfs1(1, 1);
	HeavyChain :: dfs2(1, 1);
	HeavyChain :: build(1, n, 1);
	for(int i = 1; i <= m; ++ i) {
		int opt, l, r;
		scanf("%d %d", &opt, &l);
		if(opt == 0) {
			std :: cout << HeavyChain :: querySumOnLine(l, s) << endl;
			s = l;
		}
		else {
			scanf("%d", &r);
			if(HeavyChain :: dep[u[l]] > HeavyChain :: dep[v[l]])
				HeavyChain :: modifyTheNode(u[l], r);
			else HeavyChain :: modifyTheNode(v[l], r);
		}
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}