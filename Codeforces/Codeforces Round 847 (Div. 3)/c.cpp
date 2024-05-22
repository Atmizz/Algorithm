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
const int N = 101;
int n, a[N][N];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j < n; ++ j)
			std :: cin >> a[i][j];
	int b = a[n][n-1];
	for(int i = 2; i <= n; ++ i)
		if(a[i][n-1] == a[i-1][n-1]) {
			b = a[i][n-1];
			break;
		}
	for(int i = 1; i <= n; ++ i)
		if(a[i][n-1] != b) {
			for(int j = 1; j <= n - 1; ++ j)
				std :: cout << a[i][j] << ' ';
			std :: cout << b << endl;
			return ;
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