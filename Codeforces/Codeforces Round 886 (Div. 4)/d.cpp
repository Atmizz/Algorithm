#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

void solve() {
	int n, k, ans = 1;
	std :: cin >> n >> k;
	std :: vector <int> a(n), f(n);
	for(int i = 0; i < n; ++ i) std :: cin >> a[i];
	std :: sort(a.begin(), a.end());
	f[0] = 1;
	for(int i = 1; i < n; ++ i) {
		f[i] = 1;
		if(a[i] - a[i-1] <= k) f[i] = f[i-1] + 1;
		ans = std :: max(ans, f[i]);
	}
	std :: cout << n - ans << endl;
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}