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
	std :: vector <i64> a(n+1), s(n+1);
	i64 ans = 0, t1 = 1e15, t2 = 1e15, res = 0;
	for(int i = 1; i <= n; ++ i) std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i)
		s[i] = s[i-1] + ((i & 1) ? (-a[i]) : a[i]), ans += ((i & 1) ? a[i] : 0);
	for(int i = 0; i <= n; ++ i)
		if(i & 1) {
			t1 = std :: min(t1, s[i]);
			res = std :: max(res, s[i] - t1);
		} else {
			t2 = std :: min(t2, s[i]);
			res = std :: max(res, s[i] - t2);
		}
	std :: cout << ans + res << endl;
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