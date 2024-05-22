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
const int N = 3e5 + 20;
int n, m, k, c[N];
struct Node {
	int a, id;
}a[N], b[N];
bool cmp1(Node a, Node b) {
	return a.a < b.a;
}
bool cmp2(Node a, Node b) {
	return a.id < b.id;
}
void solve() {
	std :: cin >> n >> m >> k;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i].a;
		a[i].id = i;
	}
	std :: sort(a + 1, a + 1 + n, cmp1);
	int per = k / m, mod = k % m, cnt = per + (mod > 0);
	for(int i = 1; i <= cnt; ++ i) {
		b[i] = a[i];
	}
	std :: sort(b + 1, b + 1 + cnt, cmp2);
	i64 ans = 0, res = 0;
	for(int i = 1; i <= cnt; ++ i) {
		if(b[i].id == a[cnt].id && mod > 0) {
			c[i] = mod;
		} else {
			c[i] = m;
		}
	}
	for(int i = 1; i <= cnt; ++ i) {
		// deb(c[i]);
		ans += 1LL * c[i] * (b[i].a + res);
		res += c[i];
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