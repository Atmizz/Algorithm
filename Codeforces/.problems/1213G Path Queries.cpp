#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << '\n';
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
const int N = 2e5 + 20;
int n, m, pa[N], sz[N];
struct Node {
	int val, id;
	friend bool operator <(Node a, Node b) {
		return a.val < b.val;
	}
}q[N];
struct Edge {
	int u, v, w;
	friend bool operator <(Edge a, Edge b) {
		return a.w < b.w;
	}
}a[N];
int find(int x) {
	return x == pa[x] ? x : pa[x] = find(pa[x]);
}
int unit(int u, int v) {
	if(sz[u] < sz[v]) {
		std :: swap(u, v);
	}
	pa[v] = u;
	sz[u] += sz[v];
	return u;
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i < n; ++ i) {
		std :: cin >> a[i].u >> a[i].v >> a[i].w;
	}
	std :: vector <i64> b(m+1);
	for(int i = 1; i <= m; ++ i) {
		std :: cin >> q[i].val;
		q[i].id = i;
	}
	std :: sort(a + 1, a + n);
	std :: sort(q + 1, q + 1 + m);
	for(int i = 1; i <= n; ++ i) {
		pa[i] = i;
		sz[i] = 1;
	}
	i64 ans = 0;
	for(int i = 1, j = 1; i <= m; ++ i) {
		while(j < n) {
			if(a[j].w > q[i].val) {
				break;
			}
			int uu = find(a[j].u);
			int vv = find(a[j].v);
			ans -= 1LL * sz[uu] * (sz[uu] - 1) / 2;
			ans -= 1LL * sz[vv] * (sz[vv] - 1) / 2;
			int rt = unit(uu, vv);
			ans += 1LL * sz[rt] * (sz[rt] - 1) / 2;
			j ++;
		}
		b[q[i].id] = ans;
	}
	for(int i = 1; i <= m; ++ i) {
		std :: cout << b[i] << ' ';
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