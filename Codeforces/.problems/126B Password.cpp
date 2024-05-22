#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

void solve() {
	std :: string str;
	std :: cin >> str;
	int n = str.length(), px = 131;
	std :: vector <ull> p(n+1), h(n+1);
	p[0] = 1;
	for(int i = 0; i < n; ++ i) {
		h[i+1] = h[i] * px + str[i];
		p[i+1] = p[i] * px;
	}
	auto get_hash = [&] (int l, int r) -> int {
		return h[r] - h[l-1] * p[r-l+1];
	};

	std :: vector <int> lst;
	for(int i = 1; i < n; ++ i)
		if(get_hash(1, i) == get_hash(n-i+1, n))
			lst.push_back(i);
	int l = 0, r = lst.size() - 1, ans = -1;
	// for(auto x : lst)
	// 	deb(x);
	// deb(L);
	while(l <= r) {
		int mid = (l + r + 1) >> 1, cnt = 0;
		for(int i = 2; i < n - lst[mid] + 1; ++ i)
			if(get_hash(1, lst[mid]) == get_hash(i, i + lst[mid] - 1)) cnt ++;
		// deb(cnt);
		if(cnt > 0) l = mid + 1, ans = mid;
		else r = mid - 1;

	}
	// if(ans == lst.size()) ans = *lst.rbegin();
	// deb(ans);
	if(ans >= 0)
		for(int i = 0; i < lst[ans]; ++ i)
			std :: cout << str[i];
	else std :: cout << "Just a legend";
	puts("");
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