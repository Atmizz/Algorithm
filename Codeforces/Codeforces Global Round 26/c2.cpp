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
const int Mod = 998244353;
// const int N = ;
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <i64> a(n+1);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	std :: vector <i64> suf(n+2);
	for(int i = n; i >= 1; -- i) {
		suf[i] = suf[i+1] + a[i];
	}
	i64 sum = 0, maxx = 0, ans = 0;
	for(int i = 1; i <= n; ++ i) {
		sum += a[i];
		maxx = max(maxx, abs(abs(sum) + suf[i+1]));
	}
	i64 res = 1, tmp = 0;
	sum = 0;
	for(int i = 1; i <= n; ++ i) {
		sum += a[i];
		if(a[i] >= 0 && a[i-1] >= 0) {
			res = (res * 2) % Mod;
		} else {
			tmp = (tmp + res) % Mod;
			res = 1;
		}
		if(maxx == abs(abs(sum) + suf[i+1])) {
			deb(i);
			deb(maxx);
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
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}