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

void solve() {
	int k; std :: cin >> k;
	std :: vector <pi> a;
	std :: vector <int> num1(k), num2(k);
	int Begin = 0, End = -1;
	for(int i = 0; i < k; ++ i) {
		int x; std :: cin >> num1[i]; num2[i] = num1[i]; End += num1[i];
		for(int j = 1; j <= num1[i]; ++ j)
			std :: cin >> x, a.push_back({x, i});
	}
	std :: sort(a.begin(), a.end());
	// for(auto x : a)
	// 	std :: cout << x.first << ' ' << x.second << endl;
	while(num1[a[Begin].second] > 1) num1[a[Begin].second] --, Begin ++;
	while(num2[a[End].second] > 1) num2[a[End].second] --, End --;
	// deb(a[End].first); deb(a[Begin].first);
	 deb(End); deb(Begin);
	if(End >= Begin) std :: cout << a[End].first -  a[Begin].first << endl;
	else {

	}
}

int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}