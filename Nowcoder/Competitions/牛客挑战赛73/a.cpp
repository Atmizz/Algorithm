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
// const int N = ;
i64 gcd(i64 a, i64 b) {
	return b == 0 ? a : gcd(b, a % b);
}
void solve() {
	int n;
	std :: cin >> n;
	if(n & 1) {
		std :: cout << (1LL * n * (n + 1) / 2);
	} else {
		int res = n + 1;
		i64 ans = n / 2;
		for(int i = 2; i <= n; ++ i) {
			if(i == n / 2) {
				continue;
			}
			i64 G = gcd(i, res);
			res /= G;
			ans *= G;
		}
		std :: cout << ans;
	}
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