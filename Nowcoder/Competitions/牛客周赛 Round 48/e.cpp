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
void solve() {
	std :: string s;
	std :: cin >> s;
	int n = sz(s);
	s = '0' + s;
	std :: vector <int> pos[26];
	std :: vector <i64> sum[26];
	for(int i = 0; i < 26; ++ i) {
		pos[i].pb(0);
		sum[i].pb(0);
	}
	i64 ans = 0;
	for(int i = 1; i <= n; ++ i) {
		int x = s[i] - 'a';
		pos[x].pb(i);
		sum[x].pb(sum[x].back() + i);
		int res = n - i + 1;
		for(int j = 0; j < 26; ++ j) {
			if(j != x && sz(pos[j]) > 1) {
				int p = std :: upper_bound(pos[j].begin(), pos[j].end(), res) - pos[j].begin() - 1;
				ans += sum[j][p];
				ans += 1LL * res * (sz(pos[j]) - 1 - p);
			}
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