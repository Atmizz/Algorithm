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
const int N = 1e4 + 20;
int n, a[N];
int query(int l, int r) {
	std :: cout << "? " << l << ' ' << r << '\n';
	std :: cout.flush();
	int x;
	std :: cin >> x;
	return x;
}
void answer() {
	std :: cout << "! ";
	for(int i = 1; i <= n; ++ i) {
		std :: cout << a[i] << ' ';
	}
}
void solve() {
	std :: cin >> n;
	int pos = 1;
	for(int i = 2; i <= n; ++ i) {
		int res1 = query(pos, i);
		int res2 = query(i, pos);
		if(res1 > res2) {
			a[pos] = res1;
			pos = i;
		} else {
			a[i] = res2;
		}
	}
	a[pos] = n;
	answer();
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