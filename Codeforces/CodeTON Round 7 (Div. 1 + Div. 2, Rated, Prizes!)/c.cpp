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
struct Node {
	int val, id;
	friend bool operator < (Node a, Node b) {
		return a.val < b.val;
	}
}a[N];
void solve() {
	int n, x; std :: cin >> n >> x;
	std :: vector <int> b(n);
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i].val, a[i].id = i;
	for(int i = 0; i < n; ++ i)
		std :: cin >> b[i];
	std :: sort(a, a + n);
	std :: sort(b.begin(), b.end());
	std :: vector <int> ans(n);
	for(int i = x + 1; i <= n; ++ i)
		if(b[i-1] < a[i-x-1].val) {
			std :: cout << "NO\n";
			return ;
		} else {
			// deb(a[i-x-1].id);
			ans[a[i-x-1].id] = b[i-1];
		}
	for(int i = 1; i <= x; ++ i)
		if(b[i-1] >= a[n-x+i-1].val) {
			std :: cout << "NO\n";
			return ;
		} else {
			// deb(a[n-x+i-1].id);
			ans[a[n-x+i-1].id] = b[i-1];
		}
	std :: cout << "YES\n";
	for(auto y : ans)
		std :: cout << y << ' ';
	std :: cout << '\n';
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