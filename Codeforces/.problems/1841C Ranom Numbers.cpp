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
	std :: string s;
	std :: cin >> s;
	int n = sz(s);
	s = '0' + s;
	i64 b[5] = {1, 10, 100, 1000, 10000}, ans = -LLINF;
	std :: vector vis(n+2, std :: vector <int> (5));
	std :: vector sum(n+1, std :: vector <i64> (5));
	for(int i = n; i >= 1; -- i) {
		vis[i][s[i]-'A'] = 1;
		for(int j = 0; j < 5; ++ j) {
			vis[i][j] += vis[i+1][j];
		}
	}
	for(int i = 1; i <= n; ++ i) {
		int a = s[i] - 'A';
		for(int j = 0; j < 5; ++ j) {
			sum[i][j] += sum[i-1][j];
		}
		sum[i][a] += b[a];
	}
	std :: vector <i64> res(5);
	for(int i = n; i >= 1; -- i) {
		for(int j = 0; j < 5; ++ j) {
			i64 tmp = 0;
			for(int k = 0; k < j; ++ k) {
				tmp += sum[i-1][k] * (-1);
			}
			for(int k = j; k < 5; ++ k) {
				i64 f = 1;
				for(int h = k + 1; h < 5; ++ h) {
					if(vis[])
				}
			}
			for(int k = 0; k < 5; ++ k) {
				tmp += res[k];
			}
			i64 f = 1;
			for(int k = j + 1; k < 5; ++ k) {
				if(vis[i+1][k]) {
					f = -1;
					break;
				}
			}
			tmp += b[j] * f;
			ans = max(ans, tmp);
		}
		int a = s[i] - 'A';
		i64 f = 1;
		for(int j = a + 1; j < 5; ++ j) {
			if(vis[i][j]) {
				f = -1;
				break;
			}
		}
		res[a] += f * b[a];
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