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
const int N = 2e5 + 20;
int n, v[N], p[N];
struct Node {
	int val, x;
	friend bool operator <(Node a, Node b) {
		return a.val < b.val;
	}
};
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> v[i];
	}
	for(int j = 1; j <= n; ++ j) {
		std :: cin >> p[j];
	}
	std :: map <int, int> out;
	std :: priority_queue <Node> q;
	for(int i = 1; i <= n; ++ i) {
		q.push({v[i], i});
	}
	int cntOut = 0;
	i64 ans = 0, num;
	for(int i = 0; i < n; ++ i) {
		v[p[i]] = 0;
		if(out[p[i]] == 1) {
			cntOut --;
		}
		while(q.size() && v[q.top().x] == 0) {
			q.pop();
		}
		while(q.size() && cntOut < i) {
			out[q.top().x] = 1;
			cntOut ++;
			q.pop();
			while(q.size() && v[q.top().x] == 0) {
				q.pop();
			}
		}
		if(q.empty()) {
			break;
		}
		// deb(cntOut);
		// deb(q.top().x);
		// deb(q.top().val);
		if(q.size() && ans < 1LL * (i + 1) * q.top().val) {
			ans = 1LL * (i + 1) * q.top().val;
			num = i + 1;
		}
		// deb(i);
		// deb(ans);
		// deb(q.size())
	}
	std :: cout << ans << ' ' << num << '\n';
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