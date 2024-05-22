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
	int n; i64 ans = 0;
	std :: cin >> n;
	std :: vector <int> a(n), sum1(n), sum2(n);
	std :: map <int, int> mp;
	for(int i = 0; i < n; ++ i) std :: cin >> a[i];
	for(int i = 0; i < n; ++ i)
		sum1[i] = i == 0 ? a[0] : sum1[i-1] + a[i];
	for(int i = n - 1; i >= 0; -- i)
		sum2[i] = i == n - 1 ? a[n-1] : sum2[i+1] + a[i];
	for(int i = n - 1; i >= 0; -- i) {
		if(sum1[i] * 3 == sum1[n-1]){
			ans += mp[sum1[i]];
			if(mp[sum1[i]] != 0 && sum1[i] == sum2[i+1]) ans --;
		}
		mp[sum2[i]] ++;
	}
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