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
const int N = 1e5 + 20;
int n, a[N], k;
void solve() {
	std :: cin >> n >> k;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	i64 sum = 0;
	for(int i = 1; i <= n; ++ i) {
		sum += a[i];
	}
	if(sum % k == 0) {
		std :: cout << 0;
		return ;
	}
	int res = sum % k;
	int ans = 0;
	std :: sort(a + 1, a + 1 + n, [&](int a, int b) {
		return a > b;
	});
	int tmp = 0;
	for(int i = 1; i <= n; ++ i) {
		tmp += a[i];
		ans ++;
		if(tmp >= res) {
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
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}