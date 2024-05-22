#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi pair<int, int>
#define int long long
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

void solve() {
	int n;
	std :: cin >> n;
	std :: vector <i64> a(n-1);
	for(int i = 0; i < n - 1; ++ i)
		std :: cin >> a[i];
	if(a[n-2] * 2 > n * (n + 1)) {
		std :: cout << "NO\n";
		return ;
	}
	std :: map<i64, int> mp;
	if(a[n-2] * 2 < n * (n + 1)) {
		int sum = a[0]; mp[a[0]] ++;
		for(int i = 1; i < n - 1; ++ i)
			a[i] -= sum, sum += a[i], mp[a[i]] ++;
		mp[n*(n+1)/2-sum] ++;
		for(int i = 1; i <= n; ++ i)
			if(mp[i] != 1) {
				std :: cout << "NO\n";
				return ;
			}
		std :: cout << "YES\n";
		return ;
	}
	int t = -1;
	if(a[0] > n) t = a[0];
	else mp[a[0]] ++;
	for(int i = 1; i < n - 1; ++ i) {
		int x = a[i]-a[i-1];
		mp[x] ++;
		if(mp[x] == 2 || x > n) {
			if(t != -1) {
				std :: cout << "NO\n";
				return ;
			} t = x;
		}
	}
	int cnt = 0, sum = 0;
	for(int i = 1; i <= n; ++ i)
		if(mp[i] == 0) sum += i, cnt ++;
	// deb(t); deb(sum);
	if(sum == t && cnt == 2) std :: cout << "YES\n";
	else std :: cout << "NO\n";
}

signed main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}