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
int n, q, a[N], sum[N<<2];
inline int lowbit(int x) {
	return x & (-x);
}
void add(int x, int y) {
	for(; x <= n; x += lowbit(x))
		sum[x] += y;
}
int query(int x) {
	int res = 0;
	for(; x; x -= lowbit(x))
		res += sum[x];
	return res;
}
void solve() {
	std :: cin >> n >> q;
	memset(sum, 0, sizeof sum);
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i], add(i, a[i]);
	std :: set <int> s;
	for(int i = 1; i <= n; ++ i)
		if(a[i] == 1) s.insert(i);
	while(q --) {
		int opt, x, y;
		std :: cin >> opt >> x;
		if(opt == 1) {
			if(query(n) < x) {
				std :: cout << "NO\n";
				continue;
			}
			if((query(n) - x) % 2 == 0) {
				std :: cout << "YES\n";
				continue;
			}
			if(s.size() == 0) {
				std :: cout << "NO\n";
				continue;
			}
			int l = *s.begin(), r = *s.rbegin();
			if(std :: max(query(n) - query(l), query(r)) >= x)
				std :: cout << "YES\n";
			else std :: cout << "NO\n";
		} else {
			std :: cin >> y;
			if(a[x] == 1) s.erase(x);
			if(y == 1) s.insert(x);
			add(x, -a[x]); a[x] = y;
			add(x, a[x]);
		}
	}
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