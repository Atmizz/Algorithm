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
const int N = 60;
const int M = 1e6 + 20;
int n, m, t, B[N];
struct Deal {
	int j;
	i64 a, c;
	friend bool operator < (Deal a, Deal b) {
		return b.c * B[a.j] > a.c * B[b.j];
	}
}a[N];
i64 dp[M];
void solve() {
	for(int i = 0; i < M; ++ i) {
		dp[i] = LLONG_MIN / 2;
	}
	dp[0] = 0;
	std :: cin >> n >> m >> t;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> B[i];
	}
	for(int i = 1; i <= m; ++ i) {
		std :: cin >> a[i].j >> a[i].a >> a[i].c;
	}
	std :: sort(a + 1, a + 1 + m);
	for(int i = 1; i <= m; ++ i) {
		for(i64 j = t; j >= a[i].c; -- j) {
			dp[j] = max(dp[j], dp[j-a[i].c] + a[i].a - j * B[a[i].j]);
		}
	}
	i64 ans = LLONG_MIN;
	for(int i = 1; i <= t; ++ i) {
		ans = max(ans, dp[i]);
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