#include <bits/stdc++.h>
#pragma GCC optimize(2)
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
	std :: vector <int> a(n), b(n);
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i], b[i] = a[i];
	std :: sort(b.begin(), b.end());
	for(int i = 0; i < n; ++ i)
		if(a[i] != b[i]) {
			std :: cout << "0\n";
			return ;
		}
	for(int i = 1; i < n; ++ i)
		if(a[i] == a[i-1]) {
			std :: cout << "1\n";
			return ;
		}
	int ans = INF;
	for(int i = 0; i < n - 1; ++ i)
		ans = std :: min(ans, std :: abs(a[i] - a[i+1]));
	std :: cout << (ans / 2) + 1 << '\n';
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}