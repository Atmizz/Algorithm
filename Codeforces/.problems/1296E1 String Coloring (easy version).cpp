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
const int N = 220;
struct Node {
	char ch;
	int id, col;
	friend bool operator < (Node a, Node b) {
		return a.id < b.id;
	}
}a[N];
void solve() {
	int n;
	std :: cin >> n;
	std :: string s;
	std :: cin >> s;
	for(int i = 0; i < n; ++ i) {
		a[i+1] = {s[i], i + 1, -1};
	}
	for(int j = n; j >= 1; -- j) {
		int p = j;
		for(int i = j; i >= 1; -- i) {
			if(a[p].ch < a[i].ch) {
				p = i;
			}
		}
		// deb(p);
		if(p == j) {
			a[p].col = 0;
		} else {
			if(a[p].col == 0) {
				std :: cout << "NO\n";
				return ;
			}
			a[p].col = 1;
			for(int k = p + 1; k <= j; ++ k) {
				if(a[k].col == 1) {
					std :: cout << "NO\n";
					return ;
				}
				a[k].col = 0;
				std :: swap(a[k], a[k-1]);
			}
		}
	}
	std :: cout << "YES\n";
	std :: sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; ++ i) {
		std :: cout << a[i].col;
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