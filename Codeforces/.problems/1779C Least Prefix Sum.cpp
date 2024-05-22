#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define int long long
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
struct Node {
	int val, pos;
	friend bool operator < (Node a, Node b) {
		return a.val < b.val;
	}
};
void solve() {
	int n, m, ans = 0; std :: cin >> n >> m;
	std :: vector <int> a(n + 1);
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];

	std :: priority_queue <Node> q;
	i64 s = 0, sum = 0;

	for(int i = 1; i <= m; ++ i) {
		s += a[i];
		q.push({a[i], i});
	}

	for(int i = 1; i < m; ++ i) {
		sum += a[i];
		if(sum >= s) continue;
		while(q.top().pos <= i) q.pop();
		while(sum < s) {
			// deb(q.top().val); deb(q.top().pos);
			s = s - q.top().val - q.top().val;
			a[q.top().pos] = - q.top().val;
			ans ++; q.pop();
		}
	}
	sum += a[m];
	std :: priority_queue <int, std :: vector <int>, std :: greater <int> > p;
	for(int i = m + 1; i <= n; ++ i) {
		sum += a[i];
		p.push(a[i]);
		if(sum >= s) continue;
		while(sum < s) {
			sum = sum - p.top() - p.top();
			ans ++; p.pop();
		}
	}
	std :: cout << ans << endl;
}
signed main() {
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