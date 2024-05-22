#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
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
const int N = 3e6 + 20;
struct MonotoneStack {
	auto getMaxStBack(std :: vector <int> &a) {
		int n = (int) a.size() - 1;
		std :: vector <int> f(n+1);
		std :: stack <int> s;
		for(int i = n; i >= 1; -- i) {
			while((int)s.size() && a[s.top()] <= a[i]) {
				s.pop();
			}
			if(s.empty()) {
				f[i] = 0;
			} else {
				f[i] = s.top();
			}
			s.push(i);
		}
		return f;
	}
	auto getMinStBack(std :: vector <int> &a) {
		int n = (int) a.size() - 1;
		std :: vector <int> f(n+1);
		std :: stack <int> s;
		for(int i = n; i >= 1; -- i) {
			while((int)s.size() && a[s.top()] >= a[i]) {
				s.pop();
			}
			if(s.empty()) {
				f[i] = 0;
			} else {
				f[i] = s.top();
			}
			s.push(i);
		}
		return f;
	}
	auto getMaxStFront(std :: vector <int> &a) {
		int n = (int) a.size() - 1;
		std :: vector <int> f(n+1);
		std :: stack <int> s;
		for(int i = 1; i <= n; ++ i) {
			while((int)s.size() && a[s.top()] <= a[i]) {
				s.pop();
			}
			if(s.empty()) {
				f[i] = 0;
			} else {
				f[i] = s.top();
			}
			s.push(i);
		}
		return f;
	}
	auto getMinStFront(std :: vector <int> &a) {
		int n = (int) a.size() - 1;
		std :: vector <int> f(n+1);
		std :: stack <int> s;
		for(int i = 1; i <= n; ++ i) {
			while((int)s.size() && a[s.top()] >= a[i]) {
				s.pop();
			}
			if(s.empty()) {
				f[i] = 0;
			} else {
				f[i] = s.top();
			}
			s.push(i);
		}
		return f;
	}
}MS;
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> a(n+1);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	std :: vector <int> b = MS.getMaxStBack(a);
	for(int i = 1; i <= n; ++ i) {
		std :: cout << b[i] << ' ';
	}
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