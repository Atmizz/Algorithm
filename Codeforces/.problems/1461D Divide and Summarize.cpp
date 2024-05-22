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
int n, q;
i64 a[N], sum[N];
std :: map <i64, bool> vis;
void dfs(int l, int r) {
	// std :: cout << l << ' ' << r << '\n';
	vis[sum[r]-sum[l-1]] = 1;
	if(l == r) {
		return ;
	}
	i64 mid = (a[l] + a[r]) / 2;
	int pos = std :: upper_bound(a + l, a + r + 1, mid) - a - 1;
	// deb(pos);
	if(pos == r) {
		return ;
	}
	dfs(l, pos);
	dfs(pos+1, r);
}
void solve() {
	vis.clear();
	std :: cin >> n >> q;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	std :: sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; ++ i) {
		sum[i] = sum[i-1] + a[i];
	}
	dfs(1, n);
	while(q --) {
		i64 x;
		std :: cin >> x;
		std :: cout << (vis[x] ? "Yes\n" : "No\n");
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