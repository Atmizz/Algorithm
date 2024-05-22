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
struct Point {
	int x, y;
}p[N];
int n;
i64 ans;
bool cmpx(Point a, Point b) {
	return a.x < b.x;
}
bool cmpy(Point a, Point b) {
	return a.y < b.y;
}
void calc(std :: vector <Point> &a) {
	std :: sort(a.begin(), a.end(), cmpx);
	i64 sum = 0;
	for(int i = 0; i < sz(a); ++ i) {
		ans += (1LL * i * a[i].x - sum) / 2;
		sum += a[i].x;
	}
	sum = 0;
	std :: sort(a.begin(), a.end(), cmpy);
	for(int i = 0; i < sz(a); ++ i) {
		ans += (1LL * i * a[i].y - sum) / 2;
		sum += a[i].y;
	}
}
void solve() {
	std :: cin >> n;
	std :: vector <Point> a, b;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> p[i].x >> p[i].y;
		if((p[i].x + p[i].y) & 1) {
			a.pb({p[i].x + p[i].y, p[i].y - p[i].x});
		} else {
			b.pb({p[i].x + p[i].y, p[i].y - p[i].x});
		}
	}
	calc(a); calc(b);
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