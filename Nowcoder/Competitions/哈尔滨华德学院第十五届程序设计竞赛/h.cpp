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
const int N = 300;
struct Hash_Algorithm {
	ull p[N], h[N];
	ull P = 131; // 13331;
	void init(int n) {
		p[0] = 1;
		for(int i = 1; i <= n; ++ i) {
			p[i] = p[i-1] * P;
		}
	}
	void getHash(std :: string &s) {
		for(int i = 1; i <= (int) s.size(); ++ i) {
			h[i] = h[i-1] * P + (ull)s[i-1];
		}
	}
	ull get(int l, int r) {
		return h[r] - h[l-1] * p[r-l+1];
	}
	ull getOneHash(std :: string &s) {
		ull res = 0;
		for(int i = 0; i < (int) s.size(); ++ i) {
			res = res * P + (ull)s[i];
		}
		return res;
	}
}Hash;
void solve() {
	int n;
	Hash.init(200);
	std :: cin >> n;
	std :: vector <std :: string> s(n);
	for(auto &x : s) {
		std :: cin >> x;
	}
	std :: sort(s.begin(), s.end());
	std :: map <ull, int> dp, mp;
	for(auto &str : s) {
		Hash.getHash(str);
		mp[Hash.get(1, sz(str))] ++;
		std :: vector <ull> v;
		for(int i = 1; i < sz(str); ++ i) {
			v.pb(Hash.get(1, i));
		}
		for(int j = sz(v) - 1; j >= 0; -- j) {
			if(!dp.count(v[j])) {
				continue ;
			}
			dp[Hash.get(1, sz(str))] = max(dp[Hash.get(1, sz(str))], dp[v[j]] + mp[Hash.get(1, sz(str))]);
		}
		dp[Hash.get(1, sz(str))] = max(dp[Hash.get(1, sz(str))], mp[Hash.get(1, sz(str))]);
	}
	int ans = 0;
	for(auto &[y, x] : dp) {
		ans = max(ans, x);
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