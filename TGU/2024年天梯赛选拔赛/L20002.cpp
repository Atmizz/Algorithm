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
int n, rt, dep[N];
std :: string name[N];
std :: vector <int> adj[N];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		int x;
		std :: cin >> x;
		if(x == -1) {
			rt = i;
		} else {
			adj[x].push_back(i);
		}
	}
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> name[i];
	}
	std :: queue <PII> q;
	dep[rt] = 1;
	int maxx = 0;
	q.push({rt, 1});
	while(q.size()) {
		dep[q.front().first] = q.front().second;
		maxx = std :: max(maxx, q.front().second);
		for(auto v : adj[q.front().first]) {
			q.push({v, q.front().second + 1});
		}
		q.pop();
	}
	std :: cout << maxx << '\n';
	std :: vector <int> ans;
	for(int i = 1; i <= n; ++ i) {
		if(maxx == dep[i]) {
			ans.push_back(i);
		}
	}
	for(auto v : ans) {
		std :: cout << v << ' ';
	}
	std :: cout << '\n';
	for(auto v : ans) {
		std :: cout << name[v] << ' ';
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