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
const int N = 400;
const i64 M = 1e18;
std :: mt19937 rd(114514);
void solve() {
	int T = 100;
	std :: cout << T << '\n';
	while(T --) {
		i64 a = (int) rd() % 1042354350, b = (int) rd() % 34553464354;
		a = (a + 142343251) % 1534534651;
		b = (b + 1453453451) % 353453453;
		if(a == 0) a = 1;
		if(b == 0) b = 1;
		std :: cout << a << "^{" << b << "}\n";
	}
}
int main() {
	//freopen("1\'in", "r", stdin);
	freopen("2.in", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
//	std :: cin >> T; 
	while(T --) solve();
	return 0;
}
