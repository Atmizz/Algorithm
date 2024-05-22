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
// const int N = ;
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> a(n+1);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	std :: sort(a.begin(), a.end());
	n = std :: unique(a.begin(), a.end()) - a.begin();
	// for(int i = 0; i < n; ++ i) {
	// 	std :: cout << a[i] << ' ';
	// }
	int winner = -1;
	int cnt = 0;
	for(int i = 1; i < n; ++ i) {
		if(a[i] - a[i-1] > 1) {
			if(winner == -1) {
				if(cnt % 2 == 0) {
					winner = 1;
				} else {
					winner = 0;
				}
			}
		} else {
			cnt ++;
		}
	}
	if(winner == -1) {
		winner = (n & 1) ? 0 : 1;
	}
	std :: cout << (winner == 1 ? "Alice\n" : "Bob\n");
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