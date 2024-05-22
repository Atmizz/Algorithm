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
	i64 l, a, b;
	std :: cin >> a >> b >> l;
	int ans = 0;
	std :: vector <i64> x, y;
	i64 r1 = 1;
	while(r1 <= l) {
		x.push_back(r1);
		r1 *= a;
	}
	i64 r2 = 1;
	while(r2 <= l) {
		y.push_back(r2);
		r2 *= b;
	}
	std :: map <i64, int> mp;
	for(auto s : x) {
		for(auto t : y) {
			if(l % (s * t) == 0 && mp[l/(s*t)] == 0) {
				mp[l/(s*t)] ++;
				ans ++;
			}
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
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}