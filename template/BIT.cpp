#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << endl;
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
template <class T>
T abs(T a) {
	return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 5e5 + 20;
struct BinaryIndexTree {
	int n;
	i64 p = LLINF, a[N];
	inline int lowbit(int x) {
		return x & -x;
	}
	void add(int x, i64 z) {
		for(; x <= n; x += lowbit(x)) {
			a[x] = (a[x] + z) % p;
		}
	}
	i64 query(int x) {
		i64 sum = 0;
		for(; x; x -= lowbit(x)) {
			sum = (sum + a[x]) % p;
		}
		return sum;
	}
}BIT;
void solve() {
	int m; i64 lst = 0;
	std :: cin >> BIT.n >> m;
	for(int i = 1; i <= BIT.n; ++ i) {
		i64 x;
		std :: cin >> x;
		BIT.add(i, x - lst);
		lst = x;
	}
	while(m --) {
		int opt, x, y; i64 z;
		std :: cin >> opt >> x;
		if(opt == 1) {
			std :: cin >> y >> z;
			BIT.add(x, z); 
			BIT.add(y+1, -z);
		} else {
			std :: cout << BIT.query(x) << nl;
		}
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	//std :: cin >> _; 
	while(_ --) solve();
	return 0;
}