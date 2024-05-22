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
#define DEB std :: cout << "ok" << '\n';
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
// const int N = ;
void solve() {
	int n, X, m, Y;
	std :: cin >> n >> X;
	std :: vector <int> a(n);
	for(int &x : a) {
		std :: cin >> x;
	}
	std :: cin >> m >> Y;
	std :: vector <int> b(m);
	for(int &x : b) {
		std :: cin >> x;
	}
	std :: vector dp1(n, std :: vector <int> (1 << 17));
	std :: vector dp2(m, std :: vector <int> (1 << 17));
	auto init = [&](auto &dp) -> void {
		for(int i = 0; i < sz(dp); ++ i) {
			for(int j = 1; j < 1 << 17; ++ j) {
				for(int k = 1; k < 17; ++ k) {
					if(!(j >> k & 1)) {
						dp[i][j] = dp[i][j^(1<<k)] + k;
					}
				}
			}
		}
	};
	init(dp1); init(dp2);
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j < 1 << 17; ++ j) {
			int res = 0;
			for(int k = 1; k < 17; ++ k) {
				if(j >> k & 1) {
					res += k;
				}
			}
			if(res == dp1[i][j]) {
				std :: cout << i << ' ' << j << '\n';
			}
		}
	}
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