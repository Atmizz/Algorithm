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
const int N = 2e5 + 20;
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> a(n);
	for(auto &x : a) {
		std :: cin >> x;
	}
	std :: stack <i64> s;
	for(auto &x : a) {
		s.push(x);
		if(sz(s) <= 1) {
			continue ;
		}
		s.pop();
		int y = s.top();
		s.pop();
		s.push(y);
	  s.push(x);
		if(x != y) {
			continue ;
		} else {
			while(sz(s) >= 2) {
				int p = s.top(); s.pop();
				int q = s.top(); s.pop();
				// std :: cout << p << ' ' << q << nl;
				if(p == q) {
					s.push(p + 1);
				} else {
					s.push(q);
					s.push(p);
					break;
				}
			}
		}
	}
	std :: cout << sz(s);
	// while(sz(s)) {
	// 	std :: cout << s.top() << ' ';
	// 	s.pop();
	// }
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