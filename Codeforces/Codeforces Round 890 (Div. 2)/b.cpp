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
	int n, cnt = 0; i64 sum = 0;
	std :: cin >> n;
	std :: vector <int> a(n);
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i];
	if(n == 1) {
		std :: cout << "NO\n";
		return ;
	}
	for(int i = 0; i < n; ++ i)
		if(a[i] >= 2) cnt ++, sum += a[i];
	if(sum >= n)
		std :: cout << "YES\n";
	else std :: cout << "NO\n";
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