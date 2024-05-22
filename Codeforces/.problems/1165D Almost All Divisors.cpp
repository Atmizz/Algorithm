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
	int n; i64 ans = -1;
	std :: cin >> n;
	std :: vector <int> a(n);
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i];
	if(n == 1) {
		ans =  (i64) a[0] * a[0];
	} else {
		std :: sort(a.begin(), a.end());
		ans = (i64) a[0] * a[n-1];
		for(int i = 1; i <= (n + 1) >> 1; ++ i) {
			i64 res = (i64) a[i] * a[n-i-1];
			if(res != ans) {
				std :: cout << -1 << endl;
				return ;
			}
		}
	}
	auto check = [&] (i64 x) -> bool {
		int j = 0;
		for(int i = 2; i <= sqrt(x); ++ i)
			if(x % i == 0) {
				if(a[j] != i || a[n-j-1] != x / i) return false;
				j ++;
			}
		return true;
	};
	if(check(ans)) std :: cout << ans << endl;
	else std :: cout << -1 << endl;
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