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
// const int N = ;
bool flag;
// void dfs(i64 n, i64 k, i64 t, i64 a, i64 b, i64 sum) {
// 	// std :: cout << a << ' ' << b << endl;
// 	// std :: cout << sum << endl;
// 	if(sum + t > n * 2 || flag == 1 || a + b > n * 2) return ;
	
// 	if(sum + t == n * 2) {
// 		std :: cout << a << ' ' << b << endl;
// 		flag = 1;
// 		return ;
// 	}
	
// 	if(n & (1 << k)) {
// 		if(t == 0) dfs(n, k + 1, 0, a + (1ll << k), b, sum + (1 << k));
// 		else dfs(n, k + 1, (1ll << (k+1)), a + (1ll << k), b, sum);
// 	} else {
// 		dfs(n, k + 1, (1ll << (k + 1)), a + (1ll << k), b + (1ll << k), sum + t);
// 		dfs(n, k + 1, 0, a, b, sum + t);
// 	}
// }
void solve() {
	i64 n; std :: cin >> n;
	// flag = 0; 
	// dfs(n, 0, 0, 0, 0, 0);
	// deb(flag);
	if(n * 2 % 4 != 0) std :: cout << -1 << endl;
	else {
		i64 a = n / 2 * 3;
		i64 b = n / 2;
		// std :: cout << a << ' ' << b << ' ' << (a ^ b) << endl;
		if((a ^ b) != n) {
			std :: cout << -1 << endl;
			return ;
		}
		std :: cout << n / 2 * 3 << ' ' << n / 2 << endl;
		assert(a ^ b != n);
	}
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
