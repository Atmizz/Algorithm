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
const int N = 2e5 + 20;
struct KMPAlgorithm {
	int nxt[N];
	void getNxt(std :: vector <int> &s) {
		int i = 0, j = -1;
		nxt[0] = -1;
		while(i < sz(s)) {
			if(j == -1 || s[i] == s[j]) {
				++ i;
				++ j;
				nxt[i] = j;
			} else {
				j = nxt[j];
			}
		}
		// for(int i = 1; i <= sz(s); ++ i) {
		// 	std :: cout << nxt[i] << " \n"[i == sz(s)];
		// }
	}
	auto getKMP(std :: vector <int> &s1, std :: vector <int> &s2) {
		int i = 0, j = 0;
		std :: vector <int> v;
		while(i < sz(s1)) {
			// std :: cout << i << ' ' << j << nl;
			if((j == -1 || s1[i] == s2[j]) && j < sz(s2)) {
				i ++;
				j ++;
			} else {
				j = nxt[j];
			}
			if(j == (int) s2.size()) {
				v.push_back(i-j+1);
			}
		}
		return v;
	}
}KMP;
void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: vector <int> a(n+1), b(m+1);
	std :: vector <int> ca, cb;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		if(i >= 2) {
			ca.pb(a[i] - a[i-1]);
		}
	}
	for(int i = 1; i <= m; ++ i) {
		std :: cin >> b[i];
		if(i >= 2) {
			cb.pb(b[i] - b[i-1]);
		}
	}
	if(m == 1) {
		std :: cout << n;
		return ;
	}
	KMP.getNxt(cb);
	std :: vector <int> v = KMP.getKMP(ca, cb);
	std :: cout << sz(v);
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