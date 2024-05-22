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
const int N = 26;
int n, m, a[N], b[N], mp[1<<N], dp[1<<N];
int lowbit(int x) {
	return x & -x;
}
void solve() {
	std :: cin >> n;
	int cnt = 0;
	for(int i = 1; i <= 1 << n; i *= 2) {
		mp[i] = cnt;
		cnt ++;
	}
	for(int i = 0; i < n; ++ i) {
		std :: cin >> a[i];
	}
	std :: cin >> m;
	for(int i = 1; i <= m; ++ i) {
		std :: cin >> b[i];
	}
	dp[0] = 1;
	for(int _ = 1; _ < 1 << n; ++ _) {
		int step = 0;
		int res = _;
		while(res) {
			int tmp = lowbit(res);
			step += a[mp[tmp]];
			if(step > Mod) {
				break;
			}
			res ^= tmp;
		}
		if(step == b[1] || step == b[2]) {
			continue;
		}
		res = _;
		while(res) {
			int tmp = lowbit(res);
			dp[_]  += dp[_^tmp];
			if(dp[_] >= Mod) {
				dp[_] -= Mod;
			}
			res ^= tmp;
		}
	}
	std :: cout << dp[(1<<n)-1];
}
int main() {
	//freopen("1.in", "r", stdin);
	// freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}