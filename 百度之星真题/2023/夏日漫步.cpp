#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
int d[N], n, nxt[N], next[N], a[N];
std :: map <int, int> mp;
struct Node {
	int pos, step;
};
void bfs() {
	std :: queue <Node> q;
	q.push({1, 0});
	while(q.size()) {
		int u = q.front().pos, step = q.front().step; q.pop();
		if(step != d[u]) continue;
		if(u == n) break;
		if(u < n && d[u+1] > d[u] + 1) d[u+1] = d[u] + 1, q.push({u + 1, step + 1});
		if(u > 1 && d[u-1] > d[u] + 1) d[u-1] = d[u] + 1, q.push({u - 1, step + 1});
		if(nxt[u] > 0 && d[nxt[u]] > d[u] + 1) d[nxt[u]] = d[u] + 1, q.push({nxt[u], step + 1});
	}
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	for(int i = n; i >= 1; -- i)
		nxt[i] = mp[a[i]], mp[a[i]] = i;
	for(int i = 2; i <= n; ++ i)
		d[i] = INF;
	bfs();
	std :: cout << d[n];
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