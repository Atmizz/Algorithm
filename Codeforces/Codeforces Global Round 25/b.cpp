#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e5 + 20;
int a[N], n, k;
void solve() {
	std :: cin >> n >> k;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	int num = 0;
	for(int i = 1; i < k; ++ i) {
		num += a[k] < a[i];
	}
	int ans = 0;
	if(num == 0) {
		for(int i = 1; i <= n; ++ i) {
			ans += a[i] < a[k];
			if(a[i] > a[k]) {
				break;
			}
		}
	} else if(num == 1) {
		for(int i = 1; i < k; ++ i) {
			if(a[i] > a[k]) {
				ans = std :: max(i - 2, k - i - 1 + (i != 1));
			}
		}
	} else {
		int pos1 = -1, pos2 = -1;
		for(int i = 1; i < k; ++ i) {
			if(a[i] < a[k]) {
				continue ;
			}
			if(pos1 == -1) {
				pos1 = i;
			} else {
				pos2 = i;
				break;
			}
		}
		ans = std :: max(pos1 - 2, pos2 - pos1 - 1 + (pos1 != 1));
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