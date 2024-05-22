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
const int N = 1e6 + 20;
int n, cnt, head[N], d[N], trie[N<<5][2], tot, ans;
struct Node {
	int to, net, w;
}e[N<<1];
void init() {
	cnt = 0; tot = 0; ans = 0;
	memset(trie, 0, sizeof trie);
	memset(head, 0, sizeof head);
	memset(d, 0, sizeof d);
	memset(e, 0, sizeof e);
}
void Insert(int u, int v, int w) {
	e[++cnt].to = v;
	e[cnt].w = w;
	e[cnt].net = head[u];
	head[u] = cnt;
}
void dfs(int u, int fa) {
	for(int i = head[u]; i; i = e[i].net) {
		int v = e[i].to;
		if(v == fa) continue;
		d[v] = d[u] ^ e[i].w;
		dfs(v, u);
	}
}
void insert(int x) {
	int p = 0;
	for(int i = 30; i >= 0; -- i) {
		int v = x >> i & 1;
		if(!trie[p][v]) trie[p][v] = ++ tot;
		p = trie[p][v];
	}
}
int query(int x) {
	int p = 0, res = 0;
	for(int i = 30; i >= 0; -- i) {
		int v = x >> i & 1;
		if(trie[p][!v])
			res += (1 << i), p = trie[p][!v];
		else p = trie[p][v];
	} return res;
}
void solve() {
	while(~scanf("%d", &n)) {
		for(int i = 1; i < n; ++ i) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			u ++; v ++;
			Insert(u, v, w); Insert(v, u, w);
		}
		dfs(1, 1);
		for(int i = 1; i <= n; ++ i) insert(d[i]);
		for(int i = 1; i <= n; ++ i)
			ans = std :: max(ans, query(d[i]));
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
