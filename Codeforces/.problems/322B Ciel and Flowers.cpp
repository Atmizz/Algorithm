#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
	int r, g, b;
	std :: cin >> r >> g >> b;
	int R = r % 3, G = g % 3, B = b % 3;
	int cnt0 = ((R == 0) && (r > 0)) + ((G == 0) && (g > 0)) + ((B == 0) && (b > 0));
	int cnt2 = (R == 2) + (G == 2) + (B == 2);
	int ans = (r / 3) + (g / 3) + (b / 3)
		+ std :: min(r % 3, std :: min(g % 3, b % 3));
	// deb(cnt0);
	if(cnt0 + cnt2 == 3 && cnt0 > 0 && cnt2 > 0) ans = ans - cnt0 + 2;
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