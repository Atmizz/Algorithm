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
const int N = 50;
void solve() {
	int n;
	std :: string str;
	std :: cin >> n >> str;
	int cnt1, cnt2, f1 = 0, f2 = 0;
	for(int i = 1; i <= n; ++ i) // X
		for(int j = 1; j <= n; ++ j) { // Y
			int cnt1 = 0, cnt2 = 0;
			int res1 = 0, res2 = 0, last = 0;
			for(int k = 0; k < n; ++ k) {
				if(str[k] == 'A') res1 ++;
				else res2 ++;
				if(res1 == j) {
					cnt1 ++; last = 1;
					res1 = res2 = 0;
				}
				if(res2 == j) {
					res1 = res2 = 0;
					cnt2 ++; last = 2;
				}
			}
			if(res1 != 0 || res2 != 0) continue;
			if(cnt1 > cnt2 && cnt1 == i && last == 1) f1 ++;
			else if(cnt1 < cnt2 && cnt2 == i && last == 2) f2 ++;
		}
	if(f1 > 0 && f2 == 0) std :: cout << "A\n";
	else if(f1 == 0 && f2 > 0) std :: cout << "B\n";
	else std :: cout << "?\n";
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