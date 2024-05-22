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
const int N = 5e6 + 20;
std :: mt19937 rd(114514);
int x[N], y[N], a[N];
void solve() {
	int n;
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = i + 1; j <= n; ++ j) {
			if((x[a[i]+a[j]] != 0 && y[a[i]+a[j]] != 0) && 
				(x[a[i]+a[j]] != i && x[a[i]+a[j]] != j) && 
				(y[a[i]+a[j]] != j && y[a[i]+a[j]] != i)) {
				std :: cout << "YES\n";
				std :: cout << i << ' ' << j << ' ' << x[a[i]+a[j]] << ' ' << y[a[i]+a[j]] << '\n';
				return ;
			}
			x[a[i]+a[j]] = i;
			y[a[i]+a[j]] = j;
		}
	}
	std :: cout << "NO\n";
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	// std :: cin >> T; 
	while(T --) solve();
	return 0;
}