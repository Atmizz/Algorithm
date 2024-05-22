#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
#define i64 long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int n, m, cnt, head[N], sz[N], a[N], dfn[N], dnf, b[N];
struct Edge {
	int to, net;
}e[N<<1];
void Insert(int u, int v) {
	e[++cnt].to = v;
	e[cnt].net = head[u];
	head[u] = cnt;
}
inline int lowbit(int x) {
	return x & -x;
}
void add(int k, int x) {
	for(; k <= n; k += lowbit(k))
		a[k] += x;
}
int query(int k) {
	int sum = 0;
	for(; k; k -= lowbit(k))
		sum += a[k];
	return sum;
}
void dfs(int u, int fa) {
	dfn[u] = ++ dnf; sz[u] = 1;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa) continue;
		dfs(v, u); sz[u] += sz[v];
	}
}
void init() {
	cnt = 0; dnf = 0;
	for(int i = 1; i <= n; ++ i) head[i] = 0;
	for(int i = 1; i <= n; ++ i) a[i] = 0;
	for(int i = 1; i <= n; ++ i) b[i] = 1;
}
void solve() {
	while(scanf("%d", &n) != EOF) {
		init();
		for(int i = 1; i < n; ++ i) {
			int u, v; scanf("%d %d", &u, &v);
			Insert(u, v); Insert(v, u);
		} dfs(1, 1);
		for(int i = 1; i <= n; ++ i)
			add(dfn[i], 1);
		scanf("%d", &m);
		while(m --) {
			char ch; int x;
			std :: cin >> ch; scanf("%d", &x);
			if(ch == 'C') {
				b[x] ^= 1;
				if(b[x] == 0) add(dfn[x], -1);
				else add(dfn[x], 1);
			} else printf("%d\n", query(dfn[x] + sz[x] - 1) - query(dfn[x]-1));
		}
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//scanf("%d", &T); 
	while(T --) solve();
	return 0;
}