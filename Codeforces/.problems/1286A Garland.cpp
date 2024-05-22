#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << endl;
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
	int odd = n / 2 + (n & 1);
	int even = n / 2;
	std :: vector <int> a(n+2);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		if(a[i] & 1) {
			odd --;
		} else if(a[i] != 0) {
			even --;
		}
	}
	for(int i = 1; i <= n; ++ i) {
		if(a[i] != 0) {
			a[0] = a[i] + 1;
			break;
		}
	}
	if(a[0] == 0) {
		if(n > 1) {
			std :: cout << 1 << '\n';
		} else {
			std :: cout << 0 << '\n';
		}
		return ;
	}
	for(int i = n; i >= 1; -- i) {
		if(a[i] != 0) {
			a[n+1] = a[i] + 1;
			break;
		}
	}
	int ans = 0;
	std :: vector <int> v1, v2, v3;
	for(int i = 1; i <= n; ++ i) {
		if(a[i] > 0) {
			if(a[i-1] > 0 && i > 1) {
				if((a[i] & 1) != (a[i-1] & 1)) {
					ans ++;
				}
			}
			continue ;
		}
		int j = i;
		while(a[j] == 0 && j <= n) {
			j ++;
		}
		j --;
		int cnt = j - i + 1;
		if((a[i-1] & 1) == (a[j+1] & 1)) {
			if(a[i-1] & 1) {
				v1.pb(cnt);
			} else {
				v2.pb(cnt);
			}
		} else {
			ans ++;
		}
		i = j;
	}
	std :: sort(v1.begin(), v1.end());
	std :: sort(v2.begin(), v2.end());
	for(auto x : v1) {
		if(x <= odd) {
			odd -= x;
		} else {
			ans += 2;
		}
	}
	for(auto x : v2) {
		if(x <= even) {
			even -= x;
		} else {
			ans += 2;
		}
	}
	for(int i = 1; i <= n; ++ i) {
		if(a[i] != 0) {
			if(i > 1) {
				if(odd >= i - 1 && (a[i] & 1)) {
					ans --;
					odd -= i - 1;
				}
				if(even >= i - 1 && (!(a[i] & 1))) {
					ans --;
					even -= i - 1;
				}
			}
			break;
		}
	}
	for(int i = n; i >= 1; -- i) {
		if(a[i] != 0) {
			if(i < n) {
				if(odd >= n - i && (a[i] & 1)) {
					ans --;
				}
				if(even >= n - i && (!(a[i] & 1))) {
					ans --;
				}
			}
			break;
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
	int _ = 1;
	//std :: cin >> _; 
	while(_ --) solve();
	return 0;
}