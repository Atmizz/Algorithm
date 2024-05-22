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
const int N = 1e5 + 20;
int sum[N][4], n, a[N], b[N];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		int x, y;
		std :: cin >> x >> y;
		if(x == y) {
			a[i] = 2;
		} else if(x > y) {
			a[i] = 1;
		} else {
			a[i] = 3;
		}
	}
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> b[i];
		b[i] = a[b[i]];
		for(int j = 1; j <= 3; ++ j) {
			sum[i][j] = sum[i-1][j];
		}
		sum[i][b[i]] ++;
	}
	int ans = INT_MAX;
	int st = 1, ed = 1;
	if(sum[n][1] + sum[n][2] + sum[n][3] - max(max(sum[n][1], sum[n][2]), sum[n][3]) == 0) {
		std :: cout << 0 << '\n';
		return ;
	}
	if(sum[n][2] > 0) {
		for(int j = 1; j <= n; ++ j) {
			if(b[j] == 2) {
				st = j;
				break;
			}
		}
		for(int j = n; j >= 1; -- j) {
			if(b[j] == 2) {
				ed = j;
				break;
			}
		}
		int res = 0;
		res += sum[st][3] + sum[n][1] - sum[ed][1];
		res += ed - st + 1 - sum[ed][2] + sum[st-1][2];
		ans = res;
		if(sum[n][1] > 0) {
			for(int i = n; i >= 1; -- i) {
				if(b[i] == 1) {
					ed = i;
					break;
				}
			}
			if(sum[ed][3] == 0) {
				ans = min(ans, sum[n][2]);
				if(sum[n][2] == sum[ed][2]) {
					ans = min(ans, sum[n][1]);
				}
			}
		} else {
			for(int i = 1; i <= n; -- i) {
				if(b[i] == 3) {
					st = i;
					break;
				}
			}
			ans = min(ans, min(sum[ed][3], sum[n][2] - sum[st][2]));
		}
	} else if(sum[n][3] > 0 && sum[n][1] > 0) {
		for(int i = 1; i <= n; ++ i) {
			if(b[i] == 3) {
				st = i;
				break;
			}
		}
		for(int i = n; i >= 1; -- i) {
			if(b[i] == 1) {
				ed = i;
				break;
			}
		}
		ans = min(sum[ed][3], sum[n][1] - sum[st][1]);
	} else {
		ans = 0;
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