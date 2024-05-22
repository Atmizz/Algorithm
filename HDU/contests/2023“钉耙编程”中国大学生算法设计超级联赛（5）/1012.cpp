#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int p = 1e9 + 7;

i64 qmi(i64 a, i64 b) {
	i64 sum = 1ll;
	while(b) {
		if(b & 1) sum = sum * a % p;
		a = a * a % p; b >>= 1;
	} return sum % p;
}

void solve() {
	int n, m, ans;
	std :: cin >> n >> m;
	std :: vector <int> deg(n+1), val(n+1);
	for(int i = 1; i <= m; ++ i) {
		int u, v;
		std :: cin >> u >> v;
		deg[u] ++; deg[v] ++;
	}
	for(int i = 1; i <= n; ++ i)
		if(deg[i] > 1) val[i] = (qmi(2, deg[i]) - 1 - deg[i] + p) % p;
	ans = val[1];
	for(int i = 2; i <= n; ++ i)
		ans ^= val[i];
	std :: cout << ans << endl;
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