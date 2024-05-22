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
const int N = 2e5 + 20;
int n, k, a[N], cnt[N];
i64 sum[N], ans = LLINF;
void solve() {
	std :: cin >> n >> k;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	std :: sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; ++ i) {
		int res = a[i], num = 0;
		cnt[res] ++;
		if(cnt[res] == k)
			ans = std :: min(ans, sum[res]);
		while(res != 0) {
			res >>= 1; num ++;
			cnt[res] ++; sum[res] += num;
			if(cnt[res] == k) 
				ans = std :: min(ans, sum[res]);
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
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}