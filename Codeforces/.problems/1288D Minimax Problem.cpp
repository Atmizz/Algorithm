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
#define DEB std :: cout << "ok" << '\n';
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
const int N = 3e5 + 20;
int a[N][10], b[N];
void solve() {
	int n, m;
	std :: cin >> n >> m;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			std :: cin >> a[i][j];
		}
	}
	std :: vector <int> mp(1 << m);
	int s, t;
	auto check = [&](int x) -> bool {
		// deb(x)
		for(int i = 1; i <= n; ++ i) {
			b[i] = 0;
		}
		for(int i = 0; i < 1 << m; ++ i) {
			mp[i] = 0;
		}
		for(int i = 1; i <= n; ++ i) {
			for(int j = 1; j <= m; ++ j) {
				if(a[i][j] >= x) {
					b[i] |= (1 << j - 1);
				}
			}
			mp[b[i]] = i;
			// deb(b[i])
		}
		for(int i = 1; i < 1 << m; ++ i) {
			for(int j = 1; j < 1 << m; ++ j) {
				if((i | j) == (1 << m) - 1 && mp[i] != 0 && mp[j] != 0) {
					s = mp[i], t = mp[j];
					// std :: cout << "OK";
					// deb(x);
					return true;
				}
			}
		}
		return false;
	};

	int l = 0, r = 1e9, ans;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) {
			l = mid + 1;
			ans = mid;
		} else {
			r = mid - 1;
		}
	}
	check(ans);
	std :: cout << s << ' ' << t;
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