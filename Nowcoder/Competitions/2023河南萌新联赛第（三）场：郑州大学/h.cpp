#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

void solve() {
	int n, ans = 1;
	std :: cin >> n;
 	std :: vector <int> a(n);
 	for(int i = 0; i < n; ++ i) std :: cin >> a[i];
 	std :: sort(a.begin(), a.end());
 	for(int i = 0; i < n && ans >= a[i]; ++ i)
 		ans += a[i];
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