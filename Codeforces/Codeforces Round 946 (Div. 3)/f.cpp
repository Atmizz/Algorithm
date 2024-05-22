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
const int N = 2e5 + 20;
struct Pointa {
	int x, y;
	friend bool operator < (Pointa a, Pointa b) {
		return a.x == b.x ? a.y < b.y : a.x < b.x;
	}
}a[N];
struct Pointb {
	int x, y;
	friend bool operator < (Pointb a, Pointb b) {
		return a.y == b.y ? a.x < b.x : a.y < b.y;
	}
}b[N];
void solve() {
	int n, m, w, h;
	std :: cin >> w >> h >> n >> m;
	std :: vector <int> X, Y;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i].x >> a[i].y;
		b[i].x = a[i].x;
		b[i].y = a[i].y;
	}
	std :: sort(a + 1, a + 1 + n);
	std :: sort(b + 1, b + 1 + n);
	int stx = 1, sty = 1, edx = w, edy = h;
	int pstx = 1, pedx = n, psty = 1, pedy = n;
	int ans[2] = {0};
	std :: map <PII, bool> mp;
	for(int _ = 0; _ < m; ++ _) {
		int cnt = 0;
		char ch; int x;
		std :: cin >> ch >> x;
		// std :: cout << ch << ' ' << x << nl;
		if(ch == 'U') {
			int resx = stx + x - 1;
			int pos = std :: lower_bound(a + 1, a + 1 + n, (Pointa){resx+1, 0}) - a - 1;
			for(int i = pstx; i <= pos; ++ i) {
				// std :: cout << a[i].x << ' ' << a[i].y << nl;
				if(!mp.count({a[i].x, a[i].y})) {
					ans[_&1] ++;
					mp[{a[i].x, a[i].y}] = 1;
				}
			}
			pstx = pos + 1;
			stx = resx + 1;
		}
		 else if(ch == 'D') {
			int resx = edx - x + 1;
			int pos = std :: lower_bound(a + 1, a + 1 + n, (Pointa){resx, 0}) - a;
			for(int i = pedx; i >= pos; -- i) {
				if(!mp.count({a[i].x, a[i].y})) {
					ans[_&1] ++;
					mp[{a[i].x, a[i].y}] = 1;
				}
			}
			pedx = pos - 1;
			edx = resx - 1;
		} else if(ch == 'L') {
			int resy = sty + x - 1;
			int pos = std :: lower_bound(b + 1, b + 1 + n, (Pointb){0, resy+1}) - b - 1;
			for(int i = psty; i <= pos; ++ i) {
				if(!mp.count({b[i].x, b[i].y})) {
					ans[_&1] ++;
					mp[{b[i].x, b[i].y}] = 1;
				}
			}
			psty = pos + 1;
			sty = resy + 1;
		} else {
			int resy = edy - x + 1;
			int pos = std :: lower_bound(b + 1, b + 1 + n, (Pointb){0, resy}) - b;
			for(int i = pedy; i >= pos; -- i) {
				if(!mp.count({b[i].x, b[i].y})) {
					ans[_&1] ++;
					mp[{b[i].x, b[i].y}] = 1;
				}
			}
			pedy = pos - 1;
			edy = resy - 1;
		}
	}
	std :: cout << ans[0] << ' ' << ans[1] << nl;
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