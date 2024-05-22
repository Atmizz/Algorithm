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
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> pre(n+1), a(n+1);
	std :: map <int, int> dp;
	for(int i = 1; i <= n; ++ i) std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i) {
		int x = a[i];
		if(dp[x-1] == 0 && dp[x] == 0) dp[x] = 1;
		else if(dp[x-1] + 1 > dp[x])
			dp[x] = dp[x-1] + 1;
	}
	int ans = 0, res;
	for(int i = 1; i <= n; ++ i)
		if(dp[a[i]] > ans) ans = dp[a[i]], res = a[i];
	std :: cout << ans << endl;
	std :: vector <int> A;
	for(int i = n; i >= 1; -- i)
		if(a[i] == res) {
			A.push_back(i);
			ans --; res --;
			if(ans == 0) break;
		}
	for(int i = A.size() - 1; i >= 0; -- i)
		std :: cout << A[i] << ' ';
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