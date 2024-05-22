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
int n, a[N], dep[N];
void solve() {
	std :: cin >> n; int k = 2;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	std :: queue <int> q;
	q.push(a[1]);
	while(q.size()) {
		int u = q.front(); q.pop();
		if(k <= n) {
			dep[a[k]] = dep[u] + 1;
			q.push(a[k]);
			k ++;
		}
		for(; k <= n; ++ k) {
			if(a[k] > a[k-1]) dep[a[k]] = dep[u] + 1, q.push(a[k]);
			else break;
		}
	}
	std :: cout << dep[a[n]] << endl;
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
