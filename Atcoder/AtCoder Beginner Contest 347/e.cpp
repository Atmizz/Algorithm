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
// const int N = ;
void solve() {
	int n, q;
	std :: cin >> n >> q;
	std :: vector <int> a(q), pos[q+1];
	std :: vector <i64> sum(q+1), ans(n+1);
	for(int &x : a) {
		std :: cin >> x;
	}
	std :: set <int> s;
	for(int i = 0; i < q; ++ i) {
		pos[a[i]].push_back(i+1);
		if(s.count(a[i])) {
			s.erase(a[i]);
		} else {
			s.insert(a[i]);
		}
		sum[i+1] = (int) s.size();
	}
	for(int i = 1; i <= q; ++ i) {
		sum[i] += sum[i-1];
		// deb(sum[i]);
	}
	for(int i = 1; i <= n; ++ i) {
		// deb(i);
		// deb(pos[i].size());
		for(int j = 0; j < (int) pos[i].size(); ++ j) {
			if(j & 1) {
				ans[i] += sum[pos[i][j]-1] - sum[pos[i][j-1]-1];
			}
		}
		// deb(ans[i]);
		if((int) pos[i].size() & 1) {
			// deb((*(pos[i].rbegin()))-1)
			ans[i] += sum[q] - sum[(*(pos[i].rbegin()))-1];
		}
	}
	for(int i = 1; i <= n; ++ i) {
		std :: cout << ans[i] << ' ';
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