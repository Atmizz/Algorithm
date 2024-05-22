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
// const int N = ;
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> a(n);
	for(auto &x : a) {
		std :: cin >> x;
	}
	std :: vector <int> b;
	for(int i = 0; i < n; ++ i) {
		if(a[i] & 1) {
			int cnt = 1, j = i;
			while(j + 1 < n && a[j+1] & 1) {
				cnt ++;
				j ++;
			}
			b.pb(cnt);
			i = j;
		}
	}
	std :: sort(b.begin(), b.end(), [&](int x, int y){
		return x > y;
	});
	i64 ans = 1LL * n * (n + 1) / 2;
	for(auto &x : b) {
		ans -= 1LL * x * (x + 1) / 2;
	}
	// deb(ans);
	if(sz(b)) {
		i64 tmp = ans + 1LL * b[0] * (b[0] + 1) / 2;
		for(int i = 0; i < b[0]; ++ i) {
			ans = max(ans, tmp - 1LL * i * (i + 1) / 2 - 1LL * (b[0] - i - 1) * (b[0] - i) / 2);
		}
	}
	std :: cout << ans << nl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}