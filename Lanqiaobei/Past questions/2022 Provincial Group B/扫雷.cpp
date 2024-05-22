#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 5e4 + 20;
int n, m;
struct Node {
	int x, y;
};
i64 getDis2(Node a, Node b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
int mp[N];
void solve() {
	std :: cin >> n >> m;
	std :: map <PII, int> mp, mpr, mpR;
	for(int i = 1; i <= n; ++ i) {
		int x, y, r;
		std :: cin >> x >> y >> r;
		mp[{x, y}] ++;
		mpr[{x, y}] = std :: max(mpr[{x, y}], r);
	}
	std :: queue <Node> q;
	for(int i = 1; i <= m; ++ i) {
		int x, y, r;
		std :: cin >> x >> y >> r;
		q.push({x, y});
		mpr[{x, y}] = std :: max(mpr[{x, y}], r);
	}
	int ans = 0;
	while((int) q.size()) {
		Node node = q.front(); q.pop();
		i64 x = node.x, y = node.y, r = mpr[{x, y}];
		// std :: cout << x << ' ' << y << ' ' << r << '\n';
		for(int i = x - r; i <= x + r; ++ i) {
			for(int j = y - r; j <= y + r; ++ j) {
				if(mp.count({i, j}) && getDis2(node, (Node){i, j}) <= r * r) {
					ans += mp[{i, j}];
					mp.erase({i, j});
					q.push({i, j});
				}
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