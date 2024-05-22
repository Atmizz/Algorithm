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
const i64 Range = 1e18;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 110;
const int M = 1e5 + 20;
struct Node {
	int pos;
	i64 val;
};
int n, m, k, d;
i64 cost[N];
void solve() {
	std :: cin >> n >> m >> k >> d;
	for(int i = 1; i <= n; ++ i) {
		std :: deque <Node> q;
		q.push_back({0, 0});
		for(int j = 1; j <= m; ++ j) {
			i64 x;
			std :: cin >> x;
			while(q.size() && q.front().pos < j - d - 1) q.pop_front();
			while(q.size() && q.back().val >= x + q.front().val + 1) q.pop_back();
			if(j == m) {
				cost[i] = q.front().val + 1;
			}
			q.push_back({j, q.front().val + x + 1});
			if(j == 1) {
				q.pop_front();
			}
			
			// if(i == 2) {deb(j);
			// 					deb(x);
			// 					deb(q.front().pos);
			// 					deb(q.front().val);}
		}
	}
	for(int i = 1; i <= n; ++ i) {
		// deb(cost[i])
		cost[i] += cost[i-1];
	}
	i64 ans = Range;
	for(int i = k; i <= n; ++ i) {
		ans = std :: min(ans, cost[i] - cost[i-k]);
	}
	std :: cout << ans << '\n';
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}