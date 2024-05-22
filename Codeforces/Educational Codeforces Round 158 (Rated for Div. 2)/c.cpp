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
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
	int n; std :: cin >> n;
	std :: vector <int> a(n+1);
	int minn = INF, maxx = 0;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i) {
		maxx = std :: max(maxx, a[i]);
		minn = std :: min(minn, a[i]);
	}
	std :: vector <int> ans;
	while(minn != maxx) {
		maxx = (maxx + minn) >> 1;
		ans.push_back(minn);
	}
	std :: cout << ans.size() << '\n';
	if(ans.size() <= n) {
		for(auto x : ans)
			std :: cout << x << ' ';
		std :: cout << '\n';
	}
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
