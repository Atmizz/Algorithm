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
// const int N = ;
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <i64> a(n+1);
	i64 ans = 0;
	std :: vector <i64> v;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		i64 tmp = a[i];
		int cnt = 0;
		while(a[i] > 1) {
			bool ok = false;
			for(auto x : v) {
				if(x == a[i]) {
					ok = true;
					break;
				}
			}
			if(ok) {
				break;
			}
			a[i] = sqrtl(a[i] / 2 + 1);
			cnt ++;
		}
		ans += cnt;
		v.clear();
		while(tmp > 1) {
			v.push_back(tmp);
			tmp = sqrtl(tmp / 2 + 1);
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
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}