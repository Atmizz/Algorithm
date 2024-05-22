#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> a(n);
	int sum = 1;
	for(int i = 1; i <= n; ++ i) sum *= n;
	std :: cout << sum << endl;
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= n; ++ j)
			for(int k = 1; k <= n; ++ k)
				 for(int h = 1; h <= n; ++ h)
				 		for(int g = 1; g <= n; ++ g)
					std :: cout << n << ' ' << i << ' ' << j << ' ' << k << ' ' << h << ' ' << g << endl;
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}