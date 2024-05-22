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
int n, m, l;
struct Node {
	int val, id;
	friend bool operator < (Node a, Node b) {
		return a.val > b.val;
	}
}a[N], b[N];
std :: vector <int> res[N];
void solve() {
	std :: cin >> n >> m >> l;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i].val, a[i].id = i;
	for(int i = 1; i <= m; ++ i)
		std :: cin >> b[i].val, b[i].id = i;

	std :: sort(a + 1, a + 1 + n);
	std :: sort(b + 1, b + 1 + m);

	for(int i = 1; i <= l; ++ i) {
		int x, y; std :: cin >> x >> y;
		res[x].push_back(y);
	}
	for(int i = 1; i <= n; ++ i) {
		res[i].push_back(0);
		res[i].push_back(INF);
	}
	for(int i = 1; i <= n; ++ i)
		std :: sort(res[i].begin(), res[i].end());

	int ans = 0;
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= m; ++ j) {
			int k = a[i].id;
			int pos = std :: lower_bound(res[k].begin(), res[k].end(), b[j].id)
				- res[k].begin();
			if(res[k][pos] != b[j].id) {
				// deb(a[i].val + b[j].val);
				ans = std :: max(ans, a[i].val + b[j].val);
				break;
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
	int T = 1;
	// std :: cin >> T; 
	while(T --) solve();
	return 0;
}