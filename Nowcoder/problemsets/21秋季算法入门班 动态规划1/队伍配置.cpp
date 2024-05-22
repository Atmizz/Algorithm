#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << endl;
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
template <class T>
T abs(T a) {
	return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 150;
i64 dp1[6][N], dp2[6][N];
int n, m, d;
void solve() {
	std :: cin >> n >> m >> d;
	for(int i = 1; i <= n; ++ i) {
		i64 a, b;
		std :: cin >> a >> b;
		for(int j = min(i, 5); j >= 1; -- j) {
			for(int k = d; k >= b; -- k) {
				if(dp1[j-1][k-b] == -INF) {
					continue ;
				}
				dp1[j][k] = max(dp1[j][k], dp1[j-1][k-b] + a);
			}
		} 
	}
	for(int i = 1; i <= m; ++ i) {
		i64 a, b;
		std :: cin >> a >> b;
		for(int j = min(i, 5); j >= 1; -- j) {
			for(int k = d; k >= b; -- k) {
				if(dp2[j-1][k-b] == -INF) {
					continue ;
				}
				dp2[j][k] = max(dp2[j][k], dp2[j-1][k-b] + a);
			}
		} 
	}
	i64 ans = 0;
	for(int i = 1; i <= 5; ++ i) {
		for(int j = 0; j <= i; ++ j) {
			for(int k = 0; k <= d; ++ k) {
				for(int h = 0; h <= d; ++ h) {
					if(k + h > d) {
						break;
					}
					ans = max(ans, dp1[i][k] + dp2[j][h]);
				}
			}
		}
	}
	std :: cout << ans;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	//std :: cin >> _; 
	while(_ --) solve();
	return 0;
}