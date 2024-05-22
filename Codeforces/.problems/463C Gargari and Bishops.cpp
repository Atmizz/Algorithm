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
const int N = 2020;
int a[N][N], n, x_1, x_2, y_1, y_2;
i64 sum1[N][N], sum2[N][N], ans1, ans2;
PII get1(int i, int j) {
	return mk(i + min(n-i, n-j), j + min(n-i, n-j));
}
PII get2(int i, int j) {
	if(j <= n - i + 1) {
		return mk(i + j - 1, 1);
	}
	return mk(n, j - (n - i));
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			std :: cin >> a[i][j];
			sum1[i][j] = sum1[i-1][j-1] + a[i][j];
			sum2[i][j] = sum2[i-1][j+1] + a[i][j];
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			if((i + j) & 1) {
				auto [l1, r1] = get1(i, j);
				auto [l2, r2] = get2(i, j);
				// std :: cout << i << ' ' << j << ' ' << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << ' ' << sum1[l1][r1] + sum2[l2][r2] - a[i][j] << nl;
				if(ans1 <= sum1[l1][r1] + sum2[l2][r2] - a[i][j]) {
					ans1 = sum1[l1][r1] + sum2[l2][r2] - a[i][j];
					x_1 = i; y_1 = j;
				}
			} else {
				auto [l1, r1] = get1(i, j);
				auto [l2, r2] = get2(i, j);
				// std :: cout << i << ' ' << j << ' ' << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << ' ' << sum1[l1][r1] + sum2[l2][r2] - a[i][j] << nl;
				if(ans2 <= sum1[l1][r1] + sum2[l2][r2] - a[i][j]) {
					ans2 = sum1[l1][r1] + sum2[l2][r2] - a[i][j];
					x_2 = i, y_2 = j;
				}
			}
		}
	}
	std :: cout << ans1 + ans2 << nl;
	std :: cout << x_1 << ' ' << y_1 << ' ' << x_2 << ' ' << y_2;
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