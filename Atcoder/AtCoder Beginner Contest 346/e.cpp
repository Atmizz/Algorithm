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
int n, m, q;
int t[N], a[N], x[N];
int col[N], raw[N];
void solve() {
	std :: cin >> n >> m >> q;
	for(int i = 1; i <= q; ++ i) {
		std :: cin >> t[i] >> a[i] >> x[i];
	}
	for(int i = 1; i <= n; ++ i) {
		raw[i] = -1;
	}
	for(int i = 1; i <= m; ++ i) {
		col[i] = -1;
	}
	int cntc = 0, cntr = 0;
	std :: set <int> st;
	std :: map <int, i64> mp;
	for(int i = q; i >= 1; -- i) {
		if(t[i] == 1) {
			if(raw[a[i]] != -1 || m - cntc == 0) {
				continue;
			}
			raw[a[i]] = x[i];
			st.insert(x[i]);
			mp[x[i]] += m - cntc;
			cntr ++;
		} else {
			if(col[a[i]] != -1 || n - cntr == 0) {
				continue;
			}
			st.insert(x[i]);
			col[a[i]] = x[i];
			mp[x[i]] += n - cntr;
			cntc ++;
		}
	}
	i64 sum = 0;
	for(auto s : st) {
		if(s <= 0) {
			continue;
		}
		sum += mp[s];
	}
	mp[0] = 1LL * n * m - sum;
	if(mp[0] != 0) {
		st.insert(0);
	}
	std :: cout << st.size() << '\n';
	for(auto s : st) {
		std :: cout << s << ' ' << mp[s] << '\n';
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