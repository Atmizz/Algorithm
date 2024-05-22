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
const int N = 1e5 + 20;
int n, a[N];
int query(int x) {
	std :: cout << "? " << x << '\n';
	std :: cout.flush();
	int y;
	std :: cin >> y;
	return y;
}
void answer(int x) {
	std :: cout << "! " << x << '\n';
	std :: cout.flush();
}
void solve() {
	std :: cin >> n;
	int l = 1, r = n, ans;
	while(l < r) {
		int mid = (l + r) >> 1;
		int res1 = query(mid);
		int res2 = query(mid+1);
		if(res1 < res2) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	answer(ans);
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