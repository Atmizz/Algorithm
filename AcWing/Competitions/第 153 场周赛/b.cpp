#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
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
const int N = 2e5 + 20;
int n, l[N], r[N], a[N<<1], c[N<<1];
void solve() {
	std :: cin >> n;
	int m = 0;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> l[i] >> r[i];
		a[++m] = l[i];
		a[++m] = r[i];
	}
	std :: sort(a + 1, a + 1 + m);
	m = std :: unique(a + 1, a + 1 + m) - a;
	int maxx = INT_MIN;
	for(int i = 1; i <= n; ++ i) {
		l[i] = std :: lower_bound(a + 1, a + 1 + m, l[i]) - a;
		r[i] = std :: lower_bound(a + 1, a + 1 + m, r[i]) - a;
		c[l[i]] ++;
		c[r[i]+1] --;
		maxx = max(maxx, r[i]);
	}
	for(int i = 1; i <= maxx; ++ i) {
		c[i] += c[i-1];
		if(c[i] > 2) {
			std :: cout << "NO";
			return;
		}
	}
	std :: cout << "YES";
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