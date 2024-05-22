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
struct Node {
	i64 val,x;
	friend bool operator < (Node a, Node b) {
		return a.val > b.val;
	}
};
void solve() {
	int n, m;
	std :: cin >> n >> m;
	std :: vector <i64> a;
	std :: vector <int> b;
	std :: map <i64, int> mp;
	a.pb(-LLINF);
	for(int i = 1; i <= n; ++ i) {
		int x;
		std :: cin >> x;
		a.pb(x);
		mp[x] = 1;
	}
	a.pb(LLINF);
	std :: sort(a.begin(), a.end());
	int cnt = 0;
	i64 ans = 0;
	std :: priority_queue <Node> q;
	for(auto x : a) {
		if(x == LLINF || x == -LLINF) {
			continue ;
		}
		if(!mp.count(x-1)) {
			q.push({1, x-1});
			mp[x-1] = 1;
		}
		if(!mp.count(x+1)) {
			q.push({1, x+1});
			mp[x+1] = 1;
		}
	}
	while(sz(q)) {
		auto [val, x] = q.top(); q.pop();
		cnt ++;
		ans += val;
		b.pb(x);
		if(cnt == m) {
			break;
		}
		if(!mp.count(x-1)) {
			auto pos = std :: lower_bound(a.begin(), a.end(), x - 1);
			q.push({min(x-1-*(pos-1), *pos-x+1), x - 1});
			mp[x-1] = 1;
		}
		if(!mp.count(x+1)) {
			auto pos = std :: lower_bound(a.begin(), a.end(), x + 1);
			q.push({min(x+1-*(pos-1), *pos-x-1), x + 1});
			mp[x+1] = 1;
		}
	}
	std :: cout << ans << nl;
	for(auto &x : b) {
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