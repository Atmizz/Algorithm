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
const int N = 2e5 + 20;
void solve() {
	int n; std :: cin >> n;
	std :: vector <int> a(n);
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i];
	std :: map <int, int> m1, m2;
	i64 ans = 0;
	for(int i = 0; i < n; ++ i) {
		int t = a[i], j = 0; ans += m1[a[i]];
		while(t % 2 == 0) {
			t /= 2; j ++;
			if(a[i] - t == j) ans += m1[t];
		}
		m1[a[i]] ++;
	}
	for(int i = n - 1; i >= 0; -- i) {
		int t = a[i], j = 0;
		while(t % 2 == 0) {
			t /= 2; j ++;
			if(a[i] - t == j) ans += m2[t];
		}
		m2[a[i]] ++;
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