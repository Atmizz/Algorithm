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
const int N = 5050;
int n, m, p;
i64 c[N][N];
i64 quickPow(i64 a, i64 b) {
	i64 sum = 1;
	while(b) {
		if(b & 1LL) {
			sum = sum * a % p;
		}
		a = a * a % p; b >>= 1LL;
	}
	return sum;
}
void solve() {
	std :: cin >> n >> m >> p;
	for(int i = 0; i <= n; i ++)
	  for(int j = 0; j <= i; j ++)
      if(!j) c[i][j] = 1;
      else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % p;
	i64 ans = 0;
	for(int i = 1; i <= n; ++ i) {
		ans = (ans + (c[n][i] * quickPow(quickPow(2, i) - 1, m - 1) % p * quickPow(quickPow(2, m - 1), n - i) % p) % p) % p;
		ans = (ans + p) % p;
	}
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