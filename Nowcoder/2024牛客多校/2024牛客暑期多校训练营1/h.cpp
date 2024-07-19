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
const int N = 1e5 + 20;
struct Node {
	std :: string s;
	int t, p;
	friend bool operator < (Node a, Node b) {
		return a.t == b.t ? a.p < b.p : a.t > b.t;
	}
}a[N], b[N];
void solve() {
	int n, m;
	std :: cin >> n;
	std :: map <std :: string, int> mp;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i].s >> a[i].t >> a[i].p;
		mp[a[i].s] ++;
	}
	std :: cin >> m;
	for(int i = 1; i <= m; ++ i) {
		std :: cin >> b[i].s >> b[i].t >> b[i].p;
		mp[b[i].s] ++;
	}
	std :: sort(a + 1, a + 1 + n);
	std :: sort(b + 1, b + 1 + m);
	int ans = INF;
	int cnt = 0;
	for(int i = 1; i <= n; ++ i) {
		if(a[i].s == "lzr010506") {
			break;
		}
		if(mp[a[i].s] == 1) {
			cnt ++;
		}
	}
	ans = min(ans, cnt);
	cnt = 0;
	for(int i = 1; i <= m; ++ i) {
		if(b[i].s == "lzr010506") {
			break;
		}
		if(mp[b[i].s] == 1) {
			cnt ++;
		}
	}
	ans = min(ans, cnt);
	std :: cout << ans + 1;
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