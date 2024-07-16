// LUOGU_RID: 159835386
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
	std :: string s;
	std :: cin >> s;
	int n = sz(s);
	std :: vector <int> a(n+1);
	i64 val[5] = {1, 10, 100, 1000, 10000};
	for(int i = 0; i < sz(s); ++ i) {
		a[i+1] = s[i] - 'A';
	}
	std :: vector <i64> sufSum(n+2);
	std :: vector vis(n+2, std :: vector <int> (5));
	for(int i = n; i >= 1; -- i) {
		for(int j = 0; j < 5; ++ j) {
			vis[i][j] = vis[i+1][j];
		}
		vis[i][a[i]] ++;
	}
	for(int i = n; i >= 1; -- i) {
		i64 f = 1;
		sufSum[i] = sufSum[i+1];
		for(int j = a[i] + 1; j < 5; ++ j) {
			if(vis[i][j]) {
				f = -1;
				break;
			}
		}
		sufSum[i] += f * val[a[i]];
	}
	int cnt[5] = {0};
	i64 res = 0, ans = -LLINF;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 0; j < 5; ++ j) {
			i64 tmp = res;
			cnt[j] ++;
			for(int k = 0; k < j; ++ k) {
				tmp += -1LL * val[k] * cnt[k];
			}
			for(int k = j; k < 5; ++ k) {
				i64 f = 1;
				for(int h = k + 1; h < 5; ++ h) {
					if(vis[i+1][h]) {
						f = -1;
						break;
					}
				}
				tmp += f * val[k] * cnt[k];
			}
			// std :: cout << i << ' ' << j << ' ' << tmp + sufSum[i+1] << nl;
			ans = max(ans, tmp + sufSum[i+1]);
			cnt[j] --;
		}
		for(int j = 0; j < a[i]; ++ j) {
			res += val[j] * cnt[j] * (-1);
			cnt[j] = 0;
		}
		cnt[a[i]] ++;
	}
	std :: cout << ans << nl;
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