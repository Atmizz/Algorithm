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

int sum[100020][5];

void solve() {
	int n, k;
	std :: cin >> n >> k;
	std :: vector <int> a(n+1);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		for(int j = 1; j <= 4; ++ j)
			sum[i][j] = sum[i-1][j] + (a[i] == j);
	}
	int l = 4, r = n, ans;
	auto check = [&] (int x) -> bool {
		for(int i = 1; i <= n - x + 1; ++ i) {
			bool flag = 1;
			for(int j = 1; j <= 3; ++ j)
				if(sum[i+x-1][j] - sum[i-1][j] < 1) {
					flag = 0;
					break;
				}
			if(flag == 1 && sum[i+x-1][4] - sum[i-1][4] >= k) return true;
		}
		return false;
	};
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	} std :: cout << ans;
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