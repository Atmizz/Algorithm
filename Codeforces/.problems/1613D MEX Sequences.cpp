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
const int Mod = 998244353;
const int N = 5e5 + 20;
struct Node {
	int l, r;
	int MexNum;
	i64 sum, fac;
}t[N<<2];
i64 Pow[N];
i64 mod(i64 a, i64 b) {
	return (a + b) % Mod;
}
void pushUp(int k) {
	t[k].MexNum = t[ls].MexNum + t[rs].MexNum;
	t[k].sum = t[ls].sum + t[rs].sum;
	t[k].fac = t[ls].fac * t[rs].fac % Mod;
}
void build(int l, int r, int k) {
	t[k].l = l;
	t[k].r = r;
	t[k].MexNum = 0;
	if(l == r) {
		t[k].sum = 0;
		return ;
	}
	int mid = l + r >> 1;
	build(l, mid, ls);
	build(mid+1, r, rs);
	pushUp(k);
}
void modify(int l, int r, int k, i64 x) {
	if(t[k].l >= l && t[k].r <= r) {
		t[k].sum ++;
		t[k].MexNum = 1;
		t[k].fac = t[k].sum;
		return ;
	}
	int mid = t[k].l + t[k].r >> 1;
	if(l <= mid) {
		modify(l, r, ls, x);
	}
	if(r > mid) {
		modify(l, r, rs, x);
	}
	pushUp(k);
}
i64 queryMexNum(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) {
		return t[k].MexNum;
	}
	int mid = t[k].l + t[k].r >> 1;
	int num = 0;
	if(l <= mid) {
		num += queryMexNum(l, r, ls);
	} 
	if(r > mid) {
		num += queryMexNum(l, r, rs);
	}
	return num;
}
i64 querySum(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) {
		return t[k].sum;
	}
	int mid = t[k].l + t[k].r >> 1;
	int sum = 0;
	if(l <= mid) {
		sum += querySum(l, r, ls);
	}
	if(r > mid) {
		sum += querySum(l, r, rs);
	}
	return sum;
}
i64 queryFac(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) {
		return t[k].fac;
	}
	int mid = t[k].l + t[k].r >> 1;
	i64 fac = 1;
	if(l <= mid) {
		fac = fac * queryFac(l, r, ls) % Mod;
	}
	if(r > mid) {
		fac = fac * queryFac(l, r, rs) % Mod;
	}
	return fac;
}
i64 quickMi(i64 a, i64 b) {
	i64 sum = 1;
	while(b) {
		if(b & 1) {
			sum = 1LL * sum * a % Mod;
		}
		a = 1LL * a * a % Mod; b >>= 1LL;
	}
	return sum;
}
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> a(n+1);
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
		a[i] ++;
	}
	build(1, n + 1, 1);
	i64 ans = 0;
	for(int i = 1; i <= n; ++ i) {
		modify(a[i], a[i], 1, 1);
		if(a[i] == 1) {
			ans = mod(ans, Pow[querySum(a[i], a[i], 1) - 1]);
			deb(ans);
		} else {
			// int opt = 0;
			if(queryMexNum(1, a[i]-2, 1) == a[i] - 2) {
				i64 b = querySum(1, a[i]-2, 1);
				i64 c = querySum(a[i]+1, n+1, 1);
				i64 d = querySum(a[i], a[i], 1);
				std :: cout << i << ' ' << a[i] - 2 << ' ' << b - (a[i] - 2) << ' ' << c - 1 << nl;
				ans = mod(ans, queryFac(1, a[i]-2, 1) * quickMi(2, b-(a[i]-2)) % Mod * quickMi(2, c + d - 1) % Mod * d);
				deb(ans);
				// opt ++;
			}
			if(queryMexNum(1, a[i], 1) == a[i]) {
				i64 b = querySum(1, a[i], 1);
				i64 c = querySum(a[i]+2, n+1, 1);
				std :: cout << i << ' ' << a[i] << ' ' << b - a[i] << ' ' << c << nl;
				ans = mod(ans, queryFac(1, a[i], 1) * quickMi(2, b - a[i]) % Mod * quickMi(2, c));
				deb(ans);
				// opt ++;
			}
			// if(opt == 2) {
			// 	i64 b = querySum(1, a[i]-2, 1);
			// 	i64 c = querySum(a[i], a[i], 1);
			// 	i64 d = querySum(a[i]+2, n+1, 1);
			// 	ans = mod(ans, Mod-queryFac(1, a[i]-2, 1) * quickMi(2, b-(a[i]-2)) % Mod * quickMi(2, d + c - 1) % Mod * c % Mod);
			// 	// std :: cout << i << nl;
			// 	// deb(ans);
			// }
		}
	}
	std :: cout << ans << '\n';
}
void pre() {
	Pow[0] = 1;
	for(int i = 1; i < N; ++ i) {
		Pow[i] = Pow[i-1] * 2 % Mod;
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1; pre();
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}