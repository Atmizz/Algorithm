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
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 550;
void solve() {
	int n, x, ans = 0, k = 0; std :: cin >> n >> x;
	std :: vector <int> a(n + 1);
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i)
		if(a[i] < a[i-1]) k = i;
	for(int i = 1; i <= k; ++ i)
		if(a[i] > x) std :: swap(a[i], x), ans ++;
	for(int i = 1; i <= n; ++ i)
		if(a[i] < a[i-1]) {
			std :: cout << -1 << endl;
			return ;
		}
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