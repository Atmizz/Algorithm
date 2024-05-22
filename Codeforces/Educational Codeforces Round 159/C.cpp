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
// const int N = ;
void solve() {
	int n; std :: cin >> n;
	std :: vector <i64> a(n);
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i];
	i64 gcd = std :: abs(a[1] - a[0]);
	for(int i = 2; i < n; ++ i)
		gcd = std :: __gcd(std :: abs(a[i] - a[i-1]), gcd);
	std :: sort(a.begin(), a.end());

	i64 ans = 0;
	for(int i = 0; i < n - 1; ++ i)
		ans += (a[n-1] - a[i]) / gcd;
	for(int i = n - 1; i > 0; -- i) {
		if(a[i] - a[i-1] == gcd) continue;
		ans += (a[n-1] - a[i]) / gcd + 1;
		std :: cout << ans << '\n';
		return ;
	}
	ans += (a[n-1] - a[0]) / gcd + 1;
	std :: cout << ans << '\n';
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