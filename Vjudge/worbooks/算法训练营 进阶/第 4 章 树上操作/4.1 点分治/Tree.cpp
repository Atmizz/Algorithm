#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
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
const int N = 1e4 + 10;
int n, k, rt, sz[N], cnt, head[N], mx[N], S, ans, dep[N], s;
bool vis[N];
struct Edge {
	int to, net, dis;
}e[N<<1];
void Insert(int u, int v, int w) {
	e[++cnt].to = v;
	e[cnt].net = head[u];
	e[cnt].dis = w;
	head[u] = cnt;
}
void init() {
	cnt = 0; ans = 0;
	memset(vis, 0, sizeof vis);
	memset(head, 0, sizeof head);
}
void getRoot(int u, int fa) {
	sz[u] = 1; mx[u] = 0;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa || vis[v]) continue;
		getRoot(v, u);
		sz[u] += sz[v];
		mx[u] = std :: max(mx[u], sz[v]);
	}
	mx[u] = std :: max(mx[u], S - sz[u]);
	if(mx[u] < mx[rt]) rt = u;
}
void getDep(int u, int fa, int dis) {
	dep[++s] = dis;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa || vis[v]) continue;
		getDep(v, u, dis + e[i].dis);
	}
}
int getSum(int u, int dis) {
	s = 0;
	memset(dep, 0, sizeof dep);
	getDep(u, 0, dis);
	std :: sort(dep + 1, dep + 1 + s);
	int l = 1, r = s, sum = 0;
	while(l < r) {
		if(dep[l] + dep[r] <= k) sum += r - l, l ++;
		else r --;
	}
	return sum;
}
void devide(int u) {
	ans += getSum(u, 0);
	vis[u] = 1;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(vis[v]) continue;
		ans -= getSum(v, e[i].dis);
		rt = 0; S = sz[v];
		getRoot(v, 0);
		devide(rt);
	}
}
void solve() {
	while(1) {
		scanf("%d %d", &n, &k);
		if(n == 0) return ;
		init();
		for(int i = 1;  i < n; ++ i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			Insert(u, v, w); Insert(v, u, w);
		}
		mx[0] = S = n;
		getRoot(1, 0); devide(rt);
		printf("%d\n", ans);
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