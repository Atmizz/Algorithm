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
// const int N = ;
std :: map <i64, double> dp;
i64 n;
int a, x, y;
double dfs(i64 u) {
	if(u == 0) {
		return 0.00;
	}
	if(dp.count(u)) {
		return dp[u];
	}
	double cst1 = dfs(u / a) + x;
	double cst2 = 0;
	for(int i = 2; i <= 6; ++ i) {
		cst2 += dfs(u / i);
	}
	cst2 = cst2 / 5 + y * 6.00 / 5;
	return dp[u] = min(cst1, cst2);
}
void solve() {
	std :: cin >> n >> a >> x >> y;
	printf("%.15lf", dfs(n));
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