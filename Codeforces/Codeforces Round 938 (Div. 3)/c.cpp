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
// const int N = ;
void solve() {
	int n; i64 k;
	std :: cin >> n >> k;
	std :: vector <int> a(n+1);
	i64 res = 0;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		res += a[i];
	}
	if(res <= k) {
		std :: cout << n << '\n';
		return ;
	}
	i64 sum = 0;
	int l = 1, r = n, ans = 0;
	bool ok = 0;
	while(l <= r) {
		if(!ok) {
			if(a[l] <= a[r]) {
				sum += 1LL * a[l] * 2 - 1;
				if(sum > k) {
					break;
				}
				a[r] -= (a[l] - 1);
				ans ++;
				l ++;
				ok = 1;
			} else {
				sum += 1LL * a[r] * 2;
				if(sum > k) {
					break;
				}
				a[l] -= a[r];
				r --;
				ans ++;
			}
		} else {
			if(a[l] >= a[r]) {
				sum += 1LL * a[r] * 2 - 1;
				if(sum > k) {
					break;
				}
				a[l] -= (a[r] - 1);
				ans ++;
				r --;
				ok = 0;
			} else {
				sum += 1LL * a[l] * 2;
				if(sum > k) {
					break;
				}
				a[r] -= a[l];
				l ++;
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