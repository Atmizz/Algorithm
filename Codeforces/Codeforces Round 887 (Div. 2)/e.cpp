#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

void solve() {
	int n, k;
	std :: cin >> n >> k;
	std :: vector <int> a(n);
	for(int i = 0; i < n; ++ i) std :: cin >> a[i];
	i64 ans = 0;
	for(int i = 0; i < n; ++ i) {
		if(a[i] == k) continue;
		int j = i; ans += a[j]; ++ j;
		while(a[j] != k && j < n) {
			if(a[j] > a[j-1]) ans += (a[j] - a[j-1]);
			++ j;
		}
	}
	std :: cout << ans << endl;
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