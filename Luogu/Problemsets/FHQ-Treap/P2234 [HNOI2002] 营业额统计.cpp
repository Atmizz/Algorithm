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
int n, root, T1, T2, cnt;
struct FHQ {
	int l, r, sz, key, val;
}fhq[N];
int crt(int val) {
	fhq[++cnt] = {0, 0, 1, (int) rd(), val};
	return cnt;
}
void pushUp(int u) {
	fhq[u].sz = fhq[fhq[u].l].sz + fhq[fhq[u].r].sz + 1;
}
void split(int u, int val, int &x, int &y) {
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
void insert(int val) {
	split(root, val, T1, T2);
	root = merge(merge(T1, crt(val)), T2);
}
int queryRank(int val) {
	split(root, val-1, T1, T2);
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
void solve() {
	int ans = 0;
	std :: cin >> n;
	insert(-INF); insert(INF);
	for(int i = 1; i <= n; ++ i) {
		int x;
		std :: cin >> x;
		insert(x);
		if(i == 1) {
			ans += x;
			continue;
		}
		int rk = queryRank(x);
		// std :: cout << i << ' ' << rk << '\n';
		// std :: cout << queryKth(rk-1) << ' ' << queryKth(rk+1) << '\n';
		ans += std :: min(std :: abs(x - queryKth(rk-1)), std :: abs(x - queryKth(rk+1)));
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