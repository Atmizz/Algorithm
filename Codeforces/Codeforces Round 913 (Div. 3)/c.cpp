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
	int n, sum = 0, maxx = 0;
	std :: string str;
	std :: cin >> n >> str;
	std :: map <char, int> cnt;
	for(auto c : str)
		cnt[c] ++;
	for(auto [x, y] : cnt) {
		if(maxx < y) maxx = y;
		sum += y;
	}
	if(maxx == 1) {
		if(cnt.size() & 1)
			std :: cout << 1 << '\n';
		else std :: cout << 0 << '\n';
		return ;
	}
	if(maxx > sum - maxx)
		std :: cout << maxx * 2 - sum << '\n';
	else {
		if((sum - maxx * 2) & 1)
			std :: cout << 1 << '\n';
		else std :: cout << 0 << '\n';
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