#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

i64 ans;

void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> a(n+1), b(n+1);
	for(int i = 1; i <= n; ++ i) std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i) std :: cin >> b[i], ans += std :: abs(a[i] - b[i]);

	std :: vector < std :: pair<int, int> > s, t;
	for(int i = 1; i <= n; ++ i)
		if(a[i] < b[i]) s.push_back({a[i], b[i]});
		else if(a[i] > b[i]) t.push_back({b[i], a[i]});
	std :: sort(s.begin(), s.end());
	std :: sort(t.begin(), t.end());

	int N1 = s.size(), N2 = t.size(), mx = 0;
	
	std :: vector <int> mxs(N1+1, -1E9), mxt(N2+1, -1E9);

	for(int i = 0; i < N1; ++ i)
		mxs[i+1] = std :: max(mxs[i], s[i].second);
	for(int i = 0; i < N2; ++ i)
		mxt[i+1] = std :: max(mxt[i], t[i].second);
	
	for(int i = 0; i < N1; ++ i) {
		int j = std :: upper_bound(t.begin(), t.end(), s[i]) - t.begin();
		j = std :: min(j, N2);
		mx = std :: max(mx, std :: min(mxt[j], s[i].second) - s[i].first);
		// deb(j); deb(s[i].first); deb(s[i].second); deb(t[j].first); deb(t[j].second); deb(mxt[j]); deb(mx);
	}
	for(int i = 0; i < N2; ++ i) {
		int j = std :: upper_bound(s.begin(), s.end(), t[i]) - s.begin();
		j = std :: min(j, N1);
		mx = std :: max(mx, std :: min(mxs[j], t[i].second) - t[i].first);
		// deb(j); deb(t[i].first); deb(t[i].second); deb(mxs[j]); deb(mx);
	}
	
	std :: cout << ans - 2ll * mx;
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T;
	while(T --) solve();
	return 0;
}