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
std :: map <int, int> mp;
int p[N], a[N];
void dfs(int u, std :: vector <int> &b) {
	if(mp.count(u)) {
		return ;
	}
	mp[u] = 1;
	b.pb(u);
	dfs(p[u], b);
}
void solve() {
	int n, k, pb, ps;
	std :: cin >> n >> k >> pb >> ps;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> p[i];
	}
	for(int j = 1; j <= n; ++ j) {
		std :: cin >> a[j];
	}
	std :: vector <int> bq, sq;
	dfs(pb, bq); mp.clear();
	dfs(ps, sq); mp.clear();
	i64 reb = 0, res = 0, sum = 0;
	for(int i = 0; i < sz(bq); ++ i) {
		sum += a[bq[i]];
		if(k >= i + 1) {
			reb = max(reb, sum);
		}
		if(k > i + 1) {
			reb = max(reb, sum + 1LL * a[bq[i]] * (k - i - 1));
		}
		// deb(reb);
	}
	sum = 0;
	for(int i = 0; i < sz(sq); ++ i) {
		sum += a[sq[i]];
		if(k >= i + 1) {
			res = max(res, sum);
		}
		if(k > i + 1) {
			res = max(res, sum + 1LL * a[sq[i]] * (k - i - 1));
		}
	}
	// deb(reb);
	// deb(res);
	std :: cout << (reb > res ? "Bodya\n" : (reb < res ? "Sasha\n" : "Draw\n"));
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