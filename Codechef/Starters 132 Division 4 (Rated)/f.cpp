#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << '\n';
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
template <class T>
T abs(T a) {
	return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> a(n+1);
	std :: vector sum(n+1, std :: vector <int> (3));
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		sum[i][1] = sum[i-1][1];
		sum[i][2] = sum[i-1][2];
		if(a[i] <= 2) {
			sum[i][a[i]] ++;
		}
	}
	int q;
	std :: cin >> q;
	while(q --) {
		int l, r, k;
		std :: cin >> l >> r >> k;
		i64 cnt1 = sum[r][1] - sum[l-1][1];
		i64 cnt2 = sum[r][2] - sum[l-1][2];
		if(cnt1 > cnt2) {
			std :: swap(cnt1, cnt2);
		}
		// std :: cout << cnt1 << ' ' << cnt2 << nl;
		if(cnt1 + cnt2 < r - l + 1 && k > 0) {
			i64 dif = min(r - l + 1 - cnt1 - cnt2, min(cnt2 - cnt1, 1LL * k));
			// deb(dif);
			cnt1 += dif;
			k -= dif;
			if(k > 0) {
				dif = min(r - l + 1 - cnt1 - cnt2, 1LL * k);
				cnt1 += dif / 2;
				cnt2 += dif / 2 + (dif & 1);
				k -= dif;
			}
		}
		// deb(k);
		// std :: cout << cnt1 << ' ' << cnt2 << nl;
		if(k > 0) {
			i64 dif = min(1LL * k, (cnt1 + cnt2) / 2 - cnt1);
			cnt1 += dif;
			cnt2 -= dif;
		}
		std :: cout << cnt1 * cnt2 << nl;
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}