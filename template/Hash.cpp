#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
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
const int N = 1e6 + 20;
struct Hash_Algorithm {
	ull p[N], h[N];
	ull P = 131; // 13331;
	void init(int n) {
		p[0] = 1;
		for(int i = 1; i <= n; ++ i) {
			p[i] = p[i-1] * P;
		}
	}
	void getHash(std :: string &s) {
		for(int i = 1; i <= (int) s.size(); ++ i) {
			h[i] = h[i-1] * P + (ull)s[i-1];
		}
	}
	ull get(int l, int r) {
		return h[r] - h[l-1] * p[r-l+1];
	}
	ull getOneHash(std :: string &s) {
		ull res = 0;
		for(int i = 0; i < (int) s.size(); ++ i) {
			res = res * P + (ull)s[i];
		}
		return res;
	}
}Hash;
void solve() {
	int n, ans = 1;
	std :: cin >> n;
	std :: vector <ull> a(n);
	Hash.init(2000);
	for(int i = 1; i <= n; ++ i) {
		std :: string s;
		std :: cin >> s;
		Hash.getHash(s);
		a[i-1] = Hash.get(1, (int)s.size());
	}
	std :: sort(a.begin(), a.end());
	for(int i = 1; i < n; ++ i) {
		if(a[i] != a[i-1]) {
			ans ++;
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