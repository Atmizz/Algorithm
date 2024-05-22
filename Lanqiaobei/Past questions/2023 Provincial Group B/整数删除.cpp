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
// const int N = ;
struct Node {
	i64 val;
	int pos;
	friend bool operator < (Node a, Node b) {
		return a.val == b.val ? a.pos > b.pos : a.val > b.val;
	}
};
void solve() {
	int n, k;
	std :: cin >> n >> k;
	std :: vector <i64> c(n+2);
	std :: vector <int> nxt(n+2), lst(n+2);
	std :: priority_queue <Node> q;
	for(int i = 1; i <= n; ++ i) {
		int x;
		std :: cin >> x;
		q.push({x, i});
		lst[i] = i - 1;
		nxt[i] = i + 1;
	}
	int cnt = 0;
	while(q.size()) {
		auto [v, p] = q.top(); q.pop();
		if(c[p] != 0) {
			q.push({c[p]+v, p});
			c[p] = 0;
		} else {
			cnt ++;
			c[lst[p]] += v;
			c[nxt[p]] += v;
			lst[nxt[p]] = lst[p];
			nxt[lst[p]] = nxt[p];
			if(cnt == k) {
				break;
			}
		}
	}
	std :: vector < std :: pair <int, i64> > v;
	while(q.size()) {
		auto [val, p] = q.top(); q.pop();
		v.push_back({p, c[p]+val});
	}
	std :: sort(v.begin(), v.end());
	for(auto [p, val] : v) {
		std :: cout << val << ' ';
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