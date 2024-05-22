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
	i64 a, b, c;
	std :: cin >> a >> b >> c;
	i64 factCnt = 0, fakeCnt = 0;
	for(i64 i = 0; i < 60; ++ i) {
		if(c >> i & 1LL) {
			factCnt ++;
		} else {
			fakeCnt ++;
		}
	}
	auto ans = [&](i64 x, i64 y, i64 z) -> void {
		i64 ax = 0, ay = 0;
		for(i64 i = 0; i < 60; ++ i) {
			if(c >> i & 1LL) {
				if(x) {
					ax += (1LL << i);
					x --;
				} else if(y) {
					ay += (1LL << i);
					y --;
				}
			} else if(z) {
				ax += (1LL << i);
				ay += (1LL << i);
				z --;
			}
		}
		std :: cout << ax << ' ' << ay;
	};
	for(i64 i = 0; i <= std :: min(a, factCnt); ++ i) {
		if(a - i == b - factCnt + i && a - i <= fakeCnt) {
			ans(i, factCnt - i, a - i);
			return ;
		}
	}
	std :: cout << "-1";
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