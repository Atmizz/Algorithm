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
	int n;
	std :: cin >> n;
	std :: string s, t;
	std :: cin >> s >> t;
	int pos = n - 1;
	std :: vector <int> ans;
	for(; pos >= 0; -- pos) {
		if(s[pos] == t[pos]) continue;
		ans.push_back(pos+1);
		if(pos != 0) {
			ans.push_back(1);
			ans.push_back(pos+1);
		}
	}
	std :: cout << ans.size() << ' ';
	if(ans.size() == 0) {
		std :: cout << endl;
		return ;
	}
	for(int i = 0; i < ans.size(); ++ i)
		std :: cout << ans[i] << " \n"[i == ans.size() - 1];
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