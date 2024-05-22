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
	i64 n;
	std :: cin >> n;
	if(n == 1) {
		std :: cout << 1;
		return ;
	}
	if(n == 2) {
		std :: cout << 2;
		return ;
	}
	if(n & 1) std :: cout << n * (n - 1) * (n - 2);
	else if(n % 3 == 0) std :: cout << (n - 1) * (n - 2) * (n - 3);
	else std :: cout << n * (n - 1) * (n - 3);
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