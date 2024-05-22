#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1020;
i64 f[N], w[N], v[N], n, m;
void solve() {
	std :: cin >> n >> m;
	for(int i = 0; i <= m; ++ i)
		f[i] = 0;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> v[i];
	for(int i = 1; i <= n; ++ i)
		std :: cin >> w[i];
	for(int i = 1; i <= n; ++ i)
		for(int j = m; j >= w[i]; -- j)
			f[j] = std :: max(f[j], f[j-w[i]] + v[i]);
	std :: cout << f[m] << endl;
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