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
const int N = 1e4 + 20;
int n, m, head[N<<2], cnt, S, rt, sz[N], mx[N], d[N], q[N];
bool vis[N], ANS[N];
struct Edge {
	int to, net, dis;
}e[N<<2];
void Insert(int u, int v, int w) {
	e[++cnt].to = v;
	e[cnt].net = head[u];
	e[cnt].dis = w;
	head[u] = cnt;
}
void init() {
	cnt = 0;
	memset(vis, 0, sizeof vis);
	memset(ANS, 0, sizeof ANS);
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
void getDis(int u, int fa, int dis) {
	if(dis > 10000000) return ;
	d[++d[0]] = dis;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa || vis[v]) continue;
		getDis(v, u, dis + e[i].dis);
	}
}
int res[N], judge[10000010];
void calc(int u) {
	int p = 0;
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(vis[v]) continue;
		d[0] = 0; getDis(v, u, e[i].dis);
		for(int j = 1; j <= d[0]; ++ j)
			for(int k = 1; k <= m; ++ k)
				if(q[k] >= d[j])
					ANS[k] |= judge[q[k] - d[j]];
		for(int j = 1; j <= d[0]; ++ j)
			res[++p] = d[j], judge[d[j]] = 1;
	}
	for(int i = 1; i <= p; ++ i)
		judge[res[i]] = 0;
}
void devide(int u) {
	vis[u] = 1; calc(u);
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(vis[v]) continue;
		S = sz[v]; rt = 0;
		getRoot(v, 0); devide(rt);
	}
}
void solve() {
	while(1) {
		scanf("%d", &n);
		if(n == 0) return ;
		init();
		for(int i = 1; i <= n; ++ i) {
			while(1) {
				int v, w; scanf("%d", &v);
				if(v == 0) break;
				scanf("%d", &w);
				Insert(i, v, w); Insert(v, i, w);
			}
		}
		m = 0;
		while(1) {
			int x; scanf("%d", &x);
			if(x == 0) break;
			q[++m] = x;
		}
		judge[0] = 1; mx[0] = S = n; getRoot(1, 1); devide(rt);
		for(int i = 1; i <= m; ++ i)
			printf(ANS[i] ? "AYE\n" : "NAY\n");
		puts(".");
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