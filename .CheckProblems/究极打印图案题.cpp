#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
	int n;
	std :: cin >> n;
	n <<= 1;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= n - i; ++ j) {
			std :: cout << ' ';
		}
		if(i <= n / 2) {
			for(int j = n - i + 1; j <= n; ++ j) {
				std :: cout << '/';
			}
			for(int j = n - i + 1; j <= n; ++ j) {
				std :: cout << '\\';
			}
		} else {
			for(int j = 1; j <= n - i + 1; ++ j) {
				std :: cout << '/';
			}
			for(int j = 1; j <= ((i - n / 2) * 2 - 1) * 2; ++ j) {
				std :: cout << '_';
			}
			for(int j = 1; j <= n - i + 1; ++ j) {
				std :: cout << '\\';
			}
		}
		std :: cout << '\n';
	}
	// std :: cout << '\n';
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