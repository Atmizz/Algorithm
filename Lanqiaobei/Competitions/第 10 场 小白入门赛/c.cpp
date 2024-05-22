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
const int N = 1e5 + 20;
i64 a[N], sum[N];
void solve() {
	int n, A, B;
	std :: cin >> n >> A >> B;
	i64 init0; n --;
	std :: cin >> init0;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	std :: sort(a + 1, a + 1 + n, [&](int x, int y) {
		return x > y;
	});
	for(int i = 1; i <= n; ++ i) {
		sum[i] = sum[i-1] + a[i];
	}
	i64 ans = LLONG_MIN;
	for(int i = 0; i <= min(n, A); ++ i) {
		if(n - i > B) {
			continue ;
		}
		ans = max(ans, sum[i] - (sum[n] - sum[i]));
	}
	std :: cout << ans + init0;
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