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
const int N = 1e5 + 20;
int n, m, l[N], ans[N];
i64 sum[N];
void solve() {
	std :: cin >> n >> m;
	i64 res = 0;
	for(int i = 1; i <= m; ++ i) {
		std :: cin >> l[i];
		res += l[i];
		sum[i] = sum[i-1] + l[i];
	}
	if(res < n) {
		std :: cout << "-1";
		return ;
	}
	int lst = l[m];
	ans[m] = 1;
	for(int i = m - 1; i >= 1; -- i) {
		if(l[i] <= lst) {
			lst ++;
		} else {
			lst = l[i];
		}
	}
	if(lst > n) {
		std :: cout << "-1";
		return ;
	}
	lst = l[m];
	for(int i = m - 1; i >= 2; -- i) {
		if(l[i] <= lst) {
			lst ++;
		} else {
			lst = l[i];
		}
		ans[i] = std :: max(1LL * lst - l[i] + 1, n - sum[i-1] - l[i] + 1);
	}
	ans[1] = n - l[1] + 1;
	for(int i = 1; i <= m; ++ i) {
		std :: cout << ans[i] << " \n"[i == n];
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