#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
	i64 n, k;
	std :: cin >> n >> k;
	if(n < k) {
		std :: cout << "NO\n";
		return ;
	}
	if(n % k == 0) {
		std :: cout << "YES\n1\n" << n / k << '\n';
		return ;
	}
	if(n / (n - k + 1) == 1) {
		std :: cout << "YES\n2\n" << n - k + 1 << ' ' << 1 << '\n';
	} else {
		std :: cout << "NO\n";
	}
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