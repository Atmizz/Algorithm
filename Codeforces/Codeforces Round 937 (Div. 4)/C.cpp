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
	std :: string str;
	std :: cin >> str;
	int h = (str[0] - 48) * 10 + (str[1] - 48);
	int m = (str[3] - 48) * 10 + (str[4] - 48);
	std :: string tag[2] = {"AM", "PM"};
	int f = 0;
	if(h > 12) {
		h -= 12;
		f = 1;
	} else if(h == 0) {
		h = 12;
	} else if(h == 12) {
		f = 1;
	}
	if(h < 10) {
		std :: cout << 0;
	}
	std :: cout << h << ':';
	if(m < 10) {
		std :: cout << 0;
	}
	std :: cout << m << ' ' << tag[f] << '\n';
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