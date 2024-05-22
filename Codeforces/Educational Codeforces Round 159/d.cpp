#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
struct Point {
	int x = 0, y = 0;
};
Point operator + (Point a, Point b) {
	return {a.x + b.x, a.y + b.y};
}
Point operator - (Point a, Point b) {
	return {a.x - b.x, a.y - b.y};
}
bool operator < (Point a, Point b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
int n, q;
std :: string str;
void solve() {
	std :: cin >> n >> q >> str;
	std :: vector <Point> p(n+1);
	std :: map <Point, std :: vector <int> > pos;
	for(int i = 0; i < n; ++ i) {
		p[i+1] = p[i];
		if(str[i] == 'U') p[i+1].y ++;
		if(str[i] == 'D') p[i+1].y --;
		if(str[i] == 'L') p[i+1].x --;
		if(str[i] == 'R') p[i+1].x ++;
	}
	for(int i = 0; i <= n; ++ i)
		pos[p[i]].push_back(i);
	auto check = [&](Point P, int l, int r) {
		if(pos[P].empty()) return false;
		auto it = std :: lower_bound(pos[P].begin(), pos[P].end(), l);
		return it != pos[P].end() && *it <= r;
	};
	while(q --) {
		int x, y, l, r;
		std :: cin >> x >> y >> l >> r; l --;
		if(check({x, y}, 0, l) || check({x, y}, r, n) ||
			check(p[l] + p[r] - (Point){x, y}, l, r))
			std :: cout << "YES\n";
		else std :: cout << "NO\n";
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}