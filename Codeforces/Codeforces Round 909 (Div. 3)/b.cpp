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
const i64 Range = 1e18;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
int n;
i64 a[N], sum[N];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i)
		sum[i] = sum[i-1] + a[i];
	std :: vector <int> v;
	for(int i = 1; i <= sqrt(n); ++ i) {
		if(n % i != 0) continue;
		v.push_back(i);
		if(i * i != n) v.push_back(n / i);
	}
	i64 ans = 0;
	for(auto b : v) {
		i64 minn = Range, maxx = 0;
		for(int i = b; i <= n; i += b) {
			minn = std :: min(minn, std :: abs(sum[i] - sum[i-b]));
			maxx = std :: max(maxx, std :: abs(sum[i] - sum[i-b]));
		}
		ans = std :: max(ans, maxx - minn);
	}
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