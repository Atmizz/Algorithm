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
const int N = 1e5 + 20;
struct SparseTable {
	i64 st[N][21], Log[N];
	i64 gcd(i64 a, i64 b) {
		return !b ? a : gcd(b, a % b);
	}
	void init(std :: vector <i64> &v) {
		int n = v.size() - 1;
		for(int i = 1; i <= n; ++ i) {
			st[i][0] = v[i];
		}
		Log[1] = 0; Log[2] = 1;
		for(int i = 3; i <= n; ++ i) {
			Log[i] = Log[i>>1] + 1;
		}
		for(int j = 1; j <= 20; ++ j) {
			for(int i = 1; i + (1 << j) - 1 <= n; ++ i) {
				st[i][j] = min(st[i][j-1], st[i+(1<<j-1)][j-1]);
			}
		}
	}
	i64 query(int l, int r) {
		int k = Log[r-l+1];
		return min(st[l][k], st[r-(1<<k)+1][k]);
	}
}STMin;
void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: vector <i64> a(n+1);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	STMin.init(a);
	while(m --) {
		int l, r;
		std :: cin >> l >> r;
		std :: cout << STMin.query(l, r) << '\n';
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