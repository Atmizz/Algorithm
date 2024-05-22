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
const int N = 1e5 + 20;
int n;
void solve() {
	std :: cin >> n;
	int cnt = 0;
	for(int i = 1; i <= n; ++ i) {
		int x, y, z;
		std :: cin >> x >> y >> z;
		if(x >= -50 && x <= 50 && y >= -50 && y <= 50) {
			cnt ++;
		}
	}
	if(1LL * cnt * 199 * 199 <= 1LL * n * 19 * 19) {
		std :: cout << "bit-noob";
	} else {
		std :: cout << "buaa-noob";
	}
}
/*

取 -9 - 9
原 -99 - 99
则有 19 / 199 * 19 / 199

*/
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