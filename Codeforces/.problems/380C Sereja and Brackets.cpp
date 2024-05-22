#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e6 + 200;
struct Node { 
	int l, r;
	int sum, sl, sr;
}t[N<<2];
std :: string str;
void pushUp(Node &k, Node &L, Node &R) {
	int res = std :: min(L.sl, R.sr);
	k.sum = L.sum + R.sum + res * 2;
	k.sl = L.sl + R.sl - res;
	k.sr = L.sr + R.sr - res;
	// deb(k.sum);
}
void build(int l, int r, int k) {
	t[k] = {l, r, 0, 0, 0};
	if(l == r) {
		t[k].sl = str[l-1] == '(';
		t[k].sr = str[l-1] == ')';
		return ;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls); build(mid+1, r, rs);
	pushUp(t[k], t[ls], t[rs]);
}
Node query(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) return t[k];
	int mid = (t[k].l + t[k].r) >> 1;
	Node s = {0}, L = {0}, R = {0};
	if(l <= mid) L = query(l, r, ls);
	if(r > mid) R = query(l, r, rs);
	pushUp(s, L, R);
	return s;
}
void solve() {
	std :: cin >> str;
	int n, len = str.length();
	std :: cin >> n;
	build(1, len, 1);
	for(int i = 1; i <= n; ++ i) {
		int l, r; std :: cin >> l >> r;
		Node s = query(l, r, 1);
		std :: cout << s.sum << endl;
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