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
	int n = sz(s), m;
	std :: cin >> m;
	std :: vector <int> a(m), cnt(26);
	for(int i = 0; i < m; ++ i) {
		std :: cin >> a[i];
	}
	for(int i = 0; i < n; ++ i) {
		cnt[s[i]-'a'] ++;
	}
	std :: string ans = std :: string(m, ' ');
	int sum = 0, pos = 25;
	for(; sum < m; ) {
		int num = 0;
		// std :: cout << sum << ' ' << m << nl;
		std :: vector <int> v;
		for(int i = 0; i < m; ++ i) {
			int res = 0;
			if(ans[i] != ' ') {
				continue ;
			}
			for(int j = 0; j < m; ++ j) {
				if(ans[j] != ' ') {
					res += abs(j - i);
				}
			}
			// std :: cout << i << ' ' << res << nl;
			if(a[i] == res) {
				num ++;
				v.pb(i);
			}
		}
		// deb(num);
		for(; pos >= 0; -- pos) {
			if(cnt[pos] >= num) {
				break;
			}
		}
		for(auto x : v) {
			// deb(pos)
			ans[x] = char(pos + 'a');
		}
		pos --;
		sum += num;
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