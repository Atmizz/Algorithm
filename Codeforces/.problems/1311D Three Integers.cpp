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
const int N = 2e4 + 20;
std :: vector <int> dvd[N];
void prepare() {
	for(int _ = 1; _ <= N - 20; ++ _) {
		for(int i = 1; i <= sqrt(_); ++ i) {
			if(_ % i == 0) {
				dvd[_].push_back(i);
				if(i * i != _) {
					dvd[_].push_back(_ / i);
				}
			}
		}
		std :: sort(dvd[_].begin(), dvd[_].end());
	}
}
void solve() {
	int a, b, c;
	std :: cin >> a >> b >> c;
	int ans = INF, aa, ab, ac;
	for(int C = 1; C <= c << 1; ++ C) {
		for(int i = 0; i < (int) dvd[C].size(); ++ i) {
			int B = dvd[C][i];
			for(int j = 0; j <= i; ++ j) {
				int A = dvd[C][j];
				if(B % A) {
					continue ;
				}
				if(std :: abs(A - a) + std :: abs(B - b) + std :: abs(C - c) < ans) {
					ans = std :: abs(A - a) + std :: abs(B - b) + std :: abs(C - c);
					aa = A; ab = B; ac = C;
				}
			}
		}
	}
	std :: cout << ans << '\n';
	std :: cout << aa << ' ' << ab << ' ' << ac << '\n';
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1; prepare();
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}