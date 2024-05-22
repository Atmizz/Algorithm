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
// const int N = ;
void solve() {
	int n;
	std :: cin >> n;
	std :: set <int> s;
	std :: map <int, int> m;
	for(int i = 1; i <= n; ++ i) {
		int x; std :: cin >> x;
		s.insert(x); m[x] ++;
	}
	int last = -1, ans = 0;
	for(auto x : s) {
		if(x > last + 1) ans += m[x];
		else if(m[x] > m[last])
			ans += m[x] - m[last];
		last = x;
	}
	std :: cout << ans << endl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}