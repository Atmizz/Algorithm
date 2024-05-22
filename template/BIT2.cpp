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
const int N = 5050;
struct BinaryIndexTree2 {
	int n, m;
	i64 p = LLONG_MAX, a[N][N];
	int lowbit(int x) {
		return x & -x;
	}
	void add(int x, int y, i64 z) {
		for(int i = x; i <= n; i += lowbit(i)) {
			for(int j = y; j <= m; j += lowbit(j)) {
				a[i][j] = (a[i][j] + z) % p;
			}
		}
	}
	i64 sum(int x, int y) {
		i64 s = 0;
		for(int i = x; i; i -= lowbit(i)) {
			for(int j = y; j; j -= lowbit(j)) {
				s = (s + a[i][j]) % p;
			}
		}
		return s;
	}
	i64 query(int a, int b, int c, int d) {
		return (sum(c, d) - sum(a-1, d) - sum(c, b-1) + sum(a-1, b-1)) % p;
	}
}BIT2;
void solve() {
	scanf("%d%d", &BIT2.n, &BIT2.m);
	int a, b, c, d, opt;
	i64 k;
	while(~scanf("%d", &opt)) {
		if(opt == 1) {
			scanf("%d%d%lld", &a, &b, &k);
//			std :: cout << "opt1 \n";
//			std :: cout << opt << ' ' << a << ' ' << b << ' ' << k << nl;
			BIT2.add(a, b, k);
		} else {
			scanf("%d%d%d%d", &a, &b, &c, &d);
			std :: cout << BIT2.query(a, b, c, d) << nl;
		}
//		std :: cout << opt << '\n';
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
//	std :: ios :: sync_with_stdio(false);
//	std :: cin.tie(0);
//	std :: cout.tie(0);
	int _ = 1;
	//std :: cin >> _; 
	while(_ --) solve();
	return 0;
}
