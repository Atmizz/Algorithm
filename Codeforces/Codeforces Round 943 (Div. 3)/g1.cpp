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
	auto getKMP(std :: string &s1, std :: string &s2) {
		int i = 0, j = 0;
		std :: vector <int> v;
		while(i < (int) s1.size()) {
			if(j == -1 || s1[i] == s2[j]) {
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
	int n, L, R;
	std :: cin >> n >> L >> R;
	std :: string s;
	std :: cin >> s;
	auto check = [&](int x) -> bool {
		if(x == 0) {
			return true;
		}
		std :: string res = s.substr(0, x);
		KMP.getNxt(res);
		auto v = KMP.getKMP(s, res);
		int cnt = 0;
		int lst = -INF;
		for(auto y : v) {
			if(y - lst >= x) {
				cnt ++;
				lst = y;
			}
		}
		return cnt >= L;
	};
	int l = 0, r = n, ans;
	while(l <= r) {
		int mid = l + r >> 1;
		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
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