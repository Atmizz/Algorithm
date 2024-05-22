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
const int N = 1e5 + 20;
std :: mt19937 rd(114514);
struct FHQ {
	int l, r, sz, key, val;
}fhq[N];
int root, T1, T2, T3, cnt;
int crt(int v) {
	fhq[++cnt] = {0, 0, 1, (int) rd(), v};
	return cnt;
}
void pushUp(int u) {
	fhq[u].sz = fhq[fhq[u].l].sz + fhq[fhq[u].r].sz + 1;
}
void split(int u, int v, int &x, int &y) {
	if(!u) {
		x = y = 0;
		return ;
	}
	if(fhq[u].val > v) {
		y = u;
		split(fhq[u].l, v, x, fhq[u].l);
	} else {
		x = u;
		split(fhq[u].r, v, fhq[u].r, y);
	}
	pushUp(u);
}
int merge(int x, int y) {
	if(!x || !y) {
		return x + y;
	}
	if(fhq[x].key > fhq[y].key) {
		fhq[x].r = merge(fhq[x].r, y);
		pushUp(x);
		return x;
	} else {
		fhq[y].l = merge(x, fhq[y].l);
		pushUp(y);
		return y;
	}
}
void insert(int val) {
	split(root, val, T1, T2);
	root = merge(merge(T1, crt(val)), T2);
}
void erase(int val) {
	split(root, val, T1, T2);
	split(T1, val - 1, T1, T3);
	T3 = merge(fhq[T3].l, fhq[T3].r);
	root = merge(merge(T1, T3), T2);
}
int queryRank(int val) {
	split(root, val - 1, T1, T2);
	int res = fhq[T1].sz + 1;
	root = merge(T1, T2);
	return res;
}
int queryKth(int k) {
	int u = root;
	while(u) {
		int tmp = fhq[fhq[u].l].sz + 1;
		if(tmp == k) {
			break;
		} else if(tmp > k) {
			u = fhq[u].l;
		} else {
			k -= tmp;
			u = fhq[u].r;
		}
	}
	return fhq[u].val;
}
int queryPre(int u, int val) {
	if(u == 0) {
		return -INF;
	}
	if(fhq[u].val < val) {
		int res = queryPre(fhq[u].r, val);
		return res == -INF ? fhq[u].val : res;
	} else {
		return queryPre(fhq[u].l, val);
	}
}
int queryNxt(int u, int val) {
	if(u == 0) {
		return INF;
	}
	if(fhq[u].val > val) {
		int res = queryNxt(fhq[u].l, val);
		return res == INF ? fhq[u].val : res;
	} else {
		return queryNxt(fhq[u].r, val);
	}
}
void solve() {
	int n;
	std :: cin >> n;
	while(n --) {
		int opt, x;
		std :: cin >> opt >> x;
		if(opt == 1) {
			insert(x);
		} else if(opt == 2) {
			erase(x);
		} else if(opt == 3) {
			std :: cout << queryRank(x) << '\n';
		} else if(opt == 4) {
			std :: cout << queryKth(x) << '\n';
		} else if(opt == 5) {
			std :: cout << queryPre(root, x) << '\n';
		} else {
			std :: cout << queryNxt(root, x) << '\n';
		}
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	// std :: cin >> T; 
	while(T --) solve();
	return 0;
}