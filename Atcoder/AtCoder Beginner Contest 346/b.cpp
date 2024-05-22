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
int w, b;
void solve() {
	// wbwbwwbwbwbw
	std :: cin >> w >> b;
	std :: string str = "wbwbwwbwbwbw";
	while(str.size() < (w + b) * 2) {
		str += "wbwbwwbwbwbw";
	}
	for(int i = 0; i < str.size(); ++ i) {
		int cntw = 0, cntb = 0;
		for(int j = 0; j < w + b; ++ j) {
			if(i + j >= str.size()) {
				break;
			}
			cntw += str[i+j] == 'w';
			cntb += str[i+j] == 'b';
		}
		if(cntw == w && cntb == b) {
			std :: cout << "Yes\n";
			return ;
		}
	}
	std :: cout << "No\n";
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