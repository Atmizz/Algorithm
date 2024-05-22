#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int n, f[N];
struct Node {
	int x, pos;
	friend bool operator < (Node a, Node b) {
		return a.x > b.x;
	}
};
int t;
void solve() {
	std :: cin >> n;
	int sum = 0, l, r, ans = -INF;
	std :: priority_queue <Node> q;
	q.push({0, 1});
	for(int i = 1; i <= n; ++ i) {
		int x; std :: cin >> x; sum += x;
		if(sum - q.top().x > ans) ans = sum - q.top().x, l = q.top().pos, r = i;
		q.push({sum, i+1});
	}
	printf("Case %d:\n%d %d %d\n\n", ++t, ans, l, r);
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