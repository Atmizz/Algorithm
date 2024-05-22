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
const int N = 1000;
int f[N];
void solve() {
	int n, a[4];
	std :: cin >> n >> a[1] >> a[2] >> a[3];
	int val[4] = {0, 6, 8, 12};
	for(int i = 1; i <= n + 12; ++ i)
		f[i] = INF;
	int ans = INF;
	for(int i = 0; i <= n; ++ i)
		if(f[i] != INF)
			for(int j = 1; j <= 3; ++ j) {
				f[i+val[j]] = std :: min(f[i+val[j]], f[i] + a[j]);
				if(i + val[j] >= n) ans = std :: min(ans, f[i+val[j]]);
			}
	std :: cout << ans ;
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