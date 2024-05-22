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
const int N = 1e5 + 20;
struct SweepLineAlgorithm {
	int n, m, X[N<<1];
	struct sweepline {
		int l, r, h, mk;
		friend bool operator < (sweepline a, sweepline b) {
			return a.h < b.h;
		}
	}line[N<<1];
	struct SegmentTree {
		int l, r;
		i64 sum, len;
	}t[N<<4];
	void init() {
		m = 0;
	}
	inline void insert(int a, int b, int c, int d) {
		line[++m] = {a, c, b, 1}; X[m] = a;
		line[++m] = {a, c, d, -1}; X[m] = c;
	}
	void pushUp(int k) {
		if(t[k].sum) {
			t[k].len = X[t[k].r+1] - X[t[k].l];
		} else {
			t[k].len = t[ls].len + t[rs].len;
		}
	}
	void build(int l, int r, int k) {
		t[k].l = l; t[k].r = r;
		t[k].sum = t[k].len = 0;
		if(l == r) {
			return ;
		}
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid+1, r, rs);
	}
	void modify(int l, int r, int k, int x) {
		if(X[t[k].r+1] <= l || r <= X[t[k].l]) {
			return ;
		}
		if(X[t[k].l] >= l && X[t[k].r+1] <= r) {
			t[k].sum += x;
			pushUp(k);
			return ;
		}
		modify(l, r, ls, x);
		modify(l, r, rs, x);
		pushUp(k);
	}
	i64 solve() {
		std :: sort(line + 1, line + 1 + m);
		std :: sort(X + 1, X + 1 + m);
		m = std :: unique(X + 1, X + 1 + m) - X - 1;
		build(1, m-1, 1);
		i64 sum = 0;
		for(int i = 1; i < n << 1; ++ i) {
			modify(line[i].l, line[i].r, 1, line[i].mk);
			sum += 1LL * t[1].len * (line[i+1].h - line[i].h);
		}
		return sum;
	}
}SweepLine;
void solve() {
	SweepLine.init();
	std :: cin >> SweepLine.n;
	for(int i = 1; i <= SweepLine.n; ++ i) {
		int a, b, c, d;
		std :: cin >> a >> b >> c >> d;
		SweepLine.insert(a, b, c, d);
	}
	std :: cout << SweepLine.solve();
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