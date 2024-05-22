#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x7f7f7f7f  ;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1010;
int f[N<<1][N<<1], a[N<<1], n, sum[N<<1];
void solve() {
	while(~scanf("%d", &n)) {
		for(int i = 1; i <= n; ++ i)
			std :: cin >> a[i], a[i+n] = a[i];
	
		for(int i = 1; i <= n << 1; ++ i)
			sum[i] = sum[i-1] + a[i];
			
		for(int len = 2; len <= n; ++ len)
			for(int i = 1; i + len - 1 <= (n << 1); ++ i) {
				int j = i + len - 1;
				f[i][j] = INF;
				for(int k = i; k <= j; ++ k)
					f[i][j] = std :: min(f[i][j], f[i][k] + f[k+1][j] + sum[j] - sum[i-1]);
			}
		int ans = INF;
		for(int i = 1; i <= n; ++ i)
			ans = std :: min(ans, f[i][i+n-1]);
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
