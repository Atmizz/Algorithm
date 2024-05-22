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
// const int N = ;
void solve() {
	int n;
	std :: vector <int> cnt(21);
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		int x;
		std :: cin >> x;
		for(int j = 0; j <= 20; ++ j) {
			cnt[j] += x >> j & 1;
		}
	}
	i64 ans = 0;
	while(1) {
		bool flag = 0;
		i64 res = 0;
		for(int i = 0; i <= 20; ++ i) {
			if(cnt[i]) {
				res += (1 << i);
				cnt[i] --;
				flag = 1;
			}
		}
		if(!flag) {
			break;
		}
		ans += res * res;
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