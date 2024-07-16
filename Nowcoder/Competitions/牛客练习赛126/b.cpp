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
i64 quickPow(i64 a, i64 b) {
	i64 sum = 1;
	while(b) {
		if(b & 1) {
			sum = sum * a % Mod;
		}
		a = a * a % Mod;
		b >>= 1;
	}
	return sum;
}
void solve() {
	i64 n; i64 ans = 0;
	std :: cin >> n;
	// if(n == 2) {
	// 	std :: cout << 1;
	// 	return ;
	// }
	i64 m = quickPow(2, Mod - 2);
	i64 i = (n & 1) ? n : n - 1;
	i64 j = (n & 1) ? (n - 1) : n;
	ans = (((i + 1) * ((i + 1) % Mod * m % Mod) * m % Mod - 1 + Mod) % Mod 
			+ (j + 2) * m % Mod * j * m % Mod * m % Mod + Mod) % Mod;
	ans = (ans + Mod) % Mod;
	std :: cout << ans;
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