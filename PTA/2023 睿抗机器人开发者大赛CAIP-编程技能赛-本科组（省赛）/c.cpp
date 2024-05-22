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
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
struct Node {
	int v, x, y;
};
Node sol1(std :: vector <int> a) {
	int x = 0, y = 1;
	int maxx = 1;
	std :: map <int, int> mp;
	for(auto x : a) {
		mp[x] ++;
	}
	for(auto [u, v] : mp) {
		maxx = max(maxx, v);
	}
	for(int i = 1; i <= 5 - maxx; ++ i) {
		y *= 6;
	}
	return {5-maxx, x, y};
}
Node sol2(std :: vector <int> a) {
	int x = 1, y = 1;
	int maxx = 1;
	std :: map <int, int> mp;
	for(auto x : a) {
		mp[x] ++;
	}
	for(auto [u, v] : mp) {
		maxx = max(maxx, v);
	}
	for(int i = 1; i <= 4 - maxx; ++ i) {
		y *= 6;
	}
	return {4-maxx, x, y};
}
void solve() {
	std :: vector <int> a(5);
	int n = 5;
	for(auto &x : a) {
		std :: cin >> x;
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