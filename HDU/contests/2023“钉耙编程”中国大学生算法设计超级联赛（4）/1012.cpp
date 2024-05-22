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

void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> x(n), y(n);
	std :: vector < std :: array<int, 3> > a(n), b(n);
	for(int i = 0; i < n; ++ i) {
		std :: cin >> x[i] >> y[i];
		a[i] = {x[i], y[i], i}; b[i] = {y[i], x[i], i};
	}
	std :: sort(a.begin(), a.end());
	std :: sort(b.begin(), b.end());
	std :: map <int, bool> vis;
	int ans = 0;
	int i = n - 1, j = n - 1, flag = 1;
	for(int _ = 1; _ <= n; ++ _){
		while(vis[i]) i --;
		while(vis[j]) j --;
		if(flag == 1) {
			if(a[i][0] > b[j][0]) vis[a[j][2]] = 1, ans += a[j][0];
			else vis[b[j][2]] = 1, ans += b[j][1];
		} else {
			if(a[i][0] < b[j][0]) vis[b[j][2]] = 1, ans -= b[j][0];
			else vis[a[j][2]] = 1, ans -= a[j][1];
		} flag ^= 1;
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