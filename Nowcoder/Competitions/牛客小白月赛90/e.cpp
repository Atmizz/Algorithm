#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
std :: mt19937 rd(114514);
int n, q, a[N], b[N];
void solve() {
	std :: cin >> n >> q;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> b[i];
	}
	while(q --) {
		int x;
		std :: cin >> x;
		i64 ans = LLINF, res = 0;
		std :: priority_queue <int, std :: vector <int>, std :: less <int> > q;
		for(int i = 1; i <= n; ++ i) {
			res += a[i];
			if(q.size() < x) {
				q.push(b[i]);
				res += b[i];
			} else if(q.top() > b[i]) {
				// deb(q.top());
				res -= q.top();
				res += b[i];
				q.pop(); q.push(b[i]);
			}
			// std :: cout << i << ' ' << res << '\n';
			if(q.size() == x) {
				ans = std :: min(ans, res);
			}
		}
		std :: cout << ans << '\n';
		// std :: cout << '\n';
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}