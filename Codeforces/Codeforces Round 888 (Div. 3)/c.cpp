#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

void solve() {
	int n, k;
	std :: cin >> n >> k;
	std :: vector <int> a(n);
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i];
	if(a[0] == a[n-1]) {
		int res = 0;
		for(int i = 0; i < n; ++ i)
			if(a[i] == a[0]) res ++;
		if(res >= k) {
			std :: cout << "YES\n";
			return ;
		}
	}
	int x = 0, posx, y = 0, posy;
	for(int i = 0; i < n; ++ i)
		if(a[i] == a[0]) {
			x ++;
			if(x == k) {
				posx = i;
				break;
			}
		}
	for(int i = n - 1; i > 0; -- i)
		if(a[i] == a[n-1]) {
			y ++;
			if(y == k) {
				posy = i;
				break;
			}
		}
	if(x != k || y != k || posx >= posy) {
		std :: cout << "NO\n";
		return ;
	} std :: cout << "YES\n";
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