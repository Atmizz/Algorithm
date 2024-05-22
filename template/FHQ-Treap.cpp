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
struct FHQ_TreapAlgorithm {
	struct FHQ_Treap {
		int l, r, sz, key;
		i64 val;
	}fhq[N];
	int root, T1, T2, T3, cnt;
	void init() {
		cnt = 0;
		root = 0;
	}
	int crt(i64 val) {
		fhq[++cnt] = {0, 0, 1, (int) rd(), val};
		return cnt;
	}
	void pushUp(int k) {
		fhq[k].sz = fhq[fhq[k].l].sz + fhq[fhq[k].r].sz + 1;
	}
	void split(int u, i64 val, int &x, int &y) {
		if(!u) {
			x = y = 0;
			return ;
		}
		if(fhq[u].val > val) {
			y = u;
			split(fhq[u].l, val, x, fhq[u].l);
		} else {
			x = u;
			split(fhq[u].r, val, fhq[u].r, y);
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
	void insert(i64 val) {
		split(root, val, T1, T2);
		root = merge(merge(T1, crt(val)), T2);
	}
	void erase(i64 val) {
		split(root, val, T1, T2);
		split(T1, val-1, T1, T3);
		T3 = merge(fhq[T3].l, fhq[T3].r);
		root = merge(merge(T1, T3), T2);
	}
	int queryRank(i64 val) {
		split(root, val-1, T1, T2);
		int rk = fhq[T1].sz + 1;
		root = merge(T1, T2);
		return rk;
	}
	int queryKth(int rk) {
		int u = root;
		while(u) {
			int temp = fhq[fhq[u].l].sz + 1;
			if(temp == rk) {
				break;
			} else if(temp > rk) {
				u = fhq[u].l;
			} else {
				rk -= temp;
				u = fhq[u].r;
			}
		}
		return fhq[u].val;
	}
	i64 queryPre(int u, i64 val) {
		if(u == 0) {
			return LLONG_MIN;
		}
		if(fhq[u].val < val) {
			i64 res = queryPre(fhq[u].r, val);
			return res == LLONG_MIN ? fhq[u].val : res;
		} else {
			return queryPre(fhq[u].l, val);
		}
	}
	i64 queryNxt(int u, i64 val) {
		if(u == 0) {
			return LLONG_MAX;
		}
		if(fhq[u].val > val) {
			i64 res = queryNxt(fhq[u].l, val);
			return res == LLONG_MAX ? fhq[u].val : res;
		} else {
			return queryNxt(fhq[u].r, val);
		}
	}
}FHQ;
void solve() {
	int n;
	std :: cin >> n;
	FHQ.init();
	while(n --) {
		int opt, x;
		std :: cin >> opt >> x;
		if(opt == 1) {
			FHQ.insert(x);
		} else if(opt == 2) {
			FHQ.erase(x);
		} else if(opt == 3) {
			std :: cout << FHQ.queryRank(x) << '\n';
		} else if(opt == 4) {
			std :: cout << FHQ.queryKth(x) << '\n';
		} else if(opt == 5) {
			std :: cout << FHQ.queryPre(FHQ.root, x) << '\n';
		} else {
			std :: cout << FHQ.queryNxt(FHQ.root, x) << '\n';
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