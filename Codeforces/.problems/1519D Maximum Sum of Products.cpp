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
const int N = 5010;
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <i64> a(n+1), b(n+1);
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i)
		std :: cin >> b[i];
	i64 ans = 0, temp = 0;
	for(int i = 1; i <= n; ++ i)
		ans += a[i] * b[i];
	for(int i = 1; i <= n; ++ i) {
		i64 res = 0;
		int j = i, k = i;
		while(j >= 1 && k <= n) {
			res += (a[j] - a[k]) * (b[k] - b[j]);
			temp = std :: max(temp, res);
			j --; k ++;
		}
	}
	for(int i = 1; i < n; ++ i) {
		i64 res = 0;
		int j = i, k = i + 1;
		while(j >= 1 && k <= n) {
			res += (a[j] - a[k]) * (b[k] - b[j]);
			temp = std :: max(temp, res);
			j --; k ++;
		}
	}
	std :: cout << ans + temp << endl;
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