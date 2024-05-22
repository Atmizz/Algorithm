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
const int N = 2e5 + 20;
int n, q;
void solve() {
	std :: cin >> n;
	std :: map <int, int> pre, nxt;
	int lst = 0;
	for(int i = 1; i <= n; ++ i) {
		int x;
		std :: cin >> x;
		pre[x] = lst;
		nxt[lst] = x;
		lst = x;
	}
	nxt[lst] = -1;
	pre[-1] = lst;
	std :: cin >> q;
	for(int i = 1; i <= q; ++ i) {
		int opt, l, r;
		std :: cin >> opt >> l;
		if(opt == 1) {
			std :: cin >> r;
			nxt[r] = nxt[l];
			pre[nxt[r]] = r;
			pre[r] = l;
			nxt[l] = r;
		} else {
			pre[nxt[l]] = pre[l];
			nxt[pre[l]] = nxt[l];
		}
	}
	int pos = 0;
	while(pos != -1) {
		if(pos != 0) {
			std :: cout << pos << ' ';
		}
		pos = nxt[pos];
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