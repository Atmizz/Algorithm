#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1010;
const int M = 1e5 + 20;
int pa[N], n, m;
struct Edge {
	int u, v, t;
	friend bool operator < (Edge a, Edge b) {
		return a.t < b.t;
	}
}l[M];
int find(int x) {
	return x == pa[x] ? x : pa[x] = find(pa[x]);
}
void solve() {
	std :: cin >> n >> m;
	for(int i = 1; i <= m; ++ i) {
		std :: cin >> l[i].u >> l[i].v >> l[i].t;
	}
	for(int i = 1; i <= n; ++ i) {
		pa[i] = i;
	}
	std :: sort(l + 1, l + 1 + m);
	int k = 0;
	for(int i = 1; i <= m; ++ i) {
		int u = l[i].u, v = l[i].v, t = l[i].t;
		u = find(u); v = find(v);
		if(u == v) {
			continue;
		}
		pa[u] = v;
		k ++;
		if(k == n - 1) {
			std :: cout << t << '\n';
			return ;
		}
	}
	std :: cout << -1 << '\n';
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