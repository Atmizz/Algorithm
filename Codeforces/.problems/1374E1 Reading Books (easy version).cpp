#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
std :: vector <i64> a, b, c;
void solve() {
	int n, k; i64 ans = 0;
	std :: cin >> n >> k;
	for(int i = 1; i <= n; ++ i) {
		int t, x, y;
		std :: cin >> t >> x >> y;
		if(x == 0 && y == 0) continue;
		if(x == 1 && y == 0) a.push_back(t);
		if(x == 0 && y == 1) b.push_back(t);
		if(x == 1 && y == 1) c.push_back(t);
	}
	std :: sort(a.begin(), a.end());
	std :: sort(b.begin(), b.end());
	for(int i = 0; i < std :: min(a.size(), b.size()); ++ i)
		c.push_back(a[i] + b[i]);
	std :: sort(c.begin(), c.end());
	if(c.size() < k) {
		std :: cout << -1;
		return ;
	}
	for(int i = 0; i < k; ++ i) ans += c[i];
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