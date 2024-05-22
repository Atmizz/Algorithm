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
struct Node {
	i64 minn;
	i64 lz;
	int l, r;
}t[N<<2];
int n, m, a[N];
void pushUp(int k) {
	t[k].minn = min(t[ls].minn, t[rs].minn);
}
void pushDown(int k) {
	if(t[k].lz != 0) {
		t[ls].lz += t[k].lz;
		t[rs].lz += t[k].lz;
		t[ls].minn += t[k].lz;
		t[rs].minn += t[k].lz;
		t[k].lz = 0;
	}
}
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	if(l == r) {
		t[k].minn = a[l];
		return ;
	}
	int mid = l + r >> 1;
	build(l, mid, ls);
	build(mid+1, r, rs);
	pushUp(k);
}
void modify(int l, int r, int k, int x) {
	if(t[k].l >= l && t[k].r <= r) {
		t[k].lz += x;
		t[k].minn += x;
		return ;
	}
	pushDown(k);
	int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) {
		modify(l, r, ls, x);
	}
	if(r > mid) {
		modify(l, r, rs, x);
	}
	pushUp(k);
}
i64 query(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) {
		return t[k].minn;
	}
	pushDown(k);
	int mid = (t[k].l + t[k].r) >> 1;
	i64 minn = LLONG_MAX;
	if(l <= mid) {
		minn = min(minn, query(l, r, ls));
	}
	if(r > mid) {
		minn = min(minn, query(l, r, rs));
	}
	return minn;
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	build(1, n, 1);
	std :: cin >> m;
	m ++;
	while(m --) {
		int l = 0, r = 0, v = 0;
		std :: string str;
		getline(std :: cin, str);
		if(sz(str) == 0) {
			continue ;
		}
		// deb(str);
		int i = 0;
		for(; i < sz(str); ++ i) {
			if(str[i] == ' ') {
				i ++;
				break;
			}
			l = l * 10 + str[i] - 48;
		}
		for(; i < sz(str); ++ i) {
			if(str[i] == ' ') {
				i ++;
				break;
			}
			r = r * 10 + str[i] - 48;
		}
		// std :: cout << l << ' ' << r << nl;
		l ++; r ++;
		// std :: cout << l << ' ' << r << nl;
		if(i == sz(str)) {
			if(l <= r) {
				std :: cout << query(l, r, 1) << nl;
			} else {
				std :: cout << min(query(1, r, 1), query(l, n, 1)) << nl;
			}
		} else {
			int f = 1;
			if(str[i] == '-') {
				f = -1;
				i ++;
			}
			for(; i < sz(str); ++ i) {
				v = v * 10 + str[i] - 48;
			}
			v *= f;
			if(l <= r) {
				modify(l, r, 1, v);
			} else {
				modify(1, r, 1, v);
				modify(l, n, 1, v);
			}
		}
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