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
const int N = 2e5 + 20;
void solve() {
	int n, a, b;
	std :: cin >> n >> a >> b;
	auto get = [&](i64 x) {
		int y = x % (a + b);
		return y == 0 ? (a + b) : y;
	};
	std :: vector <i64> d;
	d.push_back(0);
	for(int i = 0; i < n; ++ i) {
		int x;
		std :: cin >> x;
		d.push_back(get(x));
		d.push_back(a+b+get(x));
	}
	std :: sort(d.begin(), d.end());
	for(int i = 1; i <= n; ++ i) {
		// std :: cout
		if(d[i+n-1] - d[i] + 1 <= a) {
			std :: cout << "Yes";
			return ;
		}
	}
	std :: cout << "No";
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