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
void solve() {
	int n, k;
	std :: cin >> n >> k;
	std :: vector a(k+1, std :: vector <int> (n+1));
	std :: vector <int> adj[n+1], in(n+1);
	for(int i = 1; i <= k; ++ i) {
		for(int j = 1; j <= n; ++ j) {
			std :: cin >> a[i][j];
		}
		for(int j = 2; j < n; ++ j) {
			adj[a[i][j]].push_back(a[i][j+1]);
			in[a[i][j+1]] ++;
		}
	}
	std :: queue <int> q;
	for(int i = 1; i <= n; ++ i) {
		if(!in[i]) {
			q.push(i);
		}
	}
	while(q.size()) {
		int u = q.front(); q.pop();
		for(auto v : adj[u]) {
			in[v] --;
			if(in[v] == 0) {
				q.push(v);
			}
		}
	}
	for(int i = 1; i <= n; ++ i) {
		if(in[i]) {
			std :: cout << "NO\n";
			return ;
		}
	}
	std :: cout << "YES\n";
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