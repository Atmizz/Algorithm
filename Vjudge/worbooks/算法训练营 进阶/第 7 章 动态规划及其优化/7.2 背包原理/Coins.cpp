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
const int N = 1e5 + 20;
int n, m, w[110], v[110], f[N];
void solve() {
	while(1) {
		std :: cin >> n >> m;
		if(n == 0) return ; f[0] = 1;
		for(int i = 1; i <= m; ++ i)
			f[i] = 0;
		for(int i = 1; i <= n; ++ i)
			std :: cin >> v[i];
		for(int i = 1; i <= n; ++ i)
			std :: cin >> w[i];
		for(int i = 1; i <= n; ++ i) {
			if(w[i] * v[i] >= m)
				for(int j = v[i]; j <= m; ++ j)
					f[j] |= f[j-v[i]];
			else
				for(int k = 1; w[i]; k <<= 1) {
					int x = std :: min(k, w[i]);
					for(int j = m; j >= x * v[i]; -- j)
						f[j] |= f[j-x*v[i]];
					w[i] -= x;
				}
		}
		int ans = 0;
		for(int i = 1; i <= m; ++ i)
			if(f[i]) ans ++;
		std :: cout << ans << endl;
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