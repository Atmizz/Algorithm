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
bool cmp(const pi &a, const pi &b) {
	return a.first == b.first ? a.second > b.second : a.first < b.first;
}
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <pi> v(9);
	for(int i = 0; i < 9; ++ i)
		std :: cin >> v[i].first, v[i].second = i + 1;
	std :: sort(v.begin(), v.end(), cmp);
	std :: vector <int> ans;
	std :: vector <pi> sum(9);
	sum[0] = v[0];
	for(int i = 1; i < 9; ++ i)
		if(v[i].second > sum[i-1].second) sum[i] = v[i];
		else sum[i] = sum[i-1];
	int temp = n / v[0].first;
	for(int i = 1; i <= temp; ++ i)
		ans.push_back(v[0].second), n -= v[0].first;
	for(int i = 0; i < ans.size(); ++ i) {
		if(n + v[0].first < v[1].first) break;
		// deb(n + v[0].first);
		auto p = std :: make_pair(n + v[0].first + 1, -1);
		int pos = std :: lower_bound(v.begin(), v.end(), p) - v.begin() - 1;
		// deb(pos);
		ans[i] = sum[pos].second; n -= sum[pos].first; n += v[0].first;
	}
	if(ans.size())
		for(auto x : ans)
			std :: cout << x;
	else std :: cout << -1;
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