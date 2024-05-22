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
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 5050;
void solve() {
	int n, k;
	std :: string str, ans = "";
	std :: cin >> n >> k >> str;
	for(int i = 1; i <= k; ++ i)
		ans += 'z';
	for(int i = 0; i < n; ++ i) {
		int l = 0;
		while((i + 1) * (1 << l) < k) l ++;
		std :: string s = str.substr(0, i + 1);
		for(int j = 1; j <= l; ++ j)
			s = s + s;
		// deb(l); deb(s);
		ans = std :: min(ans, s.substr(0, k));
	}
	std :: cout << ans << '\n';
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