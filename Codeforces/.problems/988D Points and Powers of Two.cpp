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
	int ans = 0;
	std :: vector <i64> v;
	std :: vector <i64> a(n);
	std :: map <i64, int> mp;
	for(auto &x : a) {
		std :: cin >> x;
		mp[x] = 1;
	}
	std :: sort(a.begin(), a.end());
	ans = 1;
	v.pb(a[0]);
	for(int i = 0; i < n; ++ i) {
		for(int j = 0; a[i] + (1LL << j) <= a.back(); ++ j) {
			int cnt = 1;
			std :: vector <i64> u;
			u.pb(a[i]);
			if(mp.count(a[i] + (1LL << j))) {
				cnt ++;
				u.pb(a[i] + (1LL << j));
				if(mp.count(a[i] + (1LL << j + 1))) {
					cnt ++;
					u.pb(a[i] + (1LL << j + 1));
				}
			}
			if(cnt > ans) {
				ans = cnt;
				v.clear();
				for(auto &x : u) {
					v.pb(x);
				}
			}
		}
	}
	std :: cout << ans << nl;
	for(auto &x : v) {
		std :: cout << x << ' ';
	}
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