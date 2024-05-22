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
	std :: string a, b;
	std :: cin >> a >> b;
	int res = 0;
	for(int i = 0; i < 3; ++ i) {
		int x = (a[i] + b[i] - 96) % 3;
		if(i == 0) {
			res += x * 9;
		} else if(i == 1) {
			res += x * 3;
		} else {
			res += x;
		}
	}
	std :: cout << res / 25;
	res %= 25;
	std :: cout << res / 5;
	res %= 5;
	std :: cout << res;
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