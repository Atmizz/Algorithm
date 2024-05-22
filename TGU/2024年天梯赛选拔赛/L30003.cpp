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
	i64 a, b, r;
	std :: cin >> a >> b >> r;
	if(a < b) {
		std :: swap(a, b);
	}
	i64 ans = 0;
	for(i64 i = 63; i >= 0; -- i) {
		if(((a >> i) & 1) == 1 && ((b >> i) & 1) == 0 && a > b) {
			if(ans + (1LL << i) <= r) {
				ans += (1LL << i);
				a ^= (1LL << i);
			}
		} else if(((a >> i) & 1) == 0 && ((b >> i) & 1) == 1 && a < b) {
			if(ans + (1LL << i) <= r) {
				ans += (1LL << i);
				b ^= (1LL << i);
			}
		}
	}
	std :: cout << std :: abs(a - b) << '\n';
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