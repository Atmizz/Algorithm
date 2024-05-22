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
const int N = 1e5 + 20;
struct Node {
	int l, r;
	int minn, num;
	int gcd;
}t[N<<2];
int n, s[N];
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
void pushUp(int k) {
	t[k].minn = min(t[ls].minn, t[rs].minn);
	t[k].num = (t[ls].minn == t[k].minn ? t[ls].num : 0) + (t[rs].minn == t[k].minn ? t[rs].num : 0);
	t[k].gcd = gcd(t[ls].gcd, t[rs].gcd);
}
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	if(l == r) {
		t[k].minn = t[k].gcd = s[l];
		t[k].num = 1;
		return ;
	}
	int mid = l + r >> 1;
	build(l, mid, ls);
	build(mid+1, r, rs);
	pushUp(k);
}
int queryGcd(int l, int r, int k) {
	if(l <= t[k].l && t[k].r <= r) {
		return t[k].gcd;
	}
	int Gcd = -1;
	int mid = t[k].l + t[k].r >> 1;
	if(l <= mid) {
		Gcd = queryGcd(l, r, ls);
	}
	if(r > mid) {
		if(Gcd == -1) {
			Gcd = queryGcd(l, r, rs);
		} else {
			Gcd = gcd(Gcd, queryGcd(l, r, rs));
		}
	}
	return Gcd;
}
int queryNum(int l, int r, int k, int minn) {
	if(l <= t[k].l && t[k].r <= r) {
		return t[k].minn == minn ? t[k].num : 0;
	}
	int num = 0;
	int mid = t[k].l + t[k].r >> 1;
	if(l <= mid) {
		num += queryNum(l, r, ls, minn);
	}
	if(r > mid) {
		num += queryNum(l, r, rs, minn);
	}
	return num;
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> s[i];
	}
	build(1, n, 1);
	int q;
	std :: cin >> q;
	while(q --) {
		int l, r;
		std :: cin >> l >> r;
		int Gcd = queryGcd(l, r, 1);
		std :: cout << r - l + 1 - queryNum(l, r, 1, Gcd) << nl;
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