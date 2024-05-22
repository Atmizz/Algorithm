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
const int N = 2e5 + 20;
const int M = 1e5;
int n, a[N];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	std :: map <int, int> cnt;
	for(int i = 1; i <= n; ++ i) {
		cnt[a[i]] ++;
	}
	int x = -1;
	for(int i = 0; i <= M; ++ i) {
		if(cnt[i] == 0) {
			x = i;
			break;
		}
	}
	if(x == -1) {
		std :: cout << -1 << '\n';
		return ;
	}
	cnt.clear();
	int m = x, r = -1;
	for(int i = 1; i <= n; ++ i) {
		if(a[i] < x && !cnt[a[i]]) {
			m --;
			cnt[a[i]] = 1;
		}
		if(m == 0) {
			r = i;
			break;
		}
	}
	// deb(r);
	for(int i = r + 1; i <= n; ++ i) {
		if(a[i] < x && cnt[a[i]]) {
			m ++;
			cnt[a[i]] = 0;
		}
	}
	if(m == x) {
		std :: cout << 2 << '\n' << 1 << ' ' << r << '\n' << r + 1 << ' ' << n << '\n';
	} else {
		std :: cout << -1 << '\n';
	}
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