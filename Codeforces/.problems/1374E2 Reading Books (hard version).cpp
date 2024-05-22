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
const int N = 2e5 + 20;
struct Node {
	i64 t, a, b, mk;
	friend bool operator < (Node a, Node b) {
		return a.t < b.t;
	}
}A[N], B[N], C[N];
void solve() {
	int n, m, k, cnta = 0, cntb = 0, cntc = 0; i64 ans = 0;
	std :: cin >> n >> m >> k;
	std :: set <int> s;
	std :: vector <pi> v; 
	std :: map <int, int> mp;
	for(int i = 1; i <= n; ++ i) {
		int t, x, y;
		std :: cin >> t >> x >> y;
		v.push_back({t, i});
		if(x == 0 && y == 0) continue;
		if(x == 1 && y == 0) A[++cnta] = {t, i, i, 0};
		if(x == 0 && y == 1) B[++cntb] = {t, i, i, 0};
		if(x == 1 && y == 1) C[++cntc] = {t, i, i, 1};
	}
	std :: sort(A + 1, A + 1 + cnta);
	std :: sort(B + 1, B + 1 + cntb);
	std :: sort(v.begin(), v.end());
	for(int i = 1; i <= std :: min(cnta, cntb); ++ i)
		C[++cntc] = {A[i].t + B[i].t, A[i].a, B[i].b, 0};
	std :: sort(C + 1, C + 1 + cntc);
	if(cntc < k || cntc < m || m < k) {
		std :: cout << -1;
		return ;
	}
	int cnt = 0, ch = 0, ca = 0, cb = 0;
	for(int i = 1; i <= cntc; ++ i) {
		if(C[i].mk == 0) {
			if(cnt + m + 1 > k) continue;
			cnt ++;
		} ch ++; ca ++, cb ++;
		ans += C[i].t, s.insert(C[i].a), s.insert(C[i].b);
		mp[C[i].a] = 1; mp[C[i].b] = 1;
		if(ch + cnt == m) break;
	} k += cnt;
	if(ca < k || cb < k) {
		std :: cout << -1;
		return ;
	}
	for(int i = 0; i < n; ++ i) {
		if(k >= m) break;
		if(mp[v[i].second]) continue;
		ans += v[i].first; k ++;
		mp[v[i].second] = 1;
		s.insert(v[i].second);
	}
	std :: cout << ans << endl;
	for(auto x : s)
		std :: cout << x << ' ';
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