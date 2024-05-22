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
const i64 Range = 1e18;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const i64 N = 2e6;
void solve() {
	i64 D, ans = Range; std :: cin >> D;
	for(i64 i = 0; i <= N; ++ i) {
		i64 a = i * i;
		if(a <= D) {
			i64 b = sqrt(D - a);
			ans = std :: min(ans, std :: min(D - a - b * b, a + (b + 1) * (b + 1) - D));
		}
		else ans = std :: min(ans, a + 1 - D);
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
