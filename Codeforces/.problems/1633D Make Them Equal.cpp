#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1010;
int b[N], c[N], n, k, f[N<<1];
i64 dp[N*N];
void init() {
	for(int i = 2; i < N << 1; ++ i)
		f[i] = INF;
	f[1] = 0;
	for(int i = 1; i < N; ++ i)
		for(int j = 1; j <= i; ++ j)
			f[i+i/j] = std :: min(f[i+i/j], f[i] + 1);
}
void solve() {
	std :: cin >> n >> k;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> b[i];
	for(int i = 1; i <= n; ++ i)
		std :: cin >> c[i];
	int sum = 0;
	for(int i = 1; i <= n; ++ i)
		sum += f[b[i]];
	if(sum <= k) {
		sum = 0;
		for(int i = 1; i <= n; ++ i)
			sum += c[i];
		std :: cout << sum << endl;
		return ;
	}
	memset(dp, 0, sizeof dp);
	for(int i = 1; i <= n; ++ i)
		for(int j = k; j >= f[b[i]]; -- j)
			dp[j] = std :: max(dp[j], dp[j-f[b[i]]] + c[i]);
	std :: cout << dp[k] << endl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1; init();
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}