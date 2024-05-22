#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

void solve() {
	std :: string s, t, z;
	std :: cin >> s >> t;
	std :: map <char, bool> m;
	std :: vector <int> pos[26];
	int ls = s.length(), lt = t.length();
	for(int i = 0; i < ls; ++ i)
		m[s[i]] = 1;
	for(int i = 0; i < lt; ++ i)
		if(m[t[i]] == 0) {
			std :: cout << -1 << endl;
			return ;
		}
	for(int i = 0; i < ls; ++ i)
		pos[(int)s[i]-'a'].push_back(i);
	int ans = 0;
	for(int i = 0; i < lt; ++ i) {
		int ch = t[i] - 'a';
		int n = pos[ch][0]; ans ++;
		for(int j = i + 1; j < lt; ++ j) {
			int chh = t[j] - 'a';
			int nn = std :: lower_bound(pos[chh].begin(), pos[chh].end(), n+1) - pos[chh].begin();
			if(nn == pos[chh].size() || pos[chh][nn] <= n) break;
			i = j; n = pos[chh][nn];
		}
	}
	std :: cout << ans << endl;
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