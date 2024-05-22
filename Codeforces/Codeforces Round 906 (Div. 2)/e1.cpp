#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
int n, m, k, d[N], s1[N], s2[N];
struct Line {
	int l, r;
	friend bool operator < (Line a, Line b) {
		return a.l == b.l ? a.r < b.r : a.l < b.l;
	}
}line[N];
int solution1() {
	std :: priority_queue <int> q;
	for(int i = 1; i <= m; ++ i)
		q.push(s1[line[i].r] - s1[line[i].l-1]);
	int maxx = q.top(); q.pop();
	// deb(q.top() + maxx);
	return q.top() + maxx;
}
int solution2() {
	std :: sort(line + 1, line + 1 + m);
	std :: multiset <pi> s;
	int j = 1, maxx = 0;
	for(int i = 1; i <= n; ++ i) {
		if(d[i] == 2) {
			while(j <= m && line[j].l <= i) s.insert({line[j].r, line[j].l}), ++ j;
			while(s.size() && s.begin()->first < i) s.erase(s.begin());
			int l = std :: min(s.begin()->second, s.rbegin()->second);
			int r = std :: max(s.begin()->first, s.rbegin()->first);
			int res = s1[r] - s1[l-1];
			l = std :: max(s.begin()->second, s.rbegin()->second);
			r = std :: min(s.begin()->first, s.rbegin()->first);
			res += s2[r] - s2[l-1];
			maxx = std :: max(maxx, res);
		}
	}
	// deb(maxx);
	return maxx;
}
void init() {
	for(int i = 1; i <= n; ++ i)
		d[i] = 0;
}
void solve() {
	std :: cin >> n >> m >> k;
	init(); int cnt = 0;
	for(int i = 1; i <= m; ++ i)
		std :: cin >> line[i].l >> line[i].r;
	for(int i = 1; i <= m; ++ i)
		d[line[i].l] ++, d[line[i].r+1] --;
	for(int i = 1; i <= n; ++ i)
		d[i] += d[i-1];
	for(int i = 1; i <= n; ++ i)
		cnt += (d[i] == 0);
	// for(int i = 1; i <= n; ++ i)
	// 	deb(d[i]);
	for(int i = 1; i <= n; ++ i)
		s1[i] = s1[i-1] + (d[i] == 1);
	for(int i = 1; i <= n; ++ i)
		s2[i] = s2[i-1] + (d[i] == 2);
	std :: cout << std :: max(solution1(), solution2()) + cnt << endl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}