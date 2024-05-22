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
const int N = 1e5 + 20;
struct Tree {
	int id, fa;
}t[N];
std :: vector <int> edge[N], dep(N+1);
void solve() {
	int n, ans1 = 0, ans2 = 0;
	std :: cin >> n;
	for(int i = 1; i < n; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i = 1; i <= n; ++ i) {
		std :: sort(edge[i].begin(), edge[i].end());
	}
	std :: queue <PII> q;
	q.push({1, 1});
	int cnt = 0;
	while(q.size()) {
		auto [u, d] = q.front();
		q.pop(); dep[d] ++;
		t[u].id = ++ cnt;
		if(cnt / 2 != t[t[u].fa].id && ans1 == 0) {
			ans1 = cnt - 1;
		}
		for(auto v : edge[u]) {
			if(v == t[u].fa) {
				continue;
			}
			t[v].fa = u;
			q.push({v, d + 1});
		}
	}
	for(int i = 1; i <= n; ++ i) {
		if(dep[i] != (1 << i - 1)) {
			ans2 = (1 << i - 1) - 1;
			break;
		}
	}
	// deb(edge[1].size())
	std :: cout << (ans1 == 0 ? 1 : ans1) << ' ' << (ans2 == 0 ? 1 : ans2) << '\n';
}
int main() {
	// freopen("xr10.in", "r", stdin);
	// freopen("xr1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}