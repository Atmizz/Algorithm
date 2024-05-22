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
const int N = 1e5 + 20;
int n, a[N], f[N], b[N];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	if(n == 1) {
		std :: cout << 1 << endl;
		return ;
	}
	for(int i = 1; i <= n; ++ i) {
		f[i] = 1;
		if(i == 1) continue;
		if(a[i] > a[i-1]) f[i] = f[i-1] + 1;
	}
	b[n] = f[n];
	for(int i = n; i >= 1; -- i)
		if(f[i] == f[i-1] + 1) b[i-1] = b[i];
		else b[i-1] = f[i-1];
	int ans = 1; f[0] = -1; f[n+1] = -1;
	for(int i = 1; i <= n; ++ i)
		ans = std :: max(ans, f[i]);
	for(int i = 1; i < n; ++ i)
		ans = std :: max(ans, f[i] + 1);
	for(int i = 2; i <= n; ++ i)
		if(f[i-1] + 1 != f[i])
			ans = std :: max(ans, b[i] + 1);
	for(int i = 2; i < n; ++ i)
		if(a[i-1] + 1 < a[i+1])
			ans = std :: max(ans, f[i-1] + 1 + b[i+1] - f[i+1] + 1);
		std :: cout << ans;
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