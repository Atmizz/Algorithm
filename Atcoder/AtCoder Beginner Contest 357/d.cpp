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
const int N = 3;
int n = 2;
struct Matrix {
	i64 g[N][N];
	Matrix() {
		for(int i = 1; i <= n; ++ i) {
			for(int j = 1; j <= n; ++ j) {
				g[i][j] = 0;
			}
		}
	}
	void build() {
		for(int i = 1; i <= n; ++ i) {
			g[i][i] = 1;
		}
	}
}Mat;
Matrix operator * (Matrix a, Matrix b) {
	Matrix c;
	for(int k = 1; k <= n; ++ k) {
		for(int i = 1; i <= n; ++ i) {
			for(int j = 1; j <= n; ++ j) {
				c.g[i][j] = (c.g[i][j] + a.g[i][k] * b.g[k][j] % Mod) % Mod;
			}
		}
	}
	return c;
}
Matrix quickPow(Matrix a, i64 b) {
	Matrix sum; sum.build();
	while(b) {
		if(b & 1LL) {
			sum = sum * a;
		}
		b >>= 1LL; a = a * a;
	}
	return sum;
}
void solve() {
	i64 m;
	std :: cin >> m;
	int cnt = 0;
	i64 tmp = m;
	while(tmp) {
		tmp /= 10;
		cnt ++;
	}
	i64 res = 1;
	for(int i = 1; i <= cnt; ++ i) {
		res *= 10; res %= Mod;
	}
	Matrix a, b;
	b.g[1][1] = res; b.g[2][1] = m % Mod; b.g[1][2] = 0; b.g[2][2] = 1;
	a.g[1][1] = m % Mod; a.g[1][2] = 1;
	Matrix ans = a * quickPow(b, m - 1);
	std :: cout << ans.g[1][1] % Mod;
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