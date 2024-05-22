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
const int N = 2020;
int n, l, c[N];
struct msg {
	int a, b;
	friend bool operator < (msg a, msg b) {
		return a.b == b.b ? a.a < b.a : a.b < b.b;
	}
}mes[N];
void solve() {
	std :: cin >> n >> l;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> mes[i].a >> mes[i].b;
	}
	std :: sort(mes + 1, mes + 1 + n);
	int ans = 0;
	for(int i = 1; i <= n; ++ i) {
		std :: priority_queue <int> q;
		int res = 0;
		for(int j = i; j <= n; ++ j) {
			res += mes[j].a;
			q.push(mes[j].a);
			while(q.size() && res + mes[j].b - mes[i].b > l) {
				res -= q.top();
				q.pop();
			}
			ans = std :: max(ans, (int)q.size());
		}
	}
	std :: cout << ans << '\n';
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