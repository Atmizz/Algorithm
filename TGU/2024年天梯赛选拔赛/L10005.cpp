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
	double x, y, z;
	scanf("%lf %lf", &x, &y);
	z = y / (x * x);
	printf("%.6lf\n", z);
	if(z < 18.5) {
		std :: cout << "xuan";
	} else if(z >= 18.5 && z < 24) {
		std :: cout << "xiaoxuan";
	} else if(z >= 24 && z < 28) {
		std :: cout << "jiezhi";
	} else {
		std :: cout << "feizhu";
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	// std :: ios :: sync_with_stdio(false);
	// std :: cin.tie(0);
	// std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}