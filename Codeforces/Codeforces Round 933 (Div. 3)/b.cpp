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
int a[N];
void solve() {
	int n;
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	int pos = 1;
	while(a[pos] == 0) {
		pos ++;
	}
	while(pos <= n) {
		if(a[pos] < 0 || (a[pos] > 0 && pos >= n - 1)) {
			std :: cout << "NO\n";
			return ;
		}
		a[pos+1] -= 2 * a[pos];
		a[pos+2] -= a[pos];
		a[pos] = 0;
		pos ++;
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