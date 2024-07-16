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
	int n, k;
	std :: cin >> n >> k;
	std :: map <int, std :: vector <int> > mp;
	for(int i = 1; i <= n; ++ i) {
		int x;
		std :: cin >> x;
		mp[x%k].pb(x);
	}
	i64 ans = 0;
	int cnt = 0;
	for(auto &[pos, v] : mp) {
		if(sz(v) & 1) {
			cnt ++;
		}
		std :: sort(v.begin(), v.end());
		// deb(cnt);
		// for(auto &x : v) {
		// 	std :: cout << x << ' ';
		// }
		// std :: cout << nl;
	}

	if((cnt > 0 && n % 2 == 0) || (cnt > 1 && (n & 1))) {
		std :: cout << -1 << nl;
		return ;
	}

	for(auto &[pos, v] : mp) {
		int beg = 0, end = sz(v);
		i64 res;
		if((sz(v) & 1) && sz(v) > 1) {
			std :: vector sum(2, std :: vector <i64> (sz(v)));
			sum[0][0] = v[1] - v[0];
			sum[1][1] = v[2] - v[1];
			for(int i = 2; i < sz(v) - 1; ++ i) {
				sum[i&1][i] = sum[i&1][i-2] + v[i+1] - v[i];
			}
			// deb(sum[0][sz(v)-2]);
			res = min(min(sum[1][sz(v)-2]/k, sum[0][sz(v)-3]/k), (sum[1][sz(v)-2] + v[1] - v[0])/k);
			for(int i = 2; i < sz(v) - 1; ++ i) {
				if(i & 1) {
					res = min(res, (sum[0][i-1] + sum[1][sz(v)-2] - sum[1][i-2])/k);
				} else {
					res = min(res, (sum[0][i-2] + sum[1][sz(v)-2] - sum[1][i-1])/k);
				}
			}
			ans += res;
		} else {
			for(int i = beg; i + 1 < end; i += 2) {
				ans += (v[i+1] - v[i]) / k;
			}
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