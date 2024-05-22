#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e6 + 20;
int k;
std :: string s;
void solve() {
	std :: cin >> k >> s;
	int n = s.length();
	std :: vector <int> v;
	v.push_back(0);
	for(int i = 0; i < n; ++ i)
		if(s[i] == '1')
			v.push_back(i + 1);
	v.push_back(n + 1);
	int m = v.size() - 2;
	i64 ans = 0;
	if(k > 0) {
		for(int i = 1; i <= m; ++ i)
			if(i + k - 1 <= m)
				ans += (i64)(v[i] - v[i-1]) * (v[i+k] - v[i+k-1]);
	} else {
		for(int i = 1; i <= m + 1; ++ i)
			if(v[i] > v[i-1] + 1)
				ans += i64(v[i] - v[i-1]) * (v[i] - v[i-1] - 1) / 2;
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