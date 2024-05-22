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
#define DEB std :: cout << "ok" << endl;
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
const int N = 4e4 + 20;
int n, m;
void solve() {
	std :: cin >> n >> m;
	std :: vector <int> v(m+1), p(m+1), q(m+1);
	std :: vector <int> bel[m+1];
	for(int i = 1; i <= m; ++ i) {
		std :: cin >> v[i] >> p[i] >> q[i];
		if(q[i] > 0) {
			bel[q[i]].pb(i);
		}
	}
	std :: vector <int> dp(n+1);
	for(int i = 1; i <= m; ++ i) {
		if(q[i] == 0) {
			for(int j = n; j >= 0; -- j) {
				if(j >= v[i]) {
					dp[j] = max(dp[j], dp[j-v[i]] + v[i] * p[i]);
				} else {
					break;
				}
				if(sz(bel[i]) == 1) {
					if(j >= v[i] + v[bel[i][0]]) {
						dp[j] = max(dp[j], dp[j-v[i]-v[bel[i][0]]] + v[i] * p[i] + v[bel[i][0]] * p[bel[i][0]]);
					}
				} else if(sz(bel[i]) == 2) {
					if(j >= v[i] + v[bel[i][0]]) {
						dp[j] = max(dp[j], dp[j-v[i]-v[bel[i][0]]] + v[i] * p[i] + v[bel[i][0]] * p[bel[i][0]]);
					}
					if(j >= v[i] + v[bel[i][1]]) {
						dp[j] = max(dp[j], dp[j-v[i]-v[bel[i][1]]] + v[i] * p[i] + v[bel[i][1]] * p[bel[i][1]]);
					}
					if(j >= v[i] + v[bel[i][0]] + v[bel[i][1]]) {
						dp[j] = max(dp[j], dp[j-v[i]-v[bel[i][0]]-v[bel[i][1]]] + v[i] * p[i] + v[bel[i][0]] * p[bel[i][0]] + v[bel[i][1]] * p[bel[i][1]]);
					}
				}
			}
		}
	}
	std :: cout << dp[n];
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