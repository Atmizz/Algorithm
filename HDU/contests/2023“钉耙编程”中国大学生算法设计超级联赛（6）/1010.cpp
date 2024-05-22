#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define int long long
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 4e5 + 20;
int n, q, k_[N>>1], b_[N>>1], p[N>>1], P[N>>1];
std :: vector <int> lst;
struct Node {
	int l, r, K, B;
}t[N<<2];
void up(int k) {
	t[k].K = (t[ls].K * t[rs].K) % Mod;
	t[k].B = ((t[ls].B * t[rs].K) % Mod + t[rs].B) % Mod;
}
void build(int l, int r, int k) {
	t[k].l = l; t[k].r = r;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(l, mid, ls); build(mid+1, r, rs);
}
void Modify(int l, int r, int k) {
	if(t[k].l >= l && t[k].r <= r) {
		if(l > n) l -= n;
		t[k].K = k_[lst[l]];
		t[k].B = b_[lst[l]];
		return ;
	}
	int mid = (t[k].l + t[k].r) >> 1;
	if(l <= mid) Modify(l, r, ls);
	if(r > mid) Modify(l, r, rs);
	up(k);
}
pi query(int l, int r, int k) {
	if(l <= t[k].l && t[k].r <= r) {
		pi temp;
		temp.first = t[k].K % Mod; temp.second = t[k].B % Mod;
		// deb(temp.first); deb(temp.second);
		return temp;
	}
	int mid = (t[k].l + t[k].r) >> 1;
	pi lson = {-1, -1}, rson = {-1, -1}, temp = {-1, -1};
	if(l <= mid) lson = query(l, r, ls);
	if(r > mid) rson = query(l, r, rs);
	if(lson == temp && rson != temp) return rson;
	if(lson != temp && rson == temp) return lson;
	if(lson != temp && rson != temp) {
		temp.first = (lson.first * rson.first) % Mod;
		temp.second = ((lson.second * rson.first) % Mod + rson.second) % Mod;
		return temp;
	} temp = {1, 0};
	return temp;
}
void dfs(int u) {
	if(lst.size() > n) return ;
	lst.push_back(u);
	P[u] = lst.size() - 1;
	dfs(p[u]);
}
i64 qmi(i64 a, i64 b) {
	i64 sum = 1ll;
	while(b) {
		if(b & 1ll) sum = sum * a % Mod;
		a = a * a % Mod; b >>= 1ll;
	} return sum % Mod;
}
void solve() {
	lst.clear(); lst.push_back(0);
	std :: cin >> n >> q;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> k_[i];
	for(int i = 1; i <= n; ++ i)
		std :: cin >> b_[i];
	for(int i = 1; i <= n; ++ i)
		std :: cin >> p[i];
	dfs(1); build(1, n << 1, 1);
  for(int i = 1; i <= n << 1; ++ i)
		Modify(i, i, 1);
  while(q --) {
		i64 x, l, y;
		std :: cin >> x >> l >> y;
		pi temp;
		if(l >= n) {
			temp = query(P[x]+1, P[x] + n, 1);
			i64 KK = qmi(temp.first % Mod, l / n) % Mod;
			i64 BB = temp.second * (((qmi(temp.first, l / n) - 1 + Mod) % Mod * (qmi((temp.first - 1 + Mod) % Mod, Mod - 2) % Mod)) % Mod) % Mod;
			y = ((KK * y) % Mod + BB) % Mod;
		} l %= n;
		if(l > 0) {
			temp = query(P[x]+1, P[x] + l, 1);
			y = ((y * temp.first) % Mod + temp.second) % Mod;
		}
		std :: cout << y % Mod << endl;
	}
}

signed main() {
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