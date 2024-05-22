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
struct Node {
	int a, b;
	friend bool operator < (Node a, Node b) {
		return a.a = b.a ? a.b > b.b : a.a < b.a;
	}
}a[N];
int n, ans, now;
void solve() {
	std :: cin >> n; ans = 0; now = 0;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i].a >> a[i].b;
	std :: sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; ++ i)
		if(now < a[i].a) ans += a[i].b, now ++;
	std :: cout << ans << endl;
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