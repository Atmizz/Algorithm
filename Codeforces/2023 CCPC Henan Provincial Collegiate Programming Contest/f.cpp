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
const int N = 5e5 + 20;
std :: mt19937 rd(114514);
int f[N][32], n, k;
void solve() {
	std :: cin >> n >> k;
	std :: vector <int> a(n+1);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	std :: sort(a.begin(), a.end());
	memset(f, INF, sizeof f);
	for(int i = 1; i <= n; ++ i) {
		f[i][0] = a[i] - a[i-1];
	}
	for(int j = 1; j <= 30; ++ j) {
		for(int i = 1; i + (1<<j) - 1 <= n; ++ i) {
			f[i][j] = std :: min(f[i][j-1], f[i+(1<<j-1)][j-1]);
		}
	}
	auto query = [&](int l, int r) {
		int k = std :: log2(r - l + 1);
		return std :: min(f[l][k], f[r-(1<<k)+1][k]);
	};
	i64 ans = LLINF;
	for(int i = 1; i <= n - k + 1; ++ i) {
		ans = std :: min(ans, 1LL * (a[i+k-1] - a[i]) * query(i+1, i+k-1));
	}
	std :: cout << ans;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}