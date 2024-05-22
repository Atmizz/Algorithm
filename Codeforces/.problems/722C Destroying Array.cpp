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
int n, a[N], b[N], pa[N];
i64 sum[N], ans[N];
bool vis[N];
int find(int x) {
	return x == pa[x] ? x : pa[x] = find(pa[x]);
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> b[i];
	}
	for(int i = 0; i <= n + 1; ++ i) {
		pa[i] = i;
	}
	vis[0] = vis[n+1] = 0;
	for(int i = n; i >= 1; -- i) {
		int x = b[i], u = x - 1, v = x + 1;
		if(vis[u]) {
			u = find(u);
		}
		if(vis[x+1]) {
			v = find(v);
		}
		// deb(b[i]);
		if(vis[u] && vis[v]) {
			// std :: cout << 1 << '\n';
			pa[u] = v; pa[x] = v;
			sum[v] += sum[u] + a[x];
			ans[i-1] = std :: max(ans[i], sum[v]);
		}
		else if(vis[u]) {
			// std :: cout << 2 << '\n';
			sum[u] += a[x]; pa[x] = u;
			ans[i-1] = std :: max(ans[i], sum[u]);
		}
		else if(vis[v]) {
			// std :: cout << 3 << '\n';
			sum[v] += a[x]; pa[x] = v;
			ans[i-1] = std :: max(ans[i], sum[v]);
		}
		else {
			// std :: cout << 4 << '\n';
			sum[x] += a[x];
			ans[i-1] = std :: max(ans[i], sum[x]);
		}
		vis[x] = 1;
	}
	for(int i = 1; i <= n; ++ i) {
		std :: cout << ans[i] << '\n';
	}
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