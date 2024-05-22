#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
int n, a[N];
i64 sum[N];
void solve() {
	int n;
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	std :: map <i64, int> cnt;
	for(int i = 1; i <= n; ++ i)
		sum[i] = sum[i-1] + a[i];
	i64 ans = 0; int lst = 0;
	cnt[0] = 0;
	for(int i = 1; i <= n; ++ i) {
		if(cnt.count(sum[i])) lst = std :: max(lst, cnt[sum[i]] + 1);
		ans += i - lst;
		if(lst == i && a[i] != 0) ans ++;
		cnt[sum[i]] = i;
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