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
	auto check = [&](int x) {
		for(int i = 2; i <= sqrt(x); ++ i) {
			if(x % i == 0) {
				return false;
			}
		}
		return true;
	};
	if(check(n)) {
		std :: cout << 1 << '\n' << n;
	} else if(check(n-2)) {
		std :: cout << 2 << '\n' << 2 << ' ' << n-2;
	} else {
		std :: cout << 3 << '\n';
		for(int i = n; i >= 2; -- i) {
			if(check(i)) {
				for(int j = n - i - 2; j >= 2; -- j) {
					if(check(j) && check(n-i-j)) {
						std :: cout << i << ' ' << j << ' ' << n - i - j;
						return ;
					}
				}
			}
		}
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