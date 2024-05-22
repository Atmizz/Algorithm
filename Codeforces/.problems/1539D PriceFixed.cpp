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
const int N = 1e5 + 20;
int n;
struct Node {
	i64 need, least;
	friend bool operator < (Node a, Node b) {
		return a.least < b.least;
	}
}a[N];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i].need >> a[i].least;
	std :: sort(a + 1, a + 1 + n);

	i64 now = 0, ans = 0;
	for(int i = 1; i <= n; ++ i) {
		// deb(i); deb(n);
		if(now >= a[i].least) ans += a[i].need, now += a[i].need;
		else {
			while(n > i && now < a[i].least)
				now += a[n].need, ans += a[n].need * 2, a[n].need = 0, n --;
			if(now >= a[i].least) {
				ans += a[i].need;
				n ++, a[n].need = now - a[i].least, ans -= a[n].need * 2, now = a[i].least;
			} else {
				if(a[i].least >= a[i].need + now) ans += a[i].need * 2;
				else ans += (a[i].least - now) * 2 + (a[i].need + now - a[i].least);
			}
			now += a[i].need;
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