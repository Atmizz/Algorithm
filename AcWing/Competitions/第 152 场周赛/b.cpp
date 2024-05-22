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
const int N = 1e5 + 20;
std :: string s[N];
int n;
i64 f[N][2], c[N];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> c[i];
	}
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> s[i];
		f[i][0] = f[i][1] = LLINF;
	}
	for(int i = 1; i <= n; ++ i) {
		std :: string lsts = s[i-1], nows = s[i];
		reverse(lsts.begin(), lsts.end());
		reverse(nows.begin(), nows.end());
		if(s[i] >= s[i-1]) {
			f[i][0] = std :: min(f[i][0], f[i-1][0]);
		}
		if(s[i] >= lsts) {
			f[i][0] = std :: min(f[i][0], f[i-1][1]);
		}
		if(nows >= s[i-1]) {
			f[i][1] = std :: min(f[i][1], f[i-1][0] + c[i]);
		}
		if(nows >= lsts) {
			f[i][1] = std :: min(f[i][1], f[i-1][1] + c[i]);
		}
	}
	if(min(f[n][1], f[n][0]) == LLINF) {
		std :: cout << -1;
	} else {
		std :: cout << min(f[n][1], f[n][0]);
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