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
// const int N =;
void solve() {
	i64 x;
	std :: cin >> x;
	if(x % 495 == 0) {
		std :: cout << -1;
		return ;
	}
	i64 res = 10;
	x %= 495;
	// deb(x);
	for(int i = 1; ; ++ i) {
		// deb(x * res);
		i64 tmp = (x * res) % 495;
		// deb(tmp);
		if(495 - tmp < res) {
			if(495 - tmp < res / 10) {
				std :: cout << 495 * 2 - tmp;
				return ;
			}
			std :: cout << 495 - tmp;
			return ;
		}
		res *= 10;
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