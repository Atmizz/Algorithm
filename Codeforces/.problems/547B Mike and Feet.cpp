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
const int N = 2e5 + 20;
int n, a[N], lmin[N], rmin[N];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	std :: stack <int> s;
	for(int i = 1; i <= n; ++ i) {
		while(sz(s) && a[s.top()] >= a[i]) {
			s.pop();
		}
		if(s.empty()) {
			lmin[i] = 0;
		} else {
			lmin[i] = s.top();
		}
		s.push(i);
	}
	while(sz(s)) {
		s.pop();
	}
	for(int i = n; i >= 1; -- i) {
		while(sz(s) && a[s.top()] >= a[i]) {
			s.pop();
		}
		if(s.empty()) {
			rmin[i] = n + 1;
		} else {
			rmin[i] = s.top();
		}
		s.push(i);
	}
	std :: vector <int> b[n+1];
	for(int i = 1; i <= n; ++ i) {
		int len = rmin[i] - lmin[i] - 1;
		b[len].pb(a[i]);
	}
	for(int i = 1; i <= n; ++ i) {
		std :: sort(b[i].begin(), b[i].end(), [&](int a, int b) {
			return a > b;
		});
	}
	std :: vector <int> ans(n+1);
	int res = 0;
	for(int i = n; i >= 1; -- i) {
		if(b[i].empty()) {
			ans[i] = res;
			continue ;
		}
		res = max(res, b[i][0]);
		ans[i] = res;
	}
	for(int i = 1; i <= n; ++ i) {
		std :: cout << ans[i] << " ";
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