#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
	int k;
	std :: cin >> k;
	std :: string s;
	char a, b;
	std :: cin >> s >> a >> b;
	std :: vector <int> pos[2];
	for(int i = 0; i < (int) s.size(); ++ i) {
		if(s[i] == a) {
			pos[0].push_back(i);
		} else if(s[i] == b) {
			pos[1].push_back(i);
		}
	}
	i64 ans = 0;
	pos[1].push_back(INF);
	for(auto l : pos[0]) {
		int p = std :: lower_bound(pos[1].begin(), pos[1].end(), l + k - 1) - pos[1].begin();
		if(pos[1][p] == INF) {
			continue ;
		}
		ans += pos[1].size() - p - 1;
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