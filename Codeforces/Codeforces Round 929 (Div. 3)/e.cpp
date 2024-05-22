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
int n;
i64 a[N], sum[N];
i64 calc(i64 a, i64 b) {
	i64 res = 0;
	// deb(a); deb(b);
	if(b <= a) {
		res = b * (a * 2 - b + 1) / 2;
	} else {
		res = (a + 1) * a / 2;
		b -= (a + 1);
		res -= (b + 1) * b / 2;
	}
	// deb(res);
	return res;
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		sum[i] = sum[i-1] + a[i];
	}
	int q;
	std :: cin >> q;
	while(q --) {
		int l; i64 u;
		std :: cin >> l >> u;
		int pos = std :: lower_bound(sum + 1, sum + 1 + n, sum[l-1] + u) - sum;
		i64 maxx = 0, r = pos;
		for(int i = std :: max(1, pos - 1); i <= std :: min(n, pos + 1); ++ i) {

			i64 res = calc(u, sum[i] - sum[l-1]);
			if(res > maxx) {
				maxx = res;
				r = i;
			}
		}
		std :: cout << r << ' ';
	}
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