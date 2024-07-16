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
const int N = 1e6 + 20;
struct KMPAlgorithm {
	int nxt[N];
	void getNxt(std :: string &s) {
		int i = 0, j = -1;
		nxt[0] = -1;
		while(i < (int) s.size()) {
			if(j == -1 || s[i] == s[j]) {
				++ i;
				++ j;
				nxt[i] = j;
			} else {
				j = nxt[j];
			}
		}
	}
	int getMaxNxt(std :: string &s) {
		int n = sz(s);
		return n > 0 ? nxt[n] : 0;
	}
}KMP;
void solve() {
	int n;
	std :: cin >> n;
	std :: string s[n+1];
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> s[i];
	}
	std :: string ans = "";
	for(int i = 1; i <= n; ++ i) {
		int x = min(sz(ans), sz(s[i])), len = 0;
		std :: string res = "";
		for(int j = 0; j < x; ++ j) {
			res += s[i][j];
		}
		if(x > 0) {
			res += '|';
		}
		if(sz(ans) > 0) {
			for(int j = sz(ans) - x; j < sz(ans); ++ j) {
				res += ans[j];
			}
		}
		// deb(res);
		KMP.getNxt(res);
		len = min(KMP.getMaxNxt(res), x);
		// deb(len)
		for(int j = len; j < sz(s[i]); ++ j) {
			ans += s[i][j];
		}
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