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
const int N = 1e6 + 20;
int n, m, vis[N], head[N], cnt, st[N];
struct Edge {
	int u, v, w;
	// w = -1 / -2 means the reverse side
	// w = 1 means v is an imposter
	// w = 2 means v is a crewmate
}e[N];
void Insert(int u, int v, int w) {
	e[++cnt] = {u, v, w};
	head[u] = cnt;
}
void solve() {
	std :: cin >> n >> m; cnt = 0;
	for(int i = 1; i <= m; ++ i) {
		int u, v;
		std :: string str;
		std :: cin >> u >> v >> str;
		if(str == "imposter") {
			Insert(u, v, 1);
			Insert(v, u, -1);
		} else {
			Insert(u, v, 2);
			Insert(v, u, -2);
		}
	}
	for(int i = 1; i <= n; ++ i) {
		if(vis[i]) {
			continue;
		}

	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}