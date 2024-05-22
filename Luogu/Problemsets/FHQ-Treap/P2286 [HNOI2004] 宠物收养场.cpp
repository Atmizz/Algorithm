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
const int Mod = 1e6;
const int N = 1e5 + 20;
std :: mt19937 rd(114514);
int n, rt[2], T1, T2, T3, cnt[2];
struct FHQ {
	int l, r, sz, key, val;
}fhq[2][N];
int crt(int val, int type) {
	fhq[type][++cnt[type]] = {0, 0, 1, (int) rd(), val};
	return cnt[type];
}
void pushUp(int u, int type) {
	fhq[type][u].sz = fhq[type][fhq[type][u].l].sz + fhq[type][fhq[type][u].r].sz + 1;
}
void split(int u, int val, int &x, int &y, int type) {
	if(!u) {
		x = y = 0;
		return ;
	}
	if(fhq[type][u].val > val) {
		y = u;
		split(fhq[type][u].l, val, x, fhq[type][u].l, type);
	} else {
		x = u;
		split(fhq[type][u].r, val, fhq[type][u].r, y, type);
	}
	pushUp(u, type);
}
int merge(int x, int y, int type) {
	if(!x || !y) {
		return x + y;
	}
	if(fhq[type][x].key > fhq[type][y].key) {
		fhq[type][x].r = merge(fhq[type][x].r, y, type);
		pushUp(x, type);
		return x;
	} else {
		fhq[type][y].l = merge(x, fhq[type][y].l, type);
		pushUp(y, type);
		return y;
	}
}
void insert(int val, int type) {
	split(rt[type], val, T1, T2, type);
	rt[type] = merge(merge(T1, crt(val, type), type), T2, type);
}
void erase(int val, int type) {
	split(rt[type], val, T1, T2, type);
	split(T1, val-1, T1, T3, type);
	T3 = merge(fhq[type][T3].l, fhq[type][T3].r, type);
	rt[type] = merge(merge(T1, T3, type), T2, type);
}
int queryRank(int val, int type) {
	split(rt[type], val-1, T1, T2, type);
	int res = fhq[type][T1].sz + 1;
	rt[type] = merge(T1, T2, type);
	return res;
}
int queryKth(int k, int type) {
	if(k == 0 || k == fhq[type][rt[type]].sz + 1) {
		return k == 0 ? -INF : INF;
	}
	int u = rt[type];
	while(u) {
		int tmp = fhq[type][fhq[type][u].l].sz + 1;
		if(tmp == k) {
			break;
		} else if(tmp > k) {
			u = fhq[type][u].l;
		} else {
			k -= tmp;
			u = fhq[type][u].r;
		}
	}
	return fhq[type][u].val;
}
void solve() {
	std :: cin >> n;
	int ans = 0;
	while(n --) {
		int opt, x, op;
		std :: cin >> opt >> x; op = opt^1;
		// std :: cout << x << '\n';
		// std :: cout << opt << ' ' << op << '\n';
		// deb(fhq[op][rt[op]].sz)
		if(!fhq[op][rt[op]].sz) {
			insert(x, opt);
		} else {
			insert(x, op);
			int rk = queryRank(x, op);
			int pre = queryKth(rk-1, op);
			int nxt = queryKth(rk+1, op);
			// std :: cout << rk << ' ' << pre << ' ' << nxt << '\n';
			if(nxt - x < x - pre) {
				ans = (ans + (nxt - x) % Mod) % Mod;
				erase(nxt, op);
			} else {
				ans = (ans + (x - pre) % Mod) % Mod;
				erase(pre, op);
			}
			erase(x, op);
		}
	}
	std :: cout << ans;
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