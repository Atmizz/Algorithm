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
i64 n, m;
void solve() {
	std :: cin >> n >> m;
	std :: vector <i64> a(n);
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i];
	if(n > m) {
		std :: cout << 0;
		return ;
	}
	i64 sum = 1;
	for(int i = 0; i < n; ++ i)
		for(int j = 0; j < i; ++ j)
			sum = sum * std :: abs(a[i] - a[j]) % m;
	std :: cout << sum;
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