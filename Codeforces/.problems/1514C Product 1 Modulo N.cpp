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

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

void solve() {
	int n; i64 res = 1;
	std :: cin >> n;
	std :: vector <int> ans;
	for(int i = 1; i <= n; ++ i)
		if(gcd(n, i) == 1) res = res * i % n, ans.push_back(i);
	if(res == 1) {
		std :: cout << ans.size() << endl;
		for(auto x : ans)
			std :: cout << x << ' ';
	} else {
		std :: cout << ans.size() - 1 << endl;
		for(auto x : ans)
			if(x != res) std :: cout << x << ' ';
	}
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